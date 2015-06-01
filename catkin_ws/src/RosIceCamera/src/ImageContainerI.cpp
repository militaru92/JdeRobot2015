#include "ImageContainerI.h"

ImageContainerI::ImageContainerI()
{
    cv::namedWindow("Image window");
}

ImageContainerI::~ImageContainerI()
{
    cv::destroyWindow("Image window");
}

void ImageContainerI::publishImage(const Message::ImageData& IceImage, const Ice::Current&)
{

    size_t dest_len = IceImage.rows * IceImage.cols * 3;
    size_t source_len = IceImage.data.size();

    unsigned char* origin_buf = (uchar*) malloc(dest_len);

    memcpy(origin_buf,  (unsigned char *) &(IceImage.data[0]), IceImage.rows * IceImage.cols * 3);

    cv::Mat image = cv::Mat(cvSize(IceImage.cols,IceImage.rows), IceImage.type, origin_buf);

    cv::imshow("Image window", image);
    cv::waitKey(3);


}

