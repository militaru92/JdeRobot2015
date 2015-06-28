#include "Pose3DClient.h"

Pose3DClient::Pose3DClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher <geometry_msgs::Pose> (nodeName,500);



}

Pose3DClient::~Pose3DClient()
{

}

geometry_msgs::Pose Pose3DClient::publishROS()
{

    geometry_msgs::Pose Pose3DMsg;

    jderobot::Pose3DDataPtr Pose3DData;

    Pose3DData = this->Proxy->getPose3DData();

    if(Pose3DData->h == 0)
    {
        Pose3DMsg.position.x = Pose3DData->x;
        Pose3DMsg.position.y = Pose3DData->y;
        Pose3DMsg.position.z = Pose3DData->z;
    }

    else
    {
        Pose3DMsg.position.x = Pose3DData->x / Pose3DData->h;
        Pose3DMsg.position.y = Pose3DData->y / Pose3DData->h;
        Pose3DMsg.position.z = Pose3DData->z / Pose3DData->h;
    }


    Pose3DMsg.orientation.w = Pose3DData->q0;
    Pose3DMsg.orientation.x = Pose3DData->q1;
    Pose3DMsg.orientation.y = Pose3DData->q2;
    Pose3DMsg.orientation.z = Pose3DData->q3;


    rosPublish(Pose3DMsg);

    return Pose3DMsg;
}

void Pose3DClient::rosCallback(geometry_msgs::Pose Pose3DMessage)
{



}

