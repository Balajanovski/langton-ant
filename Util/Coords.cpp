// 
// Created by Balajanovski on 10/02/2018.
//

#include "Coords.h"

bool operator== (const Coords& a, const Coords& b) {
    return (a.x == b.x) && (a.y == b.y);
}
