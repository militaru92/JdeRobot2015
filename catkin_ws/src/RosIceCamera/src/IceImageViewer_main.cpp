
#include <Ice/Ice.h>

#include "ImageContainerI.h"



int main(int argc, char **argv)
{

    int status = 0;
    Ice::CommunicatorPtr ic;
    try
    {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("SimpleImageAdapter","default -p 10000" );
        Ice::ObjectPtr object = new ImageContainerI;
        adapter->add(object, ic->stringToIdentity("SimpleImage"));
        adapter->activate();
        ic->waitForShutdown();
    } catch (const Ice::Exception& e)
    {
        std::cerr << e << std::endl;
        status = 1;
    } catch (const char* msg)
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
