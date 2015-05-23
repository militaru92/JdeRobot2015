#ifndef ROSICEBRIDGE_H
#define ROSICEBRIDGE_H

#include "ros/ros.h"


class RosIceBridge
{

private:
    ros::NodeHandle* RosNode;
    ros::Publisher*  RosPublisher;
    ros::Subscriber* RosSubscriber;
    ros::AsyncSpinner* RosSpinner;

public:
    RosIceBridge();
    virtual ~RosIceBridge();


};

#endif // ROSICEBRIDGE_H
