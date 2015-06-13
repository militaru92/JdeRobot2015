#ifndef LASERCLIENT_H
#define LASERCLIENT_H

#include "Ros_Ice.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <laser.h>
#include <RosIceGazebo/Laser.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class LaserClient : public Ros_Ice < jderobot::LaserPrx >
{

public:

    LaserClient(int argc, char **argv, std::string nodeName);
    ~LaserClient();

    void publishROS();

    void rosCallback(RosIceGazebo::Laser laserMessage);

private:
    std::string ImageWindow;




};

#endif // LASERCLIENT_H
