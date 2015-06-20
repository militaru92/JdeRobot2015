#include "EncodersClient.h"
#include "MotorClient.h"
#include "CameraClient.h"
#include "LaserClient.h"
#include "Pose3DMotorsClient.h"
#include "TeleOperator.h"
#include <opencv2/opencv.hpp>


int main(int argc, char **argv)
{

    int status;
    Ice::CommunicatorPtr ic;

    CameraClient cameraClient1(argc,argv,"camera1");
    CameraClient cameraClient2(argc,argv,"camera2");

    EncodersClient encodersClient(argc,argv,"encoders");



    LaserClient laserClient(argc,argv,"laser");

    MotorClient motorClient(argc, argv, "motor");

    TeleOperator teleOperator(argc, argv, "pioneer");


    ros::AsyncSpinner RosSpinner(4);
    RosSpinner.start();




    try
    {
        ic = Ice::initialize(argc, argv);

        cameraClient1.addIceProxy("introrob.Camera1.Proxy",ic,1);
        cameraClient2.addIceProxy("introrob.Camera2.Proxy",ic,1);

        encodersClient.addIceProxy("introrob.Encoders.Proxy",ic,1);

        laserClient.addIceProxy("introrob.Laser.Proxy",ic,1);

        motorClient.addIceProxy("introrob.Motors.Proxy",ic,1);

        RosIceGazebo::MotorData motorMsg;
        RosIceGazebo::EncodersData encodersMsg;

        motorMsg.motorW = -10.0;
        motorMsg.motorL = 25.0;
        motorMsg.motorV = 25.0;

        while(ros::ok())
        {
            cameraClient1.publishROS();
            cameraClient2.publishROS();

            encodersMsg = encodersClient.publishROS();

            laserClient.publishROS(encodersMsg);

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
