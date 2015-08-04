
#include "Pose3DMotorsInterface.h"

Pose3DMotorsInterface::Pose3DMotorsInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{


    pose3DMotorsData = new jderobot::Pose3DMotorsData();
    pose3DMotorsParamsData = new jderobot::Pose3DMotorsParams();


    pose3DMotorsParamsData->maxPan = 0;
    pose3DMotorsParamsData->minPan = 0;
    pose3DMotorsParamsData->maxTilt = 0;
    pose3DMotorsParamsData->minTilt = 0;
    pose3DMotorsParamsData->maxPanSpeed = 0;
    pose3DMotorsParamsData->maxTiltSpeed = 0;

    pose3DMotorsData->x = 0;
    pose3DMotorsData->y = 0;
    pose3DMotorsData->z = 0;

    pose3DMotorsData->roll = 0;
    pose3DMotorsData->panSpeed = 0;
    pose3DMotorsData->tiltSpeed = 0;

    flag = true;


}

Pose3DMotorsInterface::~Pose3DMotorsInterface()
{


}


jderobot::Pose3DMotorsDataPtr Pose3DMotorsInterface::getPose3DMotorsData(const Ice::Current&)
{
    if(flag == false)
    {
        std::cout<< "Reached End for Pose3DMotors\n";
        return pose3DMotorsData;
    }

    //std::cout<< "Reached End for Pose3DMotors\n";

    RosIceMessage::Pose3DMotorsData::ConstPtr pose3DMotorsMsg = getIterator()->instantiate<RosIceMessage::Pose3DMotorsData>();

    pose3DMotorsData->pan = pose3DMotorsMsg->pan;
    pose3DMotorsData->tilt = pose3DMotorsMsg->tilt;

    flag = increment();


    return pose3DMotorsData;
}

jderobot::Pose3DMotorsParamsPtr Pose3DMotorsInterface::getPose3DMotorsParams(const Ice::Current &)
{
    return pose3DMotorsParamsData;
}

Ice::Int Pose3DMotorsInterface::setPose3DMotorsData(const jderobot::Pose3DMotorsDataPtr & data, const Ice::Current&)
{

    return 0;
}


