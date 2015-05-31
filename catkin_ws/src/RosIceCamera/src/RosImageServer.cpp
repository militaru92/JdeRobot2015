
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

        ROS_INFO("Before compressing- RosServer\n");

        unsigned long source_len = image.rows*image.cols*3;
        unsigned long compress_len = compressBound(source_len);
        unsigned char* compress_buf = (unsigned char *) malloc(compress_len);

        int r = compress((Bytef *) compress_buf, (uLongf *) &compress_len, (const Bytef *) &(image.data[0]), (uLong)source_len );


        if(r != Z_OK)
        {
            ROS_ERROR("Error compressing\n");
            return;
        }
        else
        {
            IceImage.data.resize(source_len);
            memcpy(&(IceImage.data[0]),  &(compress_buf[0]), compress_len);
            ROS_INFO("After memcpy RosServer\n");
        }

        ROS_INFO("After compressing- RosServer\n");

        if(compress_buf)
        {
            free(compress_buf);
        }

        this->Proxy->publishImage(IceImage);



    }


}
