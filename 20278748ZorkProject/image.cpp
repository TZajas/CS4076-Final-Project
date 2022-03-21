#include "image.h"

Image::Image(string img)
{
    this->image=img;
}

string Image::getImage(){
    return this->image;
}
