// 
// Created by Balajanovski on 12/11/2017.
//

#include <iostream>
#include <utility>

#include "Util/Coords.h"
#include "Util/RandomNumberGen.h"
#include "AntManager.h"

AntManager::AntManager(std::shared_ptr<Field> field) : m_field(field) { }

void AntManager::iterate() {

    for (auto &a : m_ants) {
        move_ant(a);
    }
}

void AntManager::generate_ants(int number) {
    m_ants.reserve(number);

    for (int i = 0; i < number; ++i) {
        m_ants.push_back(Ant({RandomNumberGen::rng(0, m_field->get_field_width() - 1),
                              RandomNumberGen::rng(0, m_field->get_field_height() - 1)}));
    }
}

TileState AntManager::get_block_on(const Ant& ant) {
    return m_field->get_tile(ant.get_coords());
}

void AntManager::move_ant(Ant &ant) {
    auto block_on = get_block_on(ant);

    switch(block_on) {
        case TileState::WHITE:
        {
            ant.rotate_right();
            m_field->flip_tile(std::make_pair(ant.get_coords(), ant.get_color()));
            ant.move(m_field->get_field_width(), m_field->get_field_height());
        }
            break;
        case TileState::BLACK:
        {
            ant.rotate_left();
            m_field->flip_tile(std::make_pair(ant.get_coords(), ant.get_color()));
            ant.move(m_field->get_field_width(), m_field->get_field_height());
        }
            break;
    }
}


