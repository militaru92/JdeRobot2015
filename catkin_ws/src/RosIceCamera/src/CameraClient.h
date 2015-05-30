#ifndef CAMERACLIENT_H
#define CAMERACLIENT_H

#include "Ros_Ice.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


class CameraClient : public Ros_Ice< Ice::ObjectPrx >
{

public:

    CameraClient(int argc, char **argv, std::string nodeName);
    ~CameraClient();

    void rosCallback(const sensor_msgs::ImageConstPtr& image_message);

};

#endif // CAMERACLIENT_H
