

module Message
{

sequence<byte> ImageSeq;

struct ImageData
{
  int rows;
  int cols;
  int type;
  ImageSeq data;
};


interface ImageContainer
{
    void publishImage(ImageData m);
};

};
