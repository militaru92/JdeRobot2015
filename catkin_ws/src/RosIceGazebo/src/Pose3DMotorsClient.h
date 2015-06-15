#ifndef POSE3DMOTORSCLIENT_H
#define POSE3DMOTORSCLIENT_H

#include "Ros_Ice.h"
#include <jderobot/pose3dmotors.h>
#include <RosIceGazebo/Pose3DMotorsData.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class Pose3DMotorsClient : public Ros_Ice < jderobot::Pose3DMotorsPrx >
{

public:

    Pose3DMotorsClient(int argc, char **argv, std::string nodeName);
    ~Pose3DMotorsClient();


    void rosCallback(RosIceGazebo::Pose3DMotorsData pose3DMotorData);




};

#endif // POSE3DMOTORSCLIENT_H
