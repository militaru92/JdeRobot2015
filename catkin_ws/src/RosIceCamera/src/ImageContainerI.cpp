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

    int r = uncompress((Bytef *) origin_buf, (uLongf *) &dest_len, (const Bytef *) &(IceImage.data[0]), (uLong)source_len);

    if(r != Z_OK)
    {
        std::cerr << "Error decompressing" << std::endl;
        return;
    }

    else
    {

        cv::Mat image = cv::Mat(cvSize(IceImage.rows,IceImage.cols), IceImage.type, origin_buf);

        cv::imshow("Image window", image);
        cv::waitKey(3);


    }


    if (origin_buf)
        free(origin_buf);


}

