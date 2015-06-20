#include "TeleOperator.h"

TeleOperator::TeleOperator(int argc, char **argv, std::string nodeName)
{
    ros::init(argc, argv, nodeName);
    RosNode = new ros::NodeHandle;

    RosPublisher = new ros::Publisher(RosNode->advertise<RosIceGazebo::MotorData>("motor", 500));
    RosSubscriber = new ros::Subscriber(RosNode->subscribe(nodeName, 500, &TeleOperator::rosCallback, this));



}


TeleOperator::~TeleOperator()
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



}

void TeleOperator::rosCallback(geometry_msgs::Twist twistMessage)
{
    //ROS_INFO("Twist: %lf %lf %lf %lf %lf %lf\n", twistMessage.linear.x,twistMessage.linear.y,twistMessage.linear.z,twistMessage.angular.x,twistMessage.angular.y,twistMessage.angular.z);


    RosIceGazebo::MotorData motorMsg;

    motorMsg.motorW = twistMessage.angular.z;
    motorMsg.motorL = 0.0;
    motorMsg.motorV = twistMessage.linear.x * 1.5;

    RosPublisher->publish(motorMsg);

}
