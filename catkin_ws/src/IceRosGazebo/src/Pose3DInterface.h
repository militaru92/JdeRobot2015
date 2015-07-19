#ifndef POSE3DINTERFACE_H
#define POSE3DINTERFACE_H


#include <jderobot/pose3d.h>
#include <IceRosGazebo/Pose3D.h>
#include "Ros_Ice.h"

#include <fstream>

class Pose3DInterface : virtual public jderobot::Pose3D, public Ros_Ice< Ice::ObjectPrx >
{

public:
    Pose3DInterface(int argc, char **argv, std::string nodeName);

    virtual ~Pose3DInterface();

    virtual int setPose3DData(const jderobot::Pose3DDataPtr&  Pose3DData, const Ice::Current&);

    virtual jderobot::Pose3DDataPtr getPose3DData(const Ice::Current&);

    void rosCallback(IceRosGazebo::Pose3D pose3DMsg);

private:

    //IceRosGazebo::EncodersData encodersMsg;
    jderobot::Pose3DDataPtr pose3DData;

    std::ofstream myfile;


};


#endif // POSE3DINTERFACE_H
