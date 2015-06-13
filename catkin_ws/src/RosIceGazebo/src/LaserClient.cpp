#include "LaserClient.h"

LaserClient::LaserClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher <RosIceGazebo::Laser> (nodeName,1000);
    addRosSubscriber(nodeName,1000,&LaserClient::rosCallback,this);
    addRosImagePublisher(nodeName + "_image",1000);

    ImageWindow = nodeName;

    cv::namedWindow(ImageWindow);
}

LaserClient::~LaserClient()
{
    cv::destroyWindow(ImageWindow);
}

void LaserClient::publishROS()
{
    jderobot::LaserDataPtr laserData= this->Proxy->getLaserData();
    RosIceGazebo::Laser rosLaserData;

    rosLaserData.numLaser = laserData->numLaser;
    rosLaserData.distanceData = laserData->distanceData;

    rosPublish(rosLaserData);

}

void LaserClient::rosCallback(RosIceGazebo::Laser laserMessage)
{
    cv::Mat laserImage(180,360, CV_8UC3, cv::Scalar(0,0,0));

    cv::line(laserImage,cv::Point(180,165),cv::Point(180,180),cv::Scalar(255,0,0));
    double PI = 4.0 * atan(1);

    for (int i = laserMessage.numLaser - 1; i > 0; --i)
    {
        cv::line(laserImage, cv::Point(180 + ((laserMessage.distanceData[i] / 45)*(cos((i) * PI / 180))), 180 - ((laserMessage.distanceData[i] / 45)*(sin((i) * PI / 180)))), cv::Point(180 + ((laserMessage.distanceData[i + 1] / 45)*(cos((i + 1) * PI / 180))), 180 - ((laserMessage.distanceData[i + 1] / 45)*(sin((i + 1) * PI / 180)))),cv::Scalar(255,255,255));
    }

/*
    if(laserImage.cols > 0 && laserImage.rows > 0)
    {

        cv::imshow(ImageWindow, laserImage);
        cv::waitKey(3);

    }

*/
    sensor_msgs::ImagePtr image_message = cv_bridge::CvImage(std_msgs::Header(), "rgb8", laserImage).toImageMsg();
    rosImagePublish(image_message);


}

