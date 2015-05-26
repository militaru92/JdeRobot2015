#ifndef ICEROSBRIDGE_H
#define ICEROSBRIDGE_H

#include "Ros_Ice.h"
#include <Num.h>
#include <RosIceBridge/Num.h>

/**
 * @brief This a typical class implemented by the user of the final library. Note that it inherits from the two classes so that it can act as the Interface for the Ice Server and
 * as a callback function for the ROS Subscriber
 */

class IceRosBridge : public Message::Monitor, public Ros_Ice<Message::MonitorPrx>
{

public:
    /**
     * @brief Method called in the Ice Serve
     */
    virtual void publish2(const Message::Num &, const Ice::Current&);


    /**
     * @brief Method used as callback for the ROS Subscriber
     */
    virtual void rosCallback(RosIceBridge::Num RosMessage);

};


#endif // ICEROSBRIDGE_H
