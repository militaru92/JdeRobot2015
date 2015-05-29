#include <iostream>
#include <Ice/Ice.h>
#include <Num.h>


int main(int argc, char **argv)
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        ic = Ice::initialize(argc, argv);

        Message::MonitorPrx monitor = Message::MonitorPrx::checkedCast(ic->stringToProxy("SimpleMonitor:default -p 10000"));
        if (!monitor)
            throw "Invalid proxy";

        Message::Num IceMessage;
        long a = 0;
        while(a < 100)
        {
            IceMessage.value = a;
            monitor->publish2(IceMessage);
            ++a;

        }

        while(a<200)
        {
            ++a;
        }


    } catch (const Ice::Exception& ex) {
        std::cerr << ex << std::endl;
        status = 1;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        status = 1;
    }
    if (ic)
        ic->destroy();
    return status;
}

