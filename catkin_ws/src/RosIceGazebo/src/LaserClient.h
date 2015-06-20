#ifndef LASERCLIENT_H
#define LASERCLIENT_H

#include "Ros_Ice.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/PolygonStamped.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <laser.h>
#include <RosIceGazebo/Laser.h>
#include <RosIceGazebo/EncodersData.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class LaserClient : public Ros_Ice < jderobot::LaserPrx >
{

public:

    LaserClient(int argc, char **argv, std::string nodeName);
    ~LaserClient();

    void publishROS(RosIceGazebo::EncodersData encodersMessage);

    void rosCallback(RosIceGazebo::Laser laserMessage);

    void setRobotPos(RosIceGazebo::EncodersData encodersMessage);

private:
    std::string ImageWindow;
    float laser_coord[5];
    double PI;
    double DEGTORAD;

    ros::NodeHandle* Laser3DRosNode;

    ros::Publisher* Laser3DPublisher;
    //ros::Subscriber* Laser3DSubscriber;

    float robotx;
    float roboty;
    float robottheta;




};

#endif // LASERCLIENT_H
