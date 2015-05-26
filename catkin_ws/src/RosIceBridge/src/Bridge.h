#ifndef BRIDGE_H
#define BRIDGE_H

#include "Ros_Ice.h"
#include "RosIceBridge/Num.h"
#include <Num.h>
template<class IcePrx>

class Bridge : public Ros_Ice<IcePrx>
{
public:

    Bridge(int argc, char **argv, std::string nodeName) : Ros_Ice<IcePrx>(argc,argv,nodeName)
    {

    }



    void rosCallback(RosIceBridge::Num RosMessage)
    {
        Message::Num IceMessage;
        IceMessage.value = RosMessage.num;
        icePublish(IceMessage);

    }

    void icePublish(Message::Num message)
    {
        this->Proxy->publish2(message);
    }



};

#endif // BRIDGE_H
