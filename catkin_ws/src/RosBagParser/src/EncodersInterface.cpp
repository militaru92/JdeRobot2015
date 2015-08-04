
#include "EncodersInterface.h"

EncodersInterface::EncodersInterface(std::string fileName, std::string topicName) : RosBagParser(fileName,topicName)
{

    encodersData = new jderobot::EncodersData();
    flag = true;

}

EncodersInterface::~EncodersInterface()
{


}

jderobot::EncodersDataPtr EncodersInterface::getEncodersData(const Ice::Current &)
{



    if(flag == false)
    {
        std::cout<< "Reached End for Encoders\n";
        return encodersData;
    }



    RosIceMessage::EncodersData::ConstPtr encodersMsg = getIterator()->instantiate<RosIceMessage::EncodersData>();

    encodersData->robotx = encodersMsg->robotx * 1000;
    encodersData->roboty = encodersMsg->roboty * 1000;
    encodersData->robottheta = encodersMsg->robottheta;
    encodersData->robotcos = cos(encodersMsg->robottheta);
    encodersData->robotsin = sin(encodersMsg->robottheta);


    flag = increment();


    return encodersData;
}

void EncodersInterface::setEncodersData(const jderobot::EncodersDataPtr &encodersData, const Ice::Current &)
{
    //std::cout <<"Set encoders" << std::endl;
}

