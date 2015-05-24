#include "ros/ros.h"
#include "Ros_Ice.h"
#include "RosIceBridge/Num.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "pub");

    Ros_Ice publisher_bridge;

    publisher_bridge.addRosPublisher<RosIceBridge::Num>("test",10);

    long count = 0;
    while (ros::ok())
    {
        RosIceBridge::Num n;
        n.num = count;

        publisher_bridge.rosPublish<RosIceBridge::Num>(n);
        ++count;
    }

    return 0;
}
