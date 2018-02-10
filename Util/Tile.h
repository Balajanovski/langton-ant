// 
// Created by Balajanovski on 10/02/2018.
//

#ifndef LANGTON_TILE_H
#define LANGTON_TILE_H

#include "Coords.h"
#include "RGB.h"

struct Tile {
    Coords pos;
    RGB color;
};

bool operator== (const Tile& a, const Tile& b);

namespace std
{
    template <>
    struct hash<Tile>
    {
        size_t operator()(Tile const& tile) const
        {
            return std::hash<Coords>()(tile.pos);
        }
    };
}

#endif //LANGTON_TILE_H
