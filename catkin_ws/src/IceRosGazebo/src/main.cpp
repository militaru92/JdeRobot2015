
#include <jderobot/encoders.h>
#include <jderobot/laser.h>
#include <jderobot/camera.h>
#include <Ice/Ice.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <visionlib/colorspaces/colorspacesmm.h>


#include <fstream>

int main(int argc, char **argv)
{

    int status;
    Ice::CommunicatorPtr ic;

    std::ofstream myfile("Ice.txt");

    try
    {

        ic = Ice::initialize(argc,argv);


        Ice::ObjectPrx baseEncoders = ic->propertyToProxy("introrob.Encoders.Proxy");
        if (0 == baseEncoders)
            throw "Could not create proxy with encoders";

        jderobot::EncodersPrx eprx;

        // Cast to encoders
        eprx = jderobot::EncodersPrx::checkedCast(baseEncoders);
        if (0 == eprx)
            throw "Invalid proxy introrob.Encoders.Proxy";

        // Contact to LASER interface
        Ice::ObjectPrx baseLaser = ic->propertyToProxy("introrob.Laser.Proxy");
        if (0 == baseLaser)
            throw "Could not create proxy with laser";

        jderobot::LaserPrx lprx;

        // Cast to laser
        lprx = jderobot::LaserPrx::checkedCast(baseLaser);
        if (0 == lprx)
            throw "Invalid proxy introrob.Laser.Proxy";


        Ice::ObjectPrx camara1 = ic->propertyToProxy("introrob.Camera1.Proxy");
        if (0 == camara1)
            throw "Could not create proxy to camera1 server";

        jderobot::CameraPrx cprx1;

        cprx1 = jderobot::CameraPrx::checkedCast(camara1);
        if (0 == cprx1)
            throw "Invalid proxy";

        cv::namedWindow("Image window");



        while(1)
        {
            //jderobot::EncodersDataPtr data = eprx->getEncodersData();

            //std::cout << data->robotx << " " << data->roboty << " " << data->robottheta << std::endl;
/*
            jderobot::LaserDataPtr data = lprx->getLaserData();

            for(int i = 0 ; i < data->numLaser; ++i)
            {
               myfile << data->distanceData[i]<< " ";
            }

            myfile <<data->numLaser<< std::endl;
*/

            jderobot::ImageDataPtr imageData1;

            imageData1 = cprx1->getImageData(colorspaces::ImageRGB8::FORMAT_RGB8.get()->name);

            size_t dest_len = imageData1->description->height * imageData1->description->width * 3;

            unsigned char* origin_buf = (uchar*) malloc(dest_len);

            memcpy(origin_buf,  (unsigned char *) &(imageData1->pixelData[0]), imageData1->description->height * imageData1->description->width * 3);

            cv::Mat image = cv::Mat(cvSize(imageData1->description->width,imageData1->description->height), CV_8UC3, origin_buf);

            cv::imshow("Image window", image);
            cv::waitKey(3);


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

    cv::destroyWindow("Image window");



    return status;

}

