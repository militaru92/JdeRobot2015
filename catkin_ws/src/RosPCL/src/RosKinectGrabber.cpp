#include "RosKinectGrabber.h"


RosKinectGrabber::RosKinectGrabber (int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher < RosPCL::RGB_Depth_Image >(nodeName,500);
}

void RosKinectGrabber::cloud_cb_ (const boost::shared_ptr<openni_wrapper::Image> &image, const boost::shared_ptr<openni_wrapper::DepthImage> &depth_image, float focallength_inverse)
{
    RosPCL::RGB_Depth_Image rgb_depth_message;

    //rosPublish(*cloud);
}

void RosKinectGrabber::run ()
{
  pcl::Grabber* interface = new pcl::OpenNIGrabber();

  boost::function<void (const boost::shared_ptr<openni_wrapper::Image> &image, const boost::shared_ptr<openni_wrapper::DepthImage> &depth_image, float focallength_inverse)> f =
    boost::bind (&RosKinectGrabber::cloud_cb_, this, _1, _2, _3);



  interface->registerCallback (f);

  interface->start ();

  while (true)
  {
    boost::this_thread::sleep (boost::posix_time::seconds (1));
  }

  interface->stop ();
}
