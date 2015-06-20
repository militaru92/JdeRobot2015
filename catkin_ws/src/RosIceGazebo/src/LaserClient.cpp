#include "LaserClient.h"

LaserClient::LaserClient(int argc, char **argv, std::string nodeName)
{
    initializeROS(argc,argv,nodeName);
    addRosPublisher <RosIceGazebo::Laser> (nodeName,1000);
    addRosSubscriber(nodeName,1000,&LaserClient::rosCallback,this);
    addRosImagePublisher(nodeName + "_image",1000);

    Laser3DRosNode = new ros::NodeHandle;

    Laser3DPublisher = new ros::Publisher(Laser3DRosNode->advertise<geometry_msgs::PolygonStamped>(nodeName + "_3D", 500));

    //Laser3DSubscriber = new ros::Subscriber(Laser3DRosNode->subscribe("encoders", 500, &LaserClient::setRobotPos,this));


    ImageWindow = nodeName;

    PI = 4.0 * atan(1);
    DEGTORAD = PI / 180.0;

    laser_coord[0] = 19.;
    laser_coord[1] = 0.;
    laser_coord[2] = 0.;
    laser_coord[3] = cos(laser_coord[2] * DEGTORAD);
    laser_coord[4] = sin(laser_coord[2] * DEGTORAD);


    cv::namedWindow(ImageWindow);
}

LaserClient::~LaserClient()
{
    cv::destroyWindow(ImageWindow);

    delete Laser3DRosNode;
    delete Laser3DPublisher;
    //delete Laser3DSubscriber;
}

void LaserClient::publishROS(RosIceGazebo::EncodersData encodersMessage)
{
    jderobot::LaserDataPtr laserData= this->Proxy->getLaserData();
    RosIceGazebo::Laser rosLaserData;

    rosLaserData.numLaser = laserData->numLaser;
    rosLaserData.distanceData = laserData->distanceData;

    rosLaserData.position = encodersMessage;

    rosPublish(rosLaserData);

}

void LaserClient::rosCallback(RosIceGazebo::Laser laserMessage)
{
    cv::Mat laserImage(180,360, CV_8UC3, cv::Scalar(0,0,0));

    geometry_msgs::PolygonStamped laser_world;
    geometry_msgs::Point32 point;


    float X,Y,costheta,sintheta,aux_x,aux_y;

    point.z = 3.2;

    costheta = cos(laserMessage.position.robottheta * PI / 180.0);
    sintheta = sin(laserMessage.position.robottheta * PI / 180.0);

    laser_world.header.frame_id = "map";
    laser_world.header.stamp = ros::Time();
    laser_world.header.seq = 0;


    cv::line(laserImage,cv::Point(180,165),cv::Point(180,180),cv::Scalar(255,0,0));


    for (int i = laserMessage.numLaser - 1; i > 0; --i)
    {
        cv::line(laserImage, cv::Point(180 + ((laserMessage.distanceData[i] / 45)*(cos((i) * DEGTORAD))), 180 - ((laserMessage.distanceData[i] / 45)*(sin((i) * DEGTORAD)))), cv::Point(180 + ((laserMessage.distanceData[i + 1] / 45)*(cos((i + 1) * DEGTORAD))), 180 - ((laserMessage.distanceData[i + 1] / 45)*(sin((i + 1) * DEGTORAD)))),cv::Scalar(255,255,255));

        X = laserMessage.distanceData[i] * cos(((float) i - 90.) * DEGTORAD);
        Y = laserMessage.distanceData[i] * sin(((float) i - 90.) * DEGTORAD );

        point.x = (laser_coord[0]*10. + X * laser_coord[3] - Y * laser_coord[4] + laserMessage.position.robotx) / 100;
        point.y = (laser_coord[1] + Y * laser_coord[3] + X * laser_coord[4] + laserMessage.position.roboty) / 100;

        aux_x = costheta * point.x - sintheta * point.y;
        aux_y = sintheta * point.x + costheta * point.y;

        point.x = aux_x;
        point.y = aux_y;

        //ROS_INFO("Point %f %f \n", point.x, point.y);

        laser_world.polygon.points.push_back(point);
    }

    point.x = (laser_coord[0] * 10.0 + laserMessage.position.robotx)/ 100;
    point.y = (laser_coord[1] + laserMessage.position.roboty)/ 100;

    aux_x = costheta * point.x - sintheta * point.y;
    aux_y = sintheta * point.x + costheta * point.y;

    point.x = aux_x;
    point.y = aux_y;

    laser_world.polygon.points.push_back(point);



    sensor_msgs::ImagePtr image_message = cv_bridge::CvImage(std_msgs::Header(), "rgb8", laserImage).toImageMsg();
    rosImagePublish(image_message);

    Laser3DPublisher->publish(laser_world);


}

void LaserClient::setRobotPos(RosIceGazebo::EncodersData encodersMessage)
{
    this->robotx = encodersMessage.robotx;
    this->roboty = encodersMessage.roboty;
    this->robottheta = encodersMessage.robottheta;
}

