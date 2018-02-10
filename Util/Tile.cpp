// 
// Created by Balajanovski on 10/02/2018.
//

#include "Tile.h"

bool operator== (const Tile& a, const Tile& b) {
    return (a.pos == b.pos) && (a.color == b.color);
}