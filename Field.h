// 
// Created by Balajanovski on 12/11/2017.
//

#ifndef LANGTON_FIELD_H
#define LANGTON_FIELD_H

#include <vector>
#include <set>
#include <memory>

#include "Util/Coords.h"

enum class TileState {
    WHITE = 0,
    BLACK = 1,
};

class Field {
private:
    int m_width,
        m_height;

    // The memory representing the tiles of the field
    std::vector< std::vector<TileState> > m_field_mem;

    // A set representing all black tiles to make lookup more efficient
    std::shared_ptr< std::set<Coords> > m_black_tiles;

public:

    Field(int width, int height, std::shared_ptr< std::set<Coords> > black_tiles);

    void flip_tile(const Coords& c);

    TileState get_tile(const Coords& c) const;

    // Setters and getters
    int get_field_width() const;
    int get_field_height() const;
};


#endif //LANGTON_FIELD_H
