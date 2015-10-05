#include "CMDVelClient.h"
#include "ArDroneExtraClient.h"

int main(int argc, char **argv)
{

    int status;
    Ice::CommunicatorPtr ic;


    CMDVelClient cmdVelClient(argc,argv,"cmdVel");

    ArDroneExtraClient arDroneExtraClient(argc,argv,"takeOff");

    ros::AsyncSpinner RosSpinner(4);
    RosSpinner.start();




    try
    {
        ic = Ice::initialize(argc, argv);

        cmdVelClient.addIceProxy("Introrob.CMDVel.Proxy",ic,1);

        arDroneExtraClient.addIceProxy("Introrob.Extra.Proxy",ic,1);

        while(ros::ok())
        {

        }


    }
    catch (const Ice::Exception& ex)
    {
        std::cerr << ex << std::endl;
        status = 1;
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
        status = 1;
    }

    return 0;
}
