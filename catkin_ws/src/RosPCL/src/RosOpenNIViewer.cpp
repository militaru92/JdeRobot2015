#include "RosOpenNIViewer.h"

RosOpenNIViewer::RosOpenNIViewer (int argc, char **argv, std::string nodeName, std::string topicName) : viewer ("PCL OpenNI Viewer")
{

    initializeROS(argc,argv,nodeName);
    addRosSubscriber(topicName,500,&RosOpenNIViewer::rosCallback,this);
}

void RosOpenNIViewer::rosCallback(const pcl::PointCloud < pcl::PointXYZRGBA >::ConstPtr &cloud)
{
    if (!viewer.wasStopped())
      viewer.showCloud (cloud);
}
