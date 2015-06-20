#ifndef ENCODERSCLIENT_H
#define ENCODERSCLIENT_H

#include "Ros_Ice.h"
#include <RosIceGazebo/EncodersData.h>
#include <encoders.h>


class EncodersClient : public Ros_Ice < jderobot::EncodersPrx >
{

public:

    EncodersClient(int argc, char **argv, std::string nodeName);
    ~EncodersClient();

    RosIceGazebo::EncodersData publishROS();

    void rosCallback(RosIceGazebo::EncodersData encodersMessage);






};

#endif // ENCODERSCLIENT_H
