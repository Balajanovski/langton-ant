// 
// Created by Balajanovski on 12/11/2017.
//

#include <memory>
#include <algorithm>
#include <stdexcept>
#include <utility>

#include "Field.h"

Field::Field(int width, int height, std::shared_ptr< std::unordered_set< Tile > > colored_tiles) :
        m_field_mem(height),
        m_width(width),
        m_height(height),
        m_colored_tiles(colored_tiles) {

    // Create "template" row of only background tiles to fill up the memory
    std::vector<TileDirection> white_row(width);
    std::fill_n(white_row.begin(), width, TileDirection::TURN_RIGHT);

    // Fill up the memory with background rows
    std::fill_n(m_field_mem.begin(), height, white_row);
}

void Field::flip_tile(const Tile& c) {


    switch(m_field_mem[c.pos.y][c.pos.x]) {
        case TileDirection::TURN_RIGHT:
        {
            m_colored_tiles->insert(c);
            m_field_mem[c.pos.y][c.pos.x] = TileDirection::TURN_LEFT;
        }
            break;
        case TileDirection::TURN_LEFT:
        {
            m_colored_tiles->erase(c);
            m_field_mem[c.pos.y][c.pos.x] = TileDirection::TURN_RIGHT;
        }
            break;
        default:
        {
            throw std::runtime_error("error: unaccounted for base case in flip_tile function");
        }
            break;
    }
}

TileDirection Field::get_tile(const Coords& c) const {
    return m_field_mem[c.y][c.x];
}

int Field::get_field_width() const {
    return m_width;
}

int Field::get_field_height() const {
    return m_height;
}