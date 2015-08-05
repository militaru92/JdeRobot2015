#ifndef POSE3DCLIENT_H
#define POSE3DCLIENT_H

#include "Ros_Ice.h"
#include <pose3d.h>
#include <geometry_msgs/Pose.h>
#include <RosIceMessage/Pose3D.h>


class Pose3DClient : public Ros_Ice < jderobot::Pose3DPrx >
{

public:

    Pose3DClient(int argc, char **argv, std::string nodeName);
    ~Pose3DClient();

    geometry_msgs::Pose publishROS();

    void rosCallback(geometry_msgs::Pose Pose3DMessage);






};

#endif // POSE3DCLIENT_H
