#include "IceRosBridge.h"

void IceRosBridge::publish2(const Message::Num & IceMessage, const Ice::Current &)
{
    RosIceBridge::Num RosMessage;
    RosMessage.num = IceMessage.value;
    this->rosPublish<RosIceBridge::Num>(RosMessage);
}

void IceRosBridge::rosCallback(RosIceBridge::Num RosMessage)
{
    ROS_INFO("I heard %ld\n",RosMessage.num);

}
