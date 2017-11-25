// 
// Created by Balajanovski on 25/11/2017.
//

#include <tuple>

#include "RGB.h"

bool operator<(const RGB& a, const RGB& b) {
    return std::make_tuple(a.r, a.g, a.b) < std::make_tuple(b.r, b.g, b.b);
}