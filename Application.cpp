// 
// Created by Balajanovski on 18/11/2017.
//

#include "Util/GetSDL.h"

#include "Application.h"

Application::Application(int width, int height, int ant_number) : m_drawer(width, height, m_black_tiles),
                                                                  m_field(std::make_shared<Field>(width, height, m_black_tiles)),
                                                                  m_black_tiles(std::make_shared< std::set<Coords> >())
{
    m_manager = AntManager(m_field);
    m_manager.generate_ants(ant_number);
}

void Application::check_keyboard_events() {
    SDL_Event ev;

    while(SDL_PollEvent(&ev)) {
        if (ev.type == SDL_KEYDOWN) {
            switch(ev.key.keysym.sym) {
                case SDLK_ESCAPE: m_state = ApplicationState::STOPPED; break;
                case SDLK_SPACE:
                {
                    switch(m_state) {
                        case ApplicationState::PAUSED:
                            m_state = ApplicationState::RUNNING;
                            break;
                        case ApplicationState::RUNNING:
                            m_state = ApplicationState::PAUSED;
                            break;
                    }
                }
                    break;
            }
        }
        else if (ev.type == SDL_QUIT)
            m_state = ApplicationState::STOPPED;

    }
}

void Application::begin() {
    if (m_state != ApplicationState::STOPPED)
        return;

    m_state = ApplicationState::RUNNING;

    // Game loop
    int previous_time = SDL_GetTicks();
    int lag           = 0;
    while(m_state != ApplicationState::STOPPED) {
        int current_time = SDL_GetTicks();
        int elapsed = current_time - previous_time;
        previous_time = current_time;
        lag += elapsed;
        check_keyboard_events();


            while (lag >= MS_PER_UPDATE) {
                if (m_state == ApplicationState::RUNNING) {
                    m_manager.iterate();
                }
                lag -= MS_PER_UPDATE;
            }



        m_drawer.flush();
    }

}

void Application::end() {
    m_state = ApplicationState::STOPPED;
}