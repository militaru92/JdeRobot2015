#ifndef LASERCLIENT_H
#define LASERCLIENT_H

#include "Ros_Ice.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/PolygonStamped.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <laser.h>
#include <RosIceGazebo/Laser.h>
#include <RosIceGazebo/EncodersData.h>
#include <geometry_msgs/Pose.h>
//#include <geometry_msgs/Vector3.h>
#include <visionlib/colorspaces/colorspacesmm.h>
#include <tf/tf.h>


class LaserClient : public Ros_Ice < jderobot::LaserPrx >
{

public:

    LaserClient(int argc, char **argv, std::string nodeName);
    ~LaserClient();

    void publishROS(RosIceGazebo::EncodersData encodersMessage);
    void publishROS(geometry_msgs::Pose pose3DMessage);

    void rosCallback_Encoders(RosIceGazebo::Laser laserMessage);
    void rosCallback_Pose3D(RosIceGazebo::Laser laserMessage);
    void rosCallback(RosIceGazebo::Laser laserMessage);

    void setRobotPos(RosIceGazebo::EncodersData encodersMessage);

private:

    void positionMarkers(float x, float y, float costheta, float sintheta);
    void positionMarkers(float x, float y, tf::Quaternion rotation);

    geometry_msgs::Pose getPose(double x, double y, double z, double roll, double pitch, double yaw);



    std::string ImageWindow;
    float laser_coord[5];
    double PI;
    double DEGTORAD;

    ros::NodeHandle* Laser3DRosNode;

    ros::Publisher* Laser3DPublisher;
    ros::Publisher* MarkerPublisher;
    //ros::Subscriber* Laser3DSubscriber;

    float robotx;
    float roboty;
    float robottheta;

    visualization_msgs::MarkerArray marker_array;





};

#endif // LASERCLIENT_H
