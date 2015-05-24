#include "Ros_Ice.h"


Ros_Ice::Ros_Ice()
{
    RosNode = new ros::NodeHandle;
    RosSpinner = new ros::AsyncSpinner(4);
    RosPublisher = NULL;
    RosSubscriber = NULL;


    RosSpinner->start();

}

Ros_Ice::~Ros_Ice()
{
    delete RosNode;


    if(RosPublisher)
    {
        delete RosPublisher;
    }

    if(RosSubscriber)
    {
        delete RosSubscriber;
    }

    RosSpinner->stop();
    delete RosSpinner;

}
/*
template <class ROS_DATA>
void Ros_Ice::addRosPublisher(std::string rosTopic, int queueSize)
{
    RosPublisher = new ros::Publisher(RosNode->advertise<ROS_DATA>(rosTopic, queueSize));

}

template <class ROS_DATA>
void Ros_Ice::addRosSubscriber(std::string rosTopic, int queueSize,RosSubscriberHandler<ROS_DATA>* handler)
{
    RosSubscriber = new ros::Subscriber(RosNode->subscribe(rosTopic, queueSize, RosSubscriberHandler<ROS_DATA>::callback, handler ));

}



template <class ROS_DATA>
void Ros_Ice::rosPublish(ROS_DATA message)
{
    RosPublisher->publish(message);
}
*/
