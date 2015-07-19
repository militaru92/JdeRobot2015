#ifndef ENCODERSINTERFACE_H
#define ENCODERSINTERFACE_H

#include <jderobot/encoders.h>
#include <IceRosGazebo/EncodersData.h>
#include "Ros_Ice.h"

#include <fstream>

class EncodersInterface : virtual public jderobot::Encoders, public Ros_Ice< Ice::ObjectPrx >
{

public:
    EncodersInterface(int argc, char **argv, std::string nodeName);

    virtual ~EncodersInterface();

    virtual void setEncodersData(const jderobot::EncodersDataPtr&  encodersData, const Ice::Current&);

    virtual jderobot::EncodersDataPtr getEncodersData(const Ice::Current&);
    void rosCallback(IceRosGazebo::EncodersData encodersMsg);

private:

    //IceRosGazebo::EncodersData encodersMsg;
    jderobot::EncodersDataPtr encodersData;

    //std::ofstream myfile;


};

#endif // ENCODERSINTERFACE_H
