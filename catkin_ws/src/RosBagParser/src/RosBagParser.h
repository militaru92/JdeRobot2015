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

    rosbag::View::iterator getIterator();

    bool increment();


private:


    rosbag::Bag* bag;
    rosbag::View* view;

    rosbag::View::iterator iter;




};


#endif // ROSBAGPARSER_H
