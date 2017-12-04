// 
// Created by Balajanovski on 2/12/2017.
//

#include "Util/RGB.h"
#include "ConfigManager.h"

#include <stdexcept>
#include <iostream>
#include <string>
#include "Util/RandomNumberGen.h"

ConfigManager& ConfigManager::instance() {

    static ConfigManager instance;
    return instance;
}

void ConfigManager::load_file(const std::string& config_path) {
    m_config_path = config_path;
    m_config = YAML::LoadFile(m_config_path);

    m_width = m_config["width"].as<int>();
    m_height = m_config["height"].as<int>();
    m_cell_size = m_config["cell-size"].as<int>();
    m_ant_number = m_config["ant-number"].as<int>();
    m_background_color = m_config["background-color"].as<RGB>();
    m_machine_generated_colors = m_config["machine-generated-colors"].as<bool>();

    if (!m_machine_generated_colors) {
        auto unprocessed_custom_colors = m_config["ant-colors"];
        for (int i = 0; i < unprocessed_custom_colors.size(); ++i)
        {
            auto unprocessed_color = (unprocessed_custom_colors[i])["color"];

            if (unprocessed_color.IsMap()) {
                auto color = unprocessed_color.as<RGB>();
                m_tile_colors.push_back(color);
            }
            else if (unprocessed_color.IsDefined() && unprocessed_color.as<std::string>() == "random") {
                auto color = RGB{static_cast<unsigned char>(RandomNumberGen::rng(0, 255)),
                                 static_cast<unsigned char>(RandomNumberGen::rng(0, 255)),
                                 static_cast<unsigned char>(RandomNumberGen::rng(0, 255))};

                m_tile_colors.push_back(color);
            }
        }
    }

    m_config_loaded = true;
}

void ConfigManager::validate_field_access(const std::string& field) const {
    if (!m_config_loaded) {
        throw std::runtime_error("error: field " + field + " of ConfigManager accessed before file was loaded");
    }
}

std::vector<RGB> ConfigManager::get_custom_colors() const {
    if (m_machine_generated_colors) {
        throw std::runtime_error("error: attempted access of custom colors when machine generated colors flag is enabled");
    }

    return m_tile_colors;
}