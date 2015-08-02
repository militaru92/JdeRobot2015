#ifndef MOTORCLIENT_H
#define MOTORCLIENT_H

#include "Ros_Ice.h"
#include <jderobot/motors.h>
#include <RosIceMessage/MotorData.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class MotorClient : public Ros_Ice < jderobot::MotorsPrx >
{

public:

    MotorClient(int argc, char **argv, std::string nodeName);
    ~MotorClient();


    void rosCallback(RosIceMessage::MotorData motorData);




};

#endif // MOTORCLIENT_H
