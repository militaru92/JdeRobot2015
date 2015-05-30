#include <opencv2/opencv.hpp>

#include "RosImageServer.h"

int main(int argc, char** argv)
{

    cv::VideoCapture cap(0);

    RosImageServer p(argc,argv,"pub");

    while(ros::ok())
    {
        cv::Mat frame;
        cap >> frame;

        sensor_msgs::ImagePtr image_message = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

        p.rosImagePublish(image_message);

    }


    return 0;
}
