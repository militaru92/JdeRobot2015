#ifndef ROSIMAGEPUBLISHER_H
#define ROSIMAGEPUBLISHER_H

#include <cv_bridge/cv_bridge.h>
#include "Ros_Ice.h"

class RosImageServer : public Ros_Ice< Ice::ObjectPrx >
{

public:

    RosImageServer(int argc, char **argv, std::string nodeName);

    void rosCallback(const sensor_msgs::ImageConstPtr& image_message);

};

#endif // ROSIMAGEPUBLISHER_H
