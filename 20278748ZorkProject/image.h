#ifndef IMAGE_H
#define IMAGE_H
#include <string>
using namespace std;

class Image
{
public:
    Image(string img);
    string getImage();
private:
    string image;
};

#endif // IMAGE_H
