#include "RosLaserPlugin.h"

namespace gazebo
{

RosLaserPlugin::RosLaserPlugin()
{

}

RosLaserPlugin::~RosLaserPlugin()
{

    delete RosPublisher;
    delete RosNode;
}

void RosLaserPlugin::Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf)
{

    RayPlugin::Load(_parent,_sdf);
    this->parentSensor =  boost::dynamic_pointer_cast<sensors::RaySensor>(_parent);
    RosNode = new ros::NodeHandle;
    RosPublisher = new ros::Publisher(RosNode->advertise<IceRosGazebo::Laser>(this->parentSensor->GetName(), 500));
}

void RosLaserPlugin::OnNewLaserScans()
{

    physics::MultiRayShapePtr laser = this->parentSensor->GetLaserShape();

    IceRosGazebo::Laser laserMsg;

    laserMsg.numLaser = laser->GetSampleCount();

    laserMsg.distanceData.resize(laser->GetSampleCount());

    for (int i = 0; i < laser->GetSampleCount(); ++i)
    {
        laserMsg.distanceData[i] = laser->GetRange(i) * 1000;
    }

    RosPublisher->publish(laserMsg);

}


}

