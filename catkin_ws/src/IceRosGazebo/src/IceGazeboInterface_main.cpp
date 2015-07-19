
#include "EncodersInterface.h"
#include "LaserInterface.h"
#include "Pose3DInterface.h"
#include "CameraInterface.h"
#include "MotorsInterface.h"
#include "Pose3DEncodersInterface.h"


int main(int argc, char **argv)
{

    ros::init(argc, argv, "test");

    ros::AsyncSpinner spinner(4);

    spinner.start();

    Ice::CommunicatorPtr ic;
    int argc_2 = 1;
    Ice::PropertiesPtr prop;

    std::string str = "--Ice.Config=pioneer2dx.cfg";


    char* argv_2[] = {(char *) str.c_str()};

    try
    {

        ic = Ice::initialize(argc_2, argv_2);

        prop = ic->getProperties();
        std::string Endpoints = prop->getProperty("Encoders.Endpoints");
        std::cout << "Encoders Endpoints > " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_encoders = ic->createObjectAdapterWithEndpoints("Encoders", Endpoints);
        Ice::ObjectPtr object_encoders = new EncodersInterface(argc,argv,"encoders");

        adapter_encoders->add(object_encoders, ic->stringToIdentity("Encoders"));

        adapter_encoders->activate();

        Endpoints = prop->getProperty("Laser.Endpoints");
        std::cout << "Laser Endpoints > " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_laser = ic->createObjectAdapterWithEndpoints("Laser", Endpoints);
        Ice::ObjectPtr object_laser = new LaserInterface(argc,argv,"lasers");
        adapter_laser->add(object_laser, ic->stringToIdentity("Laser"));
        adapter_laser->activate();

        Endpoints = prop->getProperty("Pose3D.Endpoints");
        std::cout << "Pose3D Endpoints " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_pose3D = ic->createObjectAdapterWithEndpoints("Pose3D", Endpoints);
        Ice::ObjectPtr object_pose3D = new Pose3DInterface(argc,argv,"pose3d");

        adapter_pose3D->add(object_pose3D, ic->stringToIdentity("Pose3D"));

        adapter_pose3D->activate();

        Endpoints = prop->getProperty("CameraGazebo1.Endpoints");

        Ice::ObjectAdapterPtr adapter_cam_left = ic->createObjectAdapterWithEndpoints("CameraGazebo1", Endpoints);

        Ice::ObjectPtr object_cam_left = new CameraInterface(argc,argv,"cam_pioneer_left");
        adapter_cam_left->add(object_cam_left, ic->stringToIdentity("cam_pioneer_left"));
        adapter_cam_left->activate();

        Endpoints = prop->getProperty("CameraGazebo2.Endpoints");

        Ice::ObjectAdapterPtr adapter_cam_right = ic->createObjectAdapterWithEndpoints("CameraGazebo2", Endpoints);

        Ice::ObjectPtr object_cam_right = new CameraInterface(argc,argv,"cam_pioneer_right");
        adapter_cam_right->add(object_cam_right, ic->stringToIdentity("cam_pioneer_right"));
        adapter_cam_right->activate();

        Endpoints = prop->getProperty("Motors.Endpoints");
        std::cout << "Motors Endpoints > " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_motors = ic->createObjectAdapterWithEndpoints("Motors", Endpoints);
        Ice::ObjectPtr object_motors = new MotorsInterface(argc,argv,"motors");

        adapter_motors->add(object_motors, ic->stringToIdentity("Motors"));

        adapter_motors->activate();

        Endpoints = prop->getProperty("Pose3DEncoders1.Endpoints");
        std::cout << "Pose3DEncoders1 Endpoints > " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_pose3dencoders1 = ic->createObjectAdapterWithEndpoints("Pose3DEncoders1", Endpoints);

        Ice::ObjectPtr object_pose3dencoders1 = new Pose3DEncodersInterface(argc,argv,"pioneer_pose3dencoders_left_encoders");

        adapter_pose3dencoders1->add(object_pose3dencoders1, ic->stringToIdentity("Pose3DEncoders1"));
        adapter_pose3dencoders1->activate();



        Endpoints = prop->getProperty("Pose3DEncoders2.Endpoints");
        std::cout << "Pose3DEncoders2 Endpoints > " << Endpoints << std::endl;

        Ice::ObjectAdapterPtr adapter_pose3dencoders2 = ic->createObjectAdapterWithEndpoints("Pose3DEncoders2", Endpoints);

        Ice::ObjectPtr object_pose3dencoders2 = new Pose3DEncodersInterface(argc,argv,"pioneer_pose3dencoders_right_encoders");

        adapter_pose3dencoders2->add(object_pose3dencoders2, ic->stringToIdentity("Pose3DEncoders2"));
        adapter_pose3dencoders2->activate();


/*

        std::string Endpoints3 = prop->getProperty("Pose3DMotors1.Endpoints");
        std::cout << "Pose3DMotors1 Endpoints > " << Endpoints3 << std::endl;
        std::string Endpoints4 = prop->getProperty("Pose3DMotors2.Endpoints");
        std::cout << "Pose3DMotors2 Endpoints > " << Endpoints4 << std::endl;




        Ice::ObjectAdapterPtr adapter3 =
                ic->createObjectAdapterWithEndpoints("Pose3DMotors1", Endpoints3);
        Ice::ObjectAdapterPtr adapter4 =
                ic->createObjectAdapterWithEndpoints("Pose3DMotors2", Endpoints4);




        Ice::ObjectPtr object3 = new Pose3DMotorsI(base);
        Ice::ObjectPtr object4 = new Pose3DMotorsII(base);




        adapter3->add(object3, ic->stringToIdentity("Pose3DMotors1"));
        adapter4->add(object4, ic->stringToIdentity("Pose3DMotors2"));


        adapter3->activate();
        adapter4->activate();
*/
        std::cout <<"Before\n"<<std::endl;

        ic->waitForShutdown();

    }

    catch (const Ice::Exception& e)
    {
        std::cerr << e << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }

    if (ic)
    {
        try
        {
            ic->destroy();
        }
        catch (const Ice::Exception& e)
        {
            std::cerr << e << std::endl;
        }
    }

    return 0;
}
