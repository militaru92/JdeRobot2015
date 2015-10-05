
#include "CMDVelClient.h"

CMDVelClient::CMDVelClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher < RosIceMessage::CMDVelData > (nodeName,1000);
    addRosSubscriber(nodeName,1000,&CMDVelClient::rosCallback,this);

    this->cmdVel = new jderobot::CMDVelData;



}

CMDVelClient::~CMDVelClient()
{

}



void CMDVelClient::rosCallback(RosIceMessage::CMDVelData cmdVelData)
{
    cmdVel->linearX = cmdVelData.linearX;

    this->Proxy->setCMDVelData(cmdVel);

}


