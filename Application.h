// 
// Created by Balajanovski on 18/11/2017.
//

#ifndef LANGTON_APPLICATION_H
#define LANGTON_APPLICATION_H

#include <memory>
#include <set>

#include "AntManager.h"
#include "Field.h"
#include "Drawer.h"
#include "Util/Coords.h"
#include "Util/RGB.h"

enum class ApplicationState {
        PAUSED      = 0,
        RUNNING     = 1,
        STOPPED     = 2,
};

class Application {
private:
    static constexpr int MS_PER_UPDATE = 3;

    // A set of coords denoting turned on tiles on the field to make drawing quicker
    // This set is shared with
    // - Field class, which adds turned on tiles to the set, and removes turned off tiles
    // - Drawer class, which draws turned on tiles

    std::shared_ptr< std::set< std::pair<Coords, RGB> > > m_colored_tiles;

    AntManager m_manager;
    std::shared_ptr<Field> m_field;
    Drawer m_drawer;


    void check_keyboard_events();

    ApplicationState m_state = ApplicationState::STOPPED;


public:
    Application(int width, int height, int cell_size, int ant_number);

    void begin();
    void end();
};


#endif //LANGTON_APPLICATION_H
