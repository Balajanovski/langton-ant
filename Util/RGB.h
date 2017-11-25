// 
// Created by Balajanovski on 25/11/2017.
//

#ifndef LANGTON_RGB_H
#define LANGTON_RGB_H

struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

bool operator<(const RGB& a, const RGB& b);

#endif //LANGTON_RGB_H
