
#include "LaserInterface.h"


LaserInterface::LaserInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{

    laserData = new jderobot::LaserData();

}

LaserInterface::~LaserInterface()
{

}

jderobot::LaserDataPtr LaserInterface::getLaserData(const Ice::Current&)
{

    if(atEnd())
    {
        std::cout<< "Reached End for Laser\n";
        return laserData;
    }

    RosIceMessage::Laser::ConstPtr laserMsg = getIterator()->instantiate<RosIceMessage::Laser>();

    laserData->numLaser = laserMsg->numLaser;
    laserData->distanceData.resize(sizeof(int) * laserData->numLaser);


    for(int i = 0 ; i < laserData->numLaser; ++i)
    {
       laserData->distanceData[i] = laserMsg->distanceData[i];
    }

    increment();

    return laserData;
}

