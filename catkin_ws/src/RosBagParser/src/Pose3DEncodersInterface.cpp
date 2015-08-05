
#include "Pose3DEncodersInterface.h"

Pose3DEncodersInterface::Pose3DEncodersInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{

    pose3DEncodersData = new jderobot::Pose3DEncodersData();

    pose3DEncodersData->x = 0;
    pose3DEncodersData->y = 0;
    pose3DEncodersData->z = 0;
    pose3DEncodersData->clock = 0;
    pose3DEncodersData->roll = 0;



}

Pose3DEncodersInterface::~Pose3DEncodersInterface()
{


}


jderobot::Pose3DEncodersDataPtr Pose3DEncodersInterface::getPose3DEncodersData(const Ice::Current&)
{
    if(atEnd())
    {
        std::cout<< "Reached End for Pose3DEncoders\n";
        return pose3DEncodersData;
    }


    RosIceMessage::Pose3DEncodersData::ConstPtr pose3DEncodersMsg = getIterator()->instantiate<RosIceMessage::Pose3DEncodersData>();

    pose3DEncodersData->pan = pose3DEncodersMsg->pan;
    pose3DEncodersData->tilt = pose3DEncodersMsg->tilt;

    increment();


    return pose3DEncodersData;
}

