// 
// Created by Balajanovski on 12/11/2017.
//

#ifndef LANGTON_FIELD_H
#define LANGTON_FIELD_H

#include <vector>
#include <unordered_set>
#include <memory>
#include <utility>

#include "Util/Coords.h"
#include "Util/TileDirection.h"
#include "Util/RGB.h"
#include "Util/Tile.h"

class Field {
private:
    int m_width,
        m_height;

    // The memory representing the tiles of the field
    std::vector< std::vector<TileDirection> > m_field_mem;

    // A set representing all colored tiles to make lookup more efficient
    std::shared_ptr< std::unordered_set< Tile > > m_colored_tiles;

public:

    Field(int width, int height, std::shared_ptr< std::unordered_set< Tile > > colored_tiles);

    void flip_tile(const Tile& c);

    TileDirection get_tile(const Coords& c) const;

    // Setters and getters
    int get_field_width() const;
    int get_field_height() const;
};


#endif //LANGTON_FIELD_H
