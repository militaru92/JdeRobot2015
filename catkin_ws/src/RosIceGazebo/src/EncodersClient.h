#ifndef ENCODERSCLIENT_H
#define ENCODERSCLIENT_H

#include "Ros_Ice.h"
#include <RosIceMessage/EncodersData.h>
#include <encoders.h>


class EncodersClient : public Ros_Ice < jderobot::EncodersPrx >
{

public:

    EncodersClient(int argc, char **argv, std::string nodeName);
    ~EncodersClient();

    RosIceMessage::EncodersData publishROS();

    void rosCallback(RosIceMessage::EncodersData encodersMessage);






};

#endif // ENCODERSCLIENT_H
