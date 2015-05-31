#ifndef IMAGECONTAINERI_H
#define IMAGECONTAINERI_H

#include <Image.h>
#include <cstdlib>
#include <zlib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

class ImageContainerI : public Message::ImageContainer
{
public:

    ImageContainerI();
    ~ImageContainerI();
    virtual void publishImage(const Message::ImageData &, const Ice::Current&);
};

#endif // IMAGECONTAINERI_H
