#ifndef ARDRONEEXTRACLIENT_H
#define ARDRONEEXTRACLIENT_H

#include "Ros_Ice.h"
#include <jderobot/ardroneextra.h>
#include <std_msgs/Bool.h>

class ArDroneExtraClient : public Ros_Ice < jderobot::ArDroneExtraPrx >
{

public:

    /**
     * @brief This constructor initializes the ROS topic using the nodeName parameter
     */

    ArDroneExtraClient(int argc, char **argv, std::string nodeName);

    ~ArDroneExtraClient();

    /**
     * @brief This callback method receives data from TeleOperator class and sends it to the JdeRobot Gazebo simulator using the inherited Ice Proxy
     */

    void rosCallback(std_msgs::Bool value);




};

#endif // ARDRONEEXTRACLIENT_H
