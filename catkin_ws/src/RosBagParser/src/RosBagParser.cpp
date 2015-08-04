#include "RosBagParser.h"

RosBagParser::RosBagParser()
{
    this->bag = NULL;
    this->view = NULL;
}

RosBagParser::RosBagParser(std::string fileName, std::string topicName)
{
    configureRosBag(fileName,topicName);
}

RosBagParser::~RosBagParser()
{
    if(bag)
    {
        bag->close();
        delete bag;
    }

    if(view)
    {
        delete view;
    }
}

bool RosBagParser::configureRosBag(std::string fileName, std::string topicName)
{
    bag = new rosbag::Bag(fileName);

    view = new rosbag::View(*bag, rosbag::TopicQuery(topicName));

    iter = view->begin();



    return true;

}

rosbag::View::iterator RosBagParser::getIterator()
{
    return iter;
}

bool RosBagParser::increment()
{

    ++iter;

    if(iter == view->end())
    {
        return false;
    }



    return true;

}
