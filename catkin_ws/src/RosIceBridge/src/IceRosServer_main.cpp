#include "IceRosBridge.h"

int main(int argc, char **argv)
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try
    {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("SimpleMonitorAdapter","default -p 10000" );

        IceRosBridge *bridge = new IceRosBridge;
        bridge->initializeROS(argc,argv,"publisher");
        bridge->addRosPublisher<RosIceBridge::Num>("test",1000);
        bridge->addRosSubscriber("test",1000,&IceRosBridge::rosCallback,bridge);
        Ice::ObjectPtr object = bridge;
        adapter->add(object, ic->stringToIdentity("SimpleMonitor"));
        adapter->activate();
        ic->waitForShutdown();
    }
    catch (const Ice::Exception& e)
    {
        std::cerr << e << std::endl;
        status = 1;
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
        status = 1;
    }

    if (ic)
    {
        try
        {
            ic->destroy();
        } catch (const Ice::Exception& e)
        {
            std::cerr << e << std::endl;
            status = 1;
        }
    }
    return status;
}
