
#include "ArDroneExtraClient.h"

ArDroneExtraClient::ArDroneExtraClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher < std_msgs::Bool > (nodeName,1000);
    addRosSubscriber(nodeName,1000,&ArDroneExtraClient::rosCallback,this);



}

ArDroneExtraClient::~ArDroneExtraClient()
{

}



void ArDroneExtraClient::rosCallback(std_msgs::Bool value)
{
    if(value.data == true)
    {
        std::cout<<"Take\n";
        this->Proxy->takeoff();
    }

    else
    {
        std::cout<<"Land\n";
        this->Proxy->land();
    }


}
