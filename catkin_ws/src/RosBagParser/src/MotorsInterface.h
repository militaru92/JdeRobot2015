#ifndef MOTORSINTERFACE_H
#define MOTORSINTERFACE_H

#include <jderobot/motors.h>
#include <RosIceMessage/MotorData.h>
#include <RosIceMessage/MotorsSrv.h>


class MotorsInterface : virtual public jderobot::Motors
{

public:

    MotorsInterface(int argc, char **argv, std::string nodeName);

    ~MotorsInterface();

    virtual float getV(const Ice::Current&);
    virtual float getW(const Ice::Current&);
    virtual float getL(const Ice::Current&);

    virtual Ice::Int setV(Ice::Float v, const Ice::Current&);
    virtual Ice::Int setW(Ice::Float w, const Ice::Current&);
    virtual Ice::Int setL(Ice::Float l, const Ice::Current&);



};



#endif // MOTORSINTERFACE_H
