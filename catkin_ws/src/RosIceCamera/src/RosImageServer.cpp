
#include "RosImageServer.h"

RosImageServer::RosImageServer(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    runROSSpinner();
    addRosImagePublisher("test",1000);
    addRosImageSubscriber<RosImageServer>("test",1000,&RosImageServer::rosCallback,this);


}

void RosImageServer::rosCallback(const sensor_msgs::ImageConstPtr &image_message)
{

}
