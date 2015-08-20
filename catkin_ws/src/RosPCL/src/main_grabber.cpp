#include <pcl/io/openni_grabber.h>
//#include <pcl/visualization/cloud_viewer.h>
#include <pcl_ros/point_cloud.h>

#include "Ros_Ice.h"

class SimpleOpenNIGrabber : public Ros_Ice< Ice::ObjectPrx >
{
  public:
    SimpleOpenNIGrabber (int argc, char **argv, std::string nodeName)
    {
        initializeROS(argc,argv,nodeName);
        addRosPublisher < pcl::PointCloud<pcl::PointXYZRGBA> >(nodeName,500);
    }

    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
    {
        rosPublish(*cloud);
\
    }

    void run ()
    {
      pcl::Grabber* interface = new pcl::OpenNIGrabber();

      boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f =
        boost::bind (&SimpleOpenNIGrabber::cloud_cb_, this, _1);

      interface->registerCallback (f);

      interface->start ();

      while (true)
      {
        boost::this_thread::sleep (boost::posix_time::seconds (1));
      }

      interface->stop ();
    }


};

int main (int argc, char **argv)
{
    ros::init(argc, argv, "test");

    ros::AsyncSpinner spinner(4);

    spinner.start();

    SimpleOpenNIGrabber v(argc,argv,"openni");

    v.run ();

    return 0;
}
