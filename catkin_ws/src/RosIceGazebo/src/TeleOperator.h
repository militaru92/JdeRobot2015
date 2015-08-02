#ifndef TELEOPERATOR_H
#define TELEOPERATOR_H

#include <iostream>
#include "ros/ros.h"
#include <RosIceMessage/MotorData.h>
#include <geometry_msgs/Twist.h>




class TeleOperator
{

private:

    ros::NodeHandle* RosNode;
    ros::Publisher*  RosPublisher;
    ros::Subscriber* RosSubscriber;


public:


    TeleOperator(int argc, char **argv, std::string nodeName);



    virtual ~TeleOperator();

    void rosCallback(geometry_msgs::Twist twistMessage);







};

#endif // TELEOPERATOR_H
