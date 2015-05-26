#include "ros/ros.h"
#include "Ros_Ice.h"
#include <RosIceBridge/Num.h>
#include <Num.h>

Ros_Ice<Message::MonitorPrx> *bridge;


void callback(RosIceBridge::Num rosMessage)
{

    Message::Num m;

    m.value = rosMessage.num;

    bridge->icePublish(m);
}


int main(int argc, char **argv)
{

    bridge = new Ros_Ice<Message::MonitorPrx> (argc,argv,"publisher");

    bridge->addRosPublisher<RosIceBridge::Num>("test",1000);
    bridge->addRosSubscriber<RosIceBridge::Num>("test",1000,callback);
    bridge->addIceProxy("SimpleMonitor:default -p 10000");







    RosIceBridge::Num var;
    var.num = 0;

    while(var.num < 100)
    {
        var.num = var.num + 1;
        bridge->rosPublish<RosIceBridge::Num>(var);
    }

    delete bridge;



    return 0;
}
