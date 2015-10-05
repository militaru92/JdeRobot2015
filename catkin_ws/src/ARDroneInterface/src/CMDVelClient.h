#ifndef CMDVELCLIENT_H
#define CMDVELCLIENT_H

#include "Ros_Ice.h"
#include <jderobot/cmdvel.h>
#include <ARDroneInterface/CMDVelData.h>

class CMDVelClient : public Ros_Ice < jderobot::CMDVelPrx >
{

public:

    /**
     * @brief This constructor initializes the ROS topic using the nodeName parameter
     */

    CMDVelClient(int argc, char **argv, std::string nodeName);

    ~CMDVelClient();

    /**
     * @brief This callback method receives data from TeleOperator class and sends it to the JdeRobot Gazebo simulator using the inherited Ice Proxy
     */

    void rosCallback(RosIceMessage::CMDVelData cmdVelData);

private:

    jderobot::CMDVelDataPtr cmdVel;




};


#endif // CMDVELCLIENT_H
