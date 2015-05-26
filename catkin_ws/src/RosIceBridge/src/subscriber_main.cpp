#include "ros/ros.h"
#include "Ros_Ice.h"
#include "RosIceBridge/Num.h"
#include <Num.h>

class MonitorI : public Message::Monitor {
public:
    virtual void publish2(const Message::Num &, const Ice::Current&);
};

void
MonitorI::
publish2(const Message::Num& s, const Ice::Current&)
{
    std::cout << s.value << " Ice " << std::endl;
}

int main(int argc, char **argv)
{

    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("SimpleMonitorAdapter","default -p 10000" );
        Ice::ObjectPtr object = new MonitorI;
        adapter->add(object, ic->stringToIdentity("SimpleMonitor"));
        adapter->activate();
        ic->waitForShutdown();
    } catch (const Ice::Exception& e) {
        std::cerr << e << std::endl;
        status = 1;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        status = 1;
    }
    if (ic) {
        try {
            ic->destroy();
        } catch (const Ice::Exception& e) {
            std::cerr << e << std::endl;
            status = 1;
        }
    }
    return status;

}
