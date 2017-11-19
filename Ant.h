#ifndef LANGTON_ANT_H
#define LANGTON_ANT_H

#include <random>
#include <memory>

#include "Util/Coords.h"
#include "Field.h"

// Set as regular enum instead of enum class so some trickery
// can be undertaken when rotating
enum AntDirection {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
};

class Ant {
private:

    Coords m_ant_coords;

    AntDirection m_direction;

    // Gets the block the Ant is standing on
    TileState get_block_on(std::shared_ptr<Field> field);

public:

    // Potential SEGFAULT here

    Ant(Coords coords);


    Coords get_coords() const {
        return m_ant_coords;
    }

    void rotate_left();

    void rotate_right();

    // Moves the ant forward one unit based on its direction
    void move(int width, int height);
};

#endif //LANGTON_ANT_H
