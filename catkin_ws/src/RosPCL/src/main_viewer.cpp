
#include <pcl/visualization/cloud_viewer.h>
#include <pcl_ros/point_cloud.h>

#include "Ros_Ice.h"

class SimpleOpenNIViewer : public Ros_Ice< Ice::ObjectPrx >
{
  public:
    SimpleOpenNIViewer (int argc, char **argv, std::string nodeName) : viewer ("PCL OpenNI Viewer")
    {
        initializeROS(argc,argv,nodeName);
        addRosSubscriber(nodeName,500,&SimpleOpenNIViewer::rosCallback,this);
    }

    void rosCallback(const pcl::PointCloud < pcl::PointXYZRGBA >::ConstPtr &cloud)
    {
        if (!viewer.wasStopped())
          viewer.showCloud (cloud);
\
    }

    pcl::visualization::CloudViewer viewer;


};


int main (int argc, char **argv)
{
    ros::init(argc, argv, "test2");

    ros::AsyncSpinner spinner(4);

    spinner.start();

    SimpleOpenNIViewer v(argc,argv,"openni");

    while(ros::ok())
    {

    }

  return 0;
}
