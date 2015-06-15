#ifndef LASERCLIENT_H
#define LASERCLIENT_H

#include "Ros_Ice.h"
#include <jderobot/motors.h>
#include <RosIceGazebo/MotorData.h>
#include <visionlib/colorspaces/colorspacesmm.h>


class MotorClient : public Ros_Ice < jderobot::MotorsPrx >
{

public:

    MotorClient(int argc, char **argv, std::string nodeName);
    ~MotorClient();


    void rosCallback(RosIceGazebo::MotorData motorData);




};

#endif // LASERCLIENT_H
