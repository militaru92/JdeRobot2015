
#include "RosImageServer.h"

RosImageServer::RosImageServer(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    runROSSpinner();

    initializeIce(argc,argv);

    addRosImagePublisher("test",1000);
    addRosImageSubscriber<RosImageServer>("test",1000,&RosImageServer::rosCallback,this);

    addIceProxy("SimpleImage:default -p 10000");


}

void RosImageServer::rosCallback(const sensor_msgs::ImageConstPtr &image_message)
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

    if(image.cols > 0 && image.rows > 0)
    {
        Message::ImageData IceImage;

        IceImage.rows = image.rows;
        IceImage.cols = image.cols;
        IceImage.type = image.type();

        IceImage.data.resize(image.rows * image.cols * 3);
        memcpy(&(IceImage.data[0]),  (unsigned char *) image.data, image.rows * image.cols * 3);


        this->Proxy->publishImage(IceImage);



    }


}
