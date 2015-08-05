#ifndef ROSBAGPARSER_H
#define ROSBAGPARSER_H

#include "rosbag/bag.h"
#include "rosbag/view.h"

class RosBagParser
{

public:

    RosBagParser();
    RosBagParser(std::string fileName, std::string topicName);

    virtual ~RosBagParser();

    bool configureRosBag(std::string fileName, std::string topicName);

    bool atEnd();

    rosbag::View::iterator getIterator();

    void increment();

    int index;


private:


    rosbag::Bag* bag;
    rosbag::View* view;

    rosbag::View::iterator iter;






};


#endif // ROSBAGPARSER_H
