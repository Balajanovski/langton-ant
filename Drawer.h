#ifndef LANGTON_DRAWER_H
#define LANGTON_DRAWER_H

#include "Util/GetSDL.h"

#include "Util/Cleanup.h"
#include "Util/Coords.h"
#include "Util/RGB.h"

#include <set>
#include <memory>

// Width of grid lines
constexpr static int LINE_WIDTH = 1;

class Drawer : private SdlHandle {
public:
    Drawer(int x, int y, int cell_size, std::shared_ptr< std::set< std::pair<Coords, RGB> > > colored_tiles);

    void flush();
private:
    int width,
        height;

    SdlWinPtr window;
    SdlRenPtr renderer;

    std::shared_ptr< std::set<std::pair<Coords, RGB> > > m_colored_tiles;

    int m_cell_size;

    void draw_grid();
};


#endif //LANGTON_DRAWER_H
