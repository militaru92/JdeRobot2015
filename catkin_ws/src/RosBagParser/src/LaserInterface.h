

#ifndef LASERINTERFACE_H
#define LASERINTERFACE_H

#include <jderobot/laser.h>
#include <RosIceMessage/Laser.h>
#include "RosBagParser.h"

#include <fstream>

class LaserInterface : virtual public jderobot::Laser, public RosBagParser
{

public:
    LaserInterface(std::string fileName, std::string topicName);

    virtual ~LaserInterface();

    virtual jderobot::LaserDataPtr getLaserData(const Ice::Current&);


private:

    jderobot::LaserDataPtr laserData;
    bool flag;






};

#endif // LASERINTERFACE_H

