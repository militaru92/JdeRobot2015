#ifndef ROSBAGPARSER_H
#define ROSBAGPARSER_H

#include "rosbag/bag.h"
#include "rosbag/view.h"

/**
 * @brief This class is the base component for this package.
 * It offers methods to parse a rosbag file and return data of given topic in an iterative way
 */

class RosBagParser
{

public:

    RosBagParser();
    RosBagParser(std::string fileName, std::string topicName);

    virtual ~RosBagParser();

    /**
     * @brief This method is used to configure the private members which are responsible for parsing and quering the file
     * @param fileName: This parameter represents the path to the rosbag file
     * @param topicName: This parameter represents the name of the topic on which the desired data was published
     *
     */


    bool configureRosBag(std::string fileName, std::string topicName);

    /**
     * @brief This method returns true if there is no more data on the given topic to return
     *
     */

    bool atEnd();

    /**
     * @brief This method returns an iterator to the current message instance
     */

    rosbag::View::iterator getIterator();

    /**
     * @brief This method makes the iterator to point to the next message instance
     */

    void increment();


private:


    rosbag::Bag* bag;
    rosbag::View* view;

    /**
     * @brief Iterator to the current message instance
     */

    rosbag::View::iterator iter;






};


#endif // ROSBAGPARSER_H
