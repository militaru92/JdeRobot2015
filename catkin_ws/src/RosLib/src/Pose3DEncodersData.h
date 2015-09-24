// Generated by gencpp from file RosIceMessage/Pose3DEncodersData.msg
// DO NOT EDIT!


#ifndef ROSICEMESSAGE_MESSAGE_POSE3DENCODERSDATA_H
#define ROSICEMESSAGE_MESSAGE_POSE3DENCODERSDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace RosIceMessage
{
template <class ContainerAllocator>
struct Pose3DEncodersData_
{
  typedef Pose3DEncodersData_<ContainerAllocator> Type;

  Pose3DEncodersData_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , pan(0.0)
    , tilt(0.0)
    , roll(0.0)
    , clock(0)
    , maxPan(0.0)
    , maxTilt(0.0)
    , minPan(0.0)
    , minTilt(0.0)  {
    }
  Pose3DEncodersData_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , pan(0.0)
    , tilt(0.0)
    , roll(0.0)
    , clock(0)
    , maxPan(0.0)
    , maxTilt(0.0)
    , minPan(0.0)
    , minTilt(0.0)  {
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _pan_type;
  _pan_type pan;

   typedef float _tilt_type;
  _tilt_type tilt;

   typedef float _roll_type;
  _roll_type roll;

   typedef int32_t _clock_type;
  _clock_type clock;

   typedef float _maxPan_type;
  _maxPan_type maxPan;

   typedef float _maxTilt_type;
  _maxTilt_type maxTilt;

   typedef float _minPan_type;
  _minPan_type minPan;

   typedef float _minTilt_type;
  _minTilt_type minTilt;




  typedef boost::shared_ptr< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> const> ConstPtr;

}; // struct Pose3DEncodersData_

typedef ::RosIceMessage::Pose3DEncodersData_<std::allocator<void> > Pose3DEncodersData;

typedef boost::shared_ptr< ::RosIceMessage::Pose3DEncodersData > Pose3DEncodersDataPtr;
typedef boost::shared_ptr< ::RosIceMessage::Pose3DEncodersData const> Pose3DEncodersDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace RosIceMessage

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'RosIceMessage': ['/home/ace15/Documents/JdeRobot/GoogleSummer/JdeRobot2015/catkin_ws/src/RosIceMessage/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ad83cdba898edfa6b6fc913d349fd18d";
  }

  static const char* value(const ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xad83cdba898edfa6ULL;
  static const uint64_t static_value2 = 0xb6fc913d349fd18dULL;
};

template<class ContainerAllocator>
struct DataType< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "RosIceMessage/Pose3DEncodersData";
  }

  static const char* value(const ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 x\n\
float32 y\n\
float32 z\n\
float32 pan\n\
float32 tilt\n\
float32 roll\n\
int32 clock\n\
float32 maxPan\n\
float32 maxTilt\n\
float32 minPan\n\
float32 minTilt\n\
";
  }

  static const char* value(const ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.pan);
      stream.next(m.tilt);
      stream.next(m.roll);
      stream.next(m.clock);
      stream.next(m.maxPan);
      stream.next(m.maxTilt);
      stream.next(m.minPan);
      stream.next(m.minTilt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Pose3DEncodersData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::RosIceMessage::Pose3DEncodersData_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "pan: ";
    Printer<float>::stream(s, indent + "  ", v.pan);
    s << indent << "tilt: ";
    Printer<float>::stream(s, indent + "  ", v.tilt);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "clock: ";
    Printer<int32_t>::stream(s, indent + "  ", v.clock);
    s << indent << "maxPan: ";
    Printer<float>::stream(s, indent + "  ", v.maxPan);
    s << indent << "maxTilt: ";
    Printer<float>::stream(s, indent + "  ", v.maxTilt);
    s << indent << "minPan: ";
    Printer<float>::stream(s, indent + "  ", v.minPan);
    s << indent << "minTilt: ";
    Printer<float>::stream(s, indent + "  ", v.minTilt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSICEMESSAGE_MESSAGE_POSE3DENCODERSDATA_H
