#ifndef ENCODERSINTERFACE_H
#define ENCODERSINTERFACE_H

#include <jderobot/encoders.h>
#include <RosIceMessage/EncodersData.h>
#include "RosBagParser.h"

class EncodersInterface : virtual public jderobot::Encoders, public RosBagParser
{

public:
    EncodersInterface(std::string fileName, std::string topicName);

    virtual ~EncodersInterface();

    virtual void setEncodersData(const jderobot::EncodersDataPtr&  encodersData, const Ice::Current&);

    virtual jderobot::EncodersDataPtr getEncodersData(const Ice::Current&);

private:


    jderobot::EncodersDataPtr encodersData;
    bool flag;



};

#endif // ENCODERSINTERFACE_H
