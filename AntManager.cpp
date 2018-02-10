// 
// Created by Balajanovski on 12/11/2017.
//

#include <iostream>
#include <cmath>
#include <thread>

#include "Util/Tile.h"
#include "Util/RandomNumberGen.h"
#include "AntManager.h"
#include "ConfigManager.h"

std::mutex AntManager::m_mutex;

AntManager::AntManager(std::shared_ptr<Field> field) : m_field(field)
{
    m_thread_num = ConfigManager::instance().get_thread_number();
}

void AntManager::iterate() {
    std::vector<std::thread> threads;

    size_t partition_size = static_cast<size_t>(std::ceil(static_cast<float>(m_ants.size()) / m_thread_num));
    size_t num_ants = m_ants.size();
    for (int i = 0; i < num_ants; i += partition_size) {
        threads.push_back(std::thread(&AntManager::move_ants, this, i,
                                      ((i + partition_size) > num_ants) ? num_ants : (i + partition_size)));
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void AntManager::generate_ants(int number) {
    m_ants.reserve(number);

    for (int i = 0; i < number; ++i) {
        m_ants.push_back(Ant({RandomNumberGen::rng(0, m_field->get_field_width() - 1),
                              RandomNumberGen::rng(0, m_field->get_field_height() - 1)}));
    }
}

TileDirection AntManager::get_block_on(const Ant& ant) {
    return m_field->get_tile(ant.get_coords());
}

void AntManager::move_ant(Ant &ant) {
    auto block_on = get_block_on(ant);

    switch(block_on) {
        case TileDirection::TURN_RIGHT:
        {
            ant.rotate_right();

            m_mutex.lock();
            m_field->flip_tile(Tile{ant.get_coords(), ant.get_color()});
            m_mutex.unlock();

            ant.move(m_field->get_field_width(), m_field->get_field_height());
        }
            break;
        case TileDirection::TURN_LEFT:
        {
            ant.rotate_left();

            m_mutex.lock();
            m_field->flip_tile(Tile{ant.get_coords(), ant.get_color()});
            m_mutex.unlock();

            ant.move(m_field->get_field_width(), m_field->get_field_height());
        }
            break;
    }
}

void AntManager::move_ants(int start_index, int end_index) {
    for (int i = start_index; i < end_index; ++i) {
        move_ant(m_ants[i]);
    }
}


