// 
// Created by Balajanovski on 25/11/2017.
//

#ifndef LANGTON_RGB_H
#define LANGTON_RGB_H

#include <yaml-cpp/node/node.h>

struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

bool operator<(const RGB& a, const RGB& b);

namespace YAML {
    template<>
    struct convert<RGB> {
        static YAML::Node encode(const RGB& rhs) {
            YAML::Node node;
            node["R"] = static_cast<int>(rhs.r);
            node["G"] = static_cast<int>(rhs.g);
            node["B"] = static_cast<int>(rhs.b);
            return node;
        }

        static bool decode(const Node& node, RGB& rhs) {
            if(!node.IsMap() || node.size() != 3) {
                return false;
            }

            rhs.r = node["R"].as<int>();
            rhs.g = node["G"].as<int>();
            rhs.b = node["B"].as<int>();
            return true;
        }
    };
}

#endif //LANGTON_RGB_H
