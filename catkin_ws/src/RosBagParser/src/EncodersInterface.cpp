
#include "EncodersInterface.h"

EncodersInterface::EncodersInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{

    encodersData = new jderobot::EncodersData();
}

EncodersInterface::~EncodersInterface()
{


}

jderobot::EncodersDataPtr EncodersInterface::getEncodersData(const Ice::Current &)
{



    if(atEnd())
    {
        std::cout<< "Reached End for Encoders " << index << std::endl;
        return encodersData;
    }



    RosIceMessage::EncodersData::ConstPtr encodersMsg = getIterator()->instantiate<RosIceMessage::EncodersData>();

    encodersData->robotx = encodersMsg->robotx;
    encodersData->roboty = encodersMsg->roboty;
    encodersData->robottheta = encodersMsg->robottheta;
    encodersData->robotcos = cos(encodersMsg->robottheta);
    encodersData->robotsin = sin(encodersMsg->robottheta);

    increment();


    return encodersData;
}

void EncodersInterface::setEncodersData(const jderobot::EncodersDataPtr &encodersData, const Ice::Current &)
{
    //std::cout <<"Set encoders" << std::endl;
}

