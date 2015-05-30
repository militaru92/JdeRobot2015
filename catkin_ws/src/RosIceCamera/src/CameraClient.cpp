#include "CameraClient.h"

CameraClient::CameraClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    runROSSpinner();
    addRosImagePublisher("test",1000);
    addRosImageSubscriber<CameraClient>("test",1000,&CameraClient::rosCallback,this);


    cv::namedWindow("Image window");
}

CameraClient::~CameraClient()
{
    cv::destroyWindow("Image window");
}

void CameraClient::rosCallback(const sensor_msgs::ImageConstPtr& image_message)
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

        cv::imshow("Image window", image);
        cv::waitKey(3);

    }


}

