#ifndef POSE3DMOTORSINTERFACE_H
#define POSE3DMOTORSINTERFACE_H


#include <jderobot/pose3dmotors.h>
#include <RosIceMessage/Pose3DMotorsData.h>
#include "RosBagParser.h"


class Pose3DMotorsInterface : virtual public jderobot::Pose3DMotors, public RosBagParser
{

public:
    Pose3DMotorsInterface(std::string fileName, std::string topicName);

    virtual ~Pose3DMotorsInterface();

    virtual jderobot::Pose3DMotorsDataPtr getPose3DMotorsData(const Ice::Current&);
    virtual jderobot::Pose3DMotorsParamsPtr getPose3DMotorsParams(const Ice::Current&);
    virtual Ice::Int setPose3DMotorsData(const jderobot::Pose3DMotorsDataPtr & data, const Ice::Current&);


private:

    jderobot::Pose3DMotorsDataPtr pose3DMotorsData;
    jderobot::Pose3DMotorsParamsPtr pose3DMotorsParamsData;

    bool flag;

};


#endif // POSE3DMOTORSINTERFACE_H
