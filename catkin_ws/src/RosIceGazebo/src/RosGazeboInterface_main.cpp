#include "Ros_Ice.h"
#include "CameraClient.h"
#include "LaserClient.h"
#include <opencv2/opencv.hpp>


int main(int argc, char **argv)
{

    int status;
    Ice::CommunicatorPtr ic;

    CameraClient cameraClient1(argc,argv,"camera1");
    CameraClient cameraClient2(argc,argv,"camera2");

    LaserClient laserClient(argc,argv,"laser");



    ros::AsyncSpinner RosSpinner(4);
    RosSpinner.start();




    try
    {
        ic = Ice::initialize(argc, argv);

        cameraClient1.addIceProxy("introrob.Camera1.Proxy",ic,1);
        cameraClient2.addIceProxy("introrob.Camera2.Proxy",ic,1);
        laserClient.addIceProxy("introrob.Laser.Proxy",ic,1);


        while(ros::ok())
        {
            cameraClient1.publishROS();
            cameraClient2.publishROS();
            laserClient.publishROS();

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
    if (ic)
    {
        ic->destroy();
    }


    return 0;
}