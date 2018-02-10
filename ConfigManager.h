// 
// Created by Balajanovski on 2/12/2017.
//

#ifndef LANGTON_CONFIGMANAGER_H
#define LANGTON_CONFIGMANAGER_H

#include <string>
#include <yaml-cpp/yaml.h>
#include <vector>
#include <memory>

#include "Util/TileDirection.h"
#include "Util/RGB.h"

class ConfigManager {
private:
    YAML::Node m_config;

    std::string m_config_path;

    bool m_config_loaded = false;

    void validate_field_access(const std::string& field) const;

    // These are the fields of the configuration file
    int m_width;
    int m_height;
    int m_cell_size;
    int m_ant_number;
    size_t m_thread_number;
    RGB m_background_color;
    bool m_machine_generated_colors;
    std::vector<RGB> m_tile_colors;

    ConfigManager() { }
public:


    ConfigManager(ConfigManager const&) = delete;
    void operator=(ConfigManager const&) = delete;

    void load_file(const std::string& config_path);

    static ConfigManager& instance();

    // Getters
    int get_width() const { validate_field_access("width"); return m_width; }
    int get_height() const { validate_field_access("height"); return m_height; }
    int get_cell_size() const { validate_field_access("cell size"); return m_cell_size; }
    int get_ant_number() const { validate_field_access("ant number"); return m_ant_number; }
    size_t get_thread_number() const { validate_field_access("thread number"); return m_thread_number; }
    RGB get_background_color() const { validate_field_access("background color"); return m_background_color; }
    bool are_colors_machine_generated() const { validate_field_access("colors machine generated"); return m_machine_generated_colors; }
    std::vector<RGB> get_custom_colors() const;
};


#endif //LANGTON_CONFIGMANAGER_H
