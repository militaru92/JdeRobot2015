#ifndef POSE3DENCODERSCLIENT_H
#define POSE3DENCODERSCLIENT_H

#include "Ros_Ice.h"
#include <jderobot/pose3dencoders.h>
#include <RosIceMessage/Pose3DEncodersData.h>


class Pose3DEncodersClient : public Ros_Ice < jderobot::Pose3DEncodersPrx >
{

public:

    Pose3DEncodersClient(int argc, char **argv, std::string nodeName);
    ~Pose3DEncodersClient();

    void publishROS();





};

#endif // POSE3DENCODERSCLIENT_H
