#ifndef POSE3DENCODERSINTERFACE_H
#define POSE3DENCODERSINTERFACE_H


#include <jderobot/pose3dencoders.h>
#include <RosIceMessage/Pose3DEncodersData.h>
#include "RosBagParser.h"


class Pose3DEncodersInterface : virtual public jderobot::Pose3DEncoders, public RosBagParser
{

public:
    Pose3DEncodersInterface(std::string fileName, std::string topicName);

    virtual ~Pose3DEncodersInterface();

    jderobot::Pose3DEncodersDataPtr getPose3DEncodersData(const Ice::Current&);


private:

    jderobot::Pose3DEncodersDataPtr pose3DEncodersData;



};


#endif // POSE3DENCODERSINTERFACE_H
