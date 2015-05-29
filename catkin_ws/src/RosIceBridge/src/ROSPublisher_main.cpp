#include "ros/ros.h"
#include "Bridge.h"
#include <RosIceBridge/Num.h>
#include <Num.h>



int main(int argc, char **argv)
{

    Bridge<Message::MonitorPrx> *bridge;

    bridge = new Bridge<Message::MonitorPrx> (argc,argv,"publisher");
    bridge->runROSSpinner();

    bridge->addRosPublisher<RosIceBridge::Num>("test",1000);
    bridge->addRosSubscriber<RosIceBridge::Num>("test",1000,&Bridge<Message::MonitorPrx>::rosCallback,bridge);
    bridge->addIceProxy("SimpleMonitor:default -p 10000");


    RosIceBridge::Num var;
    var.num = 0;

    while(var.num < 100)
    {
        var.num = var.num + 1;
        bridge->rosPublish<RosIceBridge::Num>(var);
    }

    while(var.num < 200)
    {
        var.num = var.num + 1;
    }

    delete bridge;



    return 0;
}
