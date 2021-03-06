#include "Ant.h"
#include "Field.h"
#include "Util/RandomNumberGen.h"
#include "ConfigManager.h"

TileDirection Ant::get_block_on(std::shared_ptr<Field> field) {
    return field->get_tile(m_ant_coords);
}

void Ant::rotate_left() {
    // Subtract one from the direction
    // Due to the definition of the enum this effectively turns it left
    m_direction = static_cast<AntDirection>(m_direction - 1);

    // If the direction is < 0, wrap it back around to be LEFT (which is 3)
    if (m_direction < 0) {
        m_direction = AntDirection::LEFT;
    }
}

void Ant::rotate_right() {
    // Add one to the direction
    // Due to the defintion of the enum this effectively turns it right
    m_direction = static_cast<AntDirection>(m_direction + 1);

    // If the direction is > 0, wrap it back around to be UP (which is 0)
    if (m_direction > 3) {
        m_direction = AntDirection::UP;
    }
}

void Ant::move(int width, int height) {
    switch(m_direction) {
        case AntDirection::UP :
        {
            m_ant_coords.y -= 1;
            if (m_ant_coords.y < 0) {
                m_ant_coords.y = height - 1;
            }
        }
            break;
        case AntDirection::DOWN :
        {
            m_ant_coords.y += 1;
            if (m_ant_coords.y >= height) {
                m_ant_coords.y = 0;
            }
        }
            break;
        case AntDirection::LEFT :
        {
            m_ant_coords.x -= 1;
            if (m_ant_coords.x < 0) {
                m_ant_coords.x = width - 1;
            }
        }
            break;
        case AntDirection::RIGHT :
        {
            m_ant_coords.x += 1;
            if (m_ant_coords.x >= width) {
                m_ant_coords.x = 0;
            }
        }
            break;
    }
}

Ant::Ant(const Coords& coords) : m_ant_coords(coords) {
    m_direction = static_cast<AntDirection>(RandomNumberGen::rng(0, 3));

    if (ConfigManager::instance().are_colors_machine_generated()) {
        set_color({static_cast<unsigned char>(RandomNumberGen::rng(0, 255)),
                   static_cast<unsigned char>(RandomNumberGen::rng(0, 255)),
                   static_cast<unsigned char>(RandomNumberGen::rng(0, 255))});
    }
    else {
        auto custom_colors = ConfigManager::instance().get_custom_colors();

        // Select a random color from custom colors
        set_color(custom_colors[RandomNumberGen::rng(0, custom_colors.size() - 1)]);
    }
}

void Ant::set_color(const RGB& color) {
    m_ant_color = color;
}
