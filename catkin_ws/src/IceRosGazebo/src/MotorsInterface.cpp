#include "MotorsInterface.h"

MotorsInterface::MotorsInterface(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    //addRosSubscriber<IceRosGazebo::MotorData>("laser",500,&LaserInterface::rosCallback,this);

    addRosPublisher<IceRosGazebo::MotorData>("motors_subscriber",500);
    addRosServiceClient<IceRosGazebo::MotorsSrv>("motors_server");


    //myfile.open("Ros.txt");


}

MotorsInterface::~MotorsInterface()
{

}

float MotorsInterface::getL(const Ice::Current &)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    return srv.response.motorMsg.motorL;

}

float MotorsInterface::getW(const Ice::Current &)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    return srv.response.motorMsg.motorW;
}

float MotorsInterface::getV(const Ice::Current &)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    return srv.response.motorMsg.motorV;

}

Ice::Int MotorsInterface::setV(Ice::Float v, const Ice::Current&)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    srv.response.motorMsg.motorV = v;
    rosPublish(srv.response.motorMsg);
}

Ice::Int MotorsInterface::setW(Ice::Float w, const Ice::Current&)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    srv.response.motorMsg.motorW = -w;
    rosPublish(srv.response.motorMsg);
}

Ice::Int MotorsInterface::setL(Ice::Float l, const Ice::Current&)
{
    IceRosGazebo::MotorsSrv srv;
    rosServiceCall(srv);
    srv.response.motorMsg.motorL = l;
    rosPublish(srv.response.motorMsg);

}



