#ifndef LANGTON_DRAWER_H
#define LANGTON_DRAWER_H

#include "Util/GetSDL.h"

#include "Util/Cleanup.h"
#include "Util/Coords.h"

#include <set>
#include <memory>

// Size in pixels of a cell
constexpr static int CELL_SIZE = 10;
constexpr static int LINE_WIDTH = 1;

class Drawer : private SdlHandle {
public:
    Drawer(int x, int y, std::shared_ptr< std::set<Coords> > black_tiles);

    void flush();
private:
    int width,
        height;

    SdlWinPtr window;
    SdlRenPtr renderer;

    std::shared_ptr< std::set<Coords> > m_black_tiles;
};


#endif //LANGTON_DRAWER_H
