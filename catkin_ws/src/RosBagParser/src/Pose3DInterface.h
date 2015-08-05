#ifndef POSE3DINTERFACE_H
#define POSE3DINTERFACE_H


#include <jderobot/pose3d.h>
#include <RosIceMessage/Pose3D.h>
#include "RosBagParser.h"

class Pose3DInterface : virtual public jderobot::Pose3D, public RosBagParser
{

public:
    Pose3DInterface(std::string fileName, std::string topicName);

    virtual ~Pose3DInterface();

    virtual int setPose3DData(const jderobot::Pose3DDataPtr&  Pose3DData, const Ice::Current&);

    virtual jderobot::Pose3DDataPtr getPose3DData(const Ice::Current&);


private:

    jderobot::Pose3DDataPtr pose3DData;



};


#endif // POSE3DINTERFACE_H
