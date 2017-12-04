// 
// Created by Balajanovski on 2/12/2017.
//

#ifndef LANGTON_TILECOLOR_H
#define LANGTON_TILECOLOR_H

#include "RGB.h"

enum TileDirection {
    TURN_LEFT = 0,
    TURN_RIGHT = 1,
};

struct TileState : public RGB {
    TileDirection dir;

    TileState(unsigned char n_r, unsigned char n_g, unsigned char n_b, TileDirection n_dir) : RGB(RGB{n_r, n_g, n_b}), dir(n_dir) { }
    TileState() = default;
};

namespace YAML {
    template<>
    struct convert<TileState> {
        static YAML::Node encode(const TileState& rhs) {
            YAML::Node node;
            node["R"] = (rhs.r);
            node["G"] = (rhs.g);
            node["B"] = (rhs.b);
            node.push_back(static_cast<int>(rhs.dir));
            return node;
        }

        static bool decode(const Node& node, TileState& rhs) {
            if(!node.IsMap() || node.size() != 4) {
                return false;
            }

            rhs.r = node[0].as<int>();
            rhs.g = node[1].as<int>();
            rhs.b = node[2].as<int>();
            rhs.dir = static_cast<TileDirection>(node[3].as<int>());
            return true;
        }
    };
}

#endif //LANGTON_TILECOLOR_H
