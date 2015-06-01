
#include <opencv2/opencv.hpp>
#include <iostream>
#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>
#include <jderobot/camera.h>
#include <visionlib/colorspaces/colorspacesmm.h>
#include "parallelIce/cameraClient.h"
#include "CameraClient.h"

int main(int argc, char** argv){


    int status;
    Ice::CommunicatorPtr ic;

    jderobot::cameraClient* camRGB;
    CameraClient c = CameraClient(argc,argv,"cam");

    try
    {

        ic = Ice::initialize(argc,argv);
        Ice::ObjectPrx base = ic->propertyToProxy("Cameraview.Camera.Proxy");
        Ice::PropertiesPtr prop = ic->getProperties();

        if (0==base)
            throw "Could not create proxy";


        camRGB = new jderobot::cameraClient(ic,"Cameraview.Camera.");

        if (camRGB == NULL)
        {
            throw "Invalid proxy";
        }

        camRGB->start();

        cv::Mat rgb;

        while(ros::ok())
        {


            camRGB->getImage(rgb);

            sensor_msgs::ImagePtr img_message = cv_bridge::CvImage(std_msgs::Header(), "rgb8", rgb).toImageMsg();

            c.rosImagePublish(img_message);

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

    camRGB->stop_thread();
    delete(camRGB);

    return status;
}

