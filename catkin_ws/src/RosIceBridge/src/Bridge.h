#ifndef BRIDGE_H
#define BRIDGE_H

#include "Ros_Ice.h"
#include "RosIceBridge/Num.h"
#include <Num.h>


/**
 * @brief Method for adding a Subscriber with a simple function as callback
 */

template<class IcePrx>
class Bridge : public Ros_Ice<IcePrx>
{
public:

    Bridge(int argc, char **argv, std::string nodeName) : Ros_Ice<IcePrx>(argc,argv,nodeName)
    {

    }


    /**
     * @brief Callback Method that will forward the ROS message to the Ice framework
     */

    void rosCallback(RosIceBridge::Num RosMessage)
    {
        Message::Num IceMessage;
        IceMessage.value = RosMessage.num;
        icePublish(IceMessage);

    }


    /**
     * @brief Method for sending a request from an Ice Client
     */

    void icePublish(Message::Num message)
    {
        this->Proxy->publish2(message);
    }



};

#endif // BRIDGE_H
