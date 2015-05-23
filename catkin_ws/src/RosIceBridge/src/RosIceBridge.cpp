#include <RosIceBridge.h>


RosIceBridge::RosIceBridge()
{
    RosNode = new ros::NodeHandle;
    RosSpinner = new ros::AsyncSpinner(4);


    RosSpinner->start();

}

RosIceBridge::RosIceBridge()
{
    delete RosNode;
    RosSpinner->stop();

}
