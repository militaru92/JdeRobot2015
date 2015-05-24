#include "ros/ros.h"
#include "Ros_Ice.h"
#include "RosIceBridge/Num.h"

void callback(RosIceBridge::Num rosMessage)
{
    ROS_INFO("I heard: [%ld]\n", rosMessage.num);
}


int main(int argc, char **argv)
{

    ros::init(argc, argv, "sub");

    Ros_Ice subscriber_bridge;

    subscriber_bridge.addRosSubscriber<RosIceBridge::Num>("test", 10,&callback);


    ros::waitForShutdown();

    return 0;
}
