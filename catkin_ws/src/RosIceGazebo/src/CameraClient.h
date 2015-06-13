#ifndef CAMERACLIENT_H
#define CAMERACLIENT_H

#include "Ros_Ice.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <camera.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class CameraClient : public Ros_Ice < jderobot::CameraPrx >
{

public:

    CameraClient(int argc, char **argv, std::string nodeName);
    ~CameraClient();

    void publishROS();

    void rosCallback(const sensor_msgs::ImageConstPtr& image_message);

private:
    std::string ImageWindow;




};

#endif // CAMERACLIENT_H
