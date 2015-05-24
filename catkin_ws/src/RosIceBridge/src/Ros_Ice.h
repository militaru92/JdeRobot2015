#ifndef ROS_ICE_H
#define ROS_ICE_H

#include "ros/ros.h"



class Ros_Ice
{

private:
    ros::NodeHandle* RosNode;
    ros::Publisher*  RosPublisher;
    ros::Subscriber* RosSubscriber;
    ros::AsyncSpinner* RosSpinner;

public:
    Ros_Ice();
    virtual ~Ros_Ice();


    template <class ROS_DATA>
    void addRosPublisher(std::string rosTopic, int queueSize)
    {
        RosPublisher = new ros::Publisher(RosNode->advertise<ROS_DATA>(rosTopic, queueSize));

    }


    template <class ROS_DATA>
    void addRosSubscriber(std::string rosTopic, int queueSize,void(*callback)(ROS_DATA))
    {
        RosSubscriber = new ros::Subscriber(RosNode->subscribe(rosTopic, queueSize, callback));

    }


    template <class ROS_DATA>
    void rosPublish(ROS_DATA message)
    {
        RosPublisher->publish(message);
    }




};

#endif // ROSICEBRIDGE_H
