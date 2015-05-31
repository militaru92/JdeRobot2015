#ifndef ROSIMAGEPUBLISHER_H
#define ROSIMAGEPUBLISHER_H

#include <cstdlib>
#include <zlib.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <Image.h>
#include "Ros_Ice.h"

class RosImageServer : public Ros_Ice< Message::ImageContainerPrx >
{

public:

    RosImageServer(int argc, char **argv, std::string nodeName);

    void rosCallback(const sensor_msgs::ImageConstPtr& image_message);

};

#endif // ROSIMAGEPUBLISHER_H
