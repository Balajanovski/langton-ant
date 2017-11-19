// 
// Created by Balajanovski on 12/11/2017.
//

#include <memory>
#include <algorithm>
#include <stdexcept>

#include "Field.h"

Field::Field(int width, int height, std::shared_ptr< std::set<Coords> > black_tiles) : m_field_mem(height),
                                                                                       m_width(width),
                                                                                       m_height(height),
                                                                                       m_black_tiles(black_tiles) {
    // Create "template" row of only white tiles to fill up the memory
    std::vector<TileState> white_row(width);
    std::fill_n(white_row.begin(), width, TileState::WHITE);

    // Fill up the memory with white rows
    std::fill_n(m_field_mem.begin(), height, white_row);
}

void Field::flip_tile(const Coords& c) {
    switch(m_field_mem[c.y][c.x]) {
        case TileState::WHITE:
        {
            m_field_mem[c.y][c.x] = TileState::BLACK;
            m_black_tiles->insert(c);
        }
            break;
        case TileState::BLACK:
        {
            m_field_mem[c.y][c.x] = TileState::WHITE;
            m_black_tiles->erase(c);
        }
            break;
        default:
        {
            throw std::runtime_error("error: unaccounted for base case in flip_tile function");
        }
            break;
    }
}

TileState Field::get_tile(const Coords& c) const {
    return m_field_mem[c.y][c.x];
}

int Field::get_field_width() const {
    return m_width;
}

int Field::get_field_height() const {
    return m_height;
}