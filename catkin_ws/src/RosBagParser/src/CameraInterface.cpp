
#include "CameraInterface.h"

CameraInterface::CameraInterface(std::string fileName, std::string topicName): RosBagParser(fileName,topicName)
{

    imageDescription = (new jderobot::ImageDescription());
    cameraDescription = (new jderobot::CameraDescription());
    cameraDescription->name = "camera Introrob";

    replyTask = new ReplyTask(this);
    replyTask->start();



}

CameraInterface::~CameraInterface()
{

}

jderobot::ImageDescriptionPtr CameraInterface::getImageDescription(const Ice::Current& c)
{

    return imageDescription;

}

jderobot::CameraDescriptionPtr CameraInterface::getCameraDescription(const Ice::Current& c)
{
    return cameraDescription;
}

Ice::Int CameraInterface::setCameraDescription(const jderobot::CameraDescriptionPtr &description, const Ice::Current& c)
{
    return 0;
}
/*
jderobot::ImageDataPtr CameraInterface::getImageData( const std::string& format, const Ice::Current& c )
{
    return reply;
}
*/

void CameraInterface::getImageData_async (const jderobot::AMD_ImageProvider_getImageDataPtr& cb,const std::string& format, const Ice::Current& c)
{


    if(atEnd())
    {
        std::cout<< "Reached End for Camera\n";

    }


    else
    {

        cv_bridge::CvImagePtr cv_ptr;
        sensor_msgs::Image::ConstPtr image_message = getIterator()->instantiate<sensor_msgs::Image>();

        try
        {
            cv_ptr = cv_bridge::toCvCopy(image_message, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception& e)
        {
            std::cerr << "cv_bridge exception: " << e.what() << std::endl;
            return;
        }

        cv::Mat image = cv_ptr->image;

        image.copyTo(image_camera);


        increment();
    }

    replyTask->pushJob(cb, format);



}


jderobot::ImageFormat CameraInterface::getImageFormat(const Ice::Current &c)
{
    jderobot::ImageFormat mFormats;
    mFormats.push_back(colorspaces::ImageRGB8::FORMAT_RGB8.get()->name);

    return mFormats;
}

std::string CameraInterface::startCameraStreaming(const Ice::Current&)
{

}

void CameraInterface::stopCameraStreaming(const Ice::Current&)
{

}

void CameraInterface::reset(const Ice::Current&)
{

}
/*
void CameraInterface::rosCallback(const sensor_msgs::ImageConstPtr &image_message)
{
    cv_bridge::CvImagePtr cv_ptr;

    try
    {
        cv_ptr = cv_bridge::toCvCopy(image_message, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    cv::Mat image = cv_ptr->image;

    image.copyTo(image_camera);

}
*/
CameraInterface::ReplyTask::ReplyTask(CameraInterface *camera)
{
    mycamera = camera;
}

void CameraInterface::ReplyTask::pushJob(const jderobot::AMD_ImageProvider_getImageDataPtr& cb, std::string format)
{
    mFormat = format;
    IceUtil::Mutex::Lock sync(requestsMutex);
    requests.push_back(cb);
}

void CameraInterface::ReplyTask::run()
{

    jderobot::ImageDataPtr reply(new jderobot::ImageData);
    struct timeval a, b;
    int cycle = 48;
    long totalb,totala;
    long diff;

    int count = 0;

    while(1)
    {

        if(!mycamera->image_camera.data)
        {
            usleep(100);
            continue;
        }

        if(count==0)
        {
            //pthread_mutex_lock (&mycamera->cameraI->mutex);
            mycamera->imageDescription->width = mycamera->image_camera.cols;
            mycamera->imageDescription->height = mycamera->image_camera.rows;
            mycamera->imageDescription->size = mycamera->image_camera.cols * mycamera->image_camera.rows * 3;
            //pthread_mutex_unlock (&mycamera->cameraI->mutex);

            mycamera->imageDescription->format = "RGB8";

            reply->description = mycamera->imageDescription;
            count++;
        }

        //std::cout << nameGlobal<< std::endl;

        gettimeofday(&a,NULL);
        totala=a.tv_sec*1000000+a.tv_usec;


        IceUtil::Time t = IceUtil::Time::now();
        reply->timeStamp.seconds = (long)t.toSeconds();
        reply->timeStamp.useconds = (long)t.toMicroSeconds() - reply->timeStamp.seconds*1000000;

        reply->pixelData.resize(mycamera->image_camera.rows * mycamera->image_camera.cols * 3);

        memcpy( &(reply->pixelData[0]), (unsigned char *) mycamera->image_camera.data, mycamera->image_camera.rows * mycamera->image_camera.cols * 3);
        //pthread_mutex_unlock (&mycamera->cameraI->mutex);

        {
            IceUtil::Mutex::Lock sync(requestsMutex);
            while(!requests.empty())
            {
                jderobot::AMD_ImageProvider_getImageDataPtr cb = requests.front();
                requests.pop_front();
                cb->ice_response(reply);
            }
        }

        gettimeofday(&b,NULL);
        totalb=b.tv_sec*1000000+b.tv_usec;

        diff = (totalb-totala)/1000;
        diff = cycle-diff;

        //std::cout << "Gazeboserver takes " << diff << " ms " << mycamera->fileName << std::endl;

        if(diff < 33)
            diff = 33;


        /*Sleep Algorithm*/
        usleep(diff*1000);
    }

}
