#include "MotorsInterface.h"

MotorsInterface::MotorsInterface(int argc, char **argv, std::string nodeName)
{

}

MotorsInterface::~MotorsInterface()
{

}

float MotorsInterface::getL(const Ice::Current &)
{

    return 0.0;

}

float MotorsInterface::getW(const Ice::Current &)
{
    return 0.0;
}

float MotorsInterface::getV(const Ice::Current &)
{
    return 0.0;

}

Ice::Int MotorsInterface::setV(Ice::Float v, const Ice::Current&)
{
    return 0;

}

Ice::Int MotorsInterface::setW(Ice::Float w, const Ice::Current&)
{
    return 0;

}

Ice::Int MotorsInterface::setL(Ice::Float l, const Ice::Current&)
{
    return 0;
}



