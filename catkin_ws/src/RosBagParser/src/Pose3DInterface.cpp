
#include "Pose3DInterface.h"

Pose3DInterface::Pose3DInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{

    pose3DData = new jderobot::Pose3DData();

    flag = true;

}

Pose3DInterface::~Pose3DInterface()
{


}


jderobot::Pose3DDataPtr Pose3DInterface::getPose3DData(const Ice::Current&)
{


    if(flag == false)
    {
        std::cout<< "Reached End for Pose3D\n";
        return pose3DData;
    }


    RosIceMessage::Pose3D::ConstPtr pose3DMsg = getIterator()->instantiate<RosIceMessage::Pose3D>();


    pose3DData->x = pose3DMsg->x * 1000;
    pose3DData->y = pose3DMsg->y * 1000;
    pose3DData->z = 0.0;
    pose3DData->h = 1.0;

    pose3DData->q0 = pose3DMsg->q0;
    pose3DData->q1 = pose3DMsg->q1;
    pose3DData->q2 = pose3DMsg->q2;
    pose3DData->q3 = pose3DMsg->q3;

    //std::cout<< pose3DData->x << " "<< pose3DData->y << " " << pose3DData->z << " " << pose3DData->h << " "<< pose3DData->q0 << " "<< pose3DData->q1 << " " << pose3DData->q2 << " " << pose3DData->q3 << std::endl;

    flag = increment();

    return pose3DData;
}

int Pose3DInterface::setPose3DData(const jderobot::Pose3DDataPtr&  Pose3DData, const Ice::Current&)
{
    std::cout <<"Not implemented yet\n";
    return 0;
}

