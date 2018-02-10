#include "Drawer.h"
#include "Util/Coords.h"
#include "Util/RGB.h"
#include "ConfigManager.h"

#include <string>
#include <stdexcept>
#include <utility>

Drawer::Drawer(int field_width, int field_height, int cell_size, std::shared_ptr< std::unordered_set< Tile > > colored_tiles)
        : SdlHandle(SDL_INIT_EVERYTHING),
          width(field_width),
          height(field_height),
          m_cell_size(cell_size),
          m_colored_tiles(colored_tiles)
{

    window.reset(SDL_CreateWindow("Langton's Ant", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, field_width * m_cell_size, field_height * m_cell_size, SDL_WINDOW_SHOWN));
    if (!window) {
        throwSdlError("unable to create window");
    }

    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
    if (!renderer) {
        throwSdlError("unable to create renderer");
    }
}

void Drawer::flush() {
    auto background_color = ConfigManager::instance().get_background_color();

    // Draw background
    SDL_SetRenderDrawColor(renderer.get(), background_color.r, background_color.g, background_color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer.get());

    // Draw the cells from the buffer
    SDL_Rect draw_dst;
    draw_dst.w = draw_dst.h = m_cell_size;

    if (m_colored_tiles != nullptr) {
        for (const auto& tile : *m_colored_tiles) {
            SDL_SetRenderDrawColor(renderer.get(),
                                   tile.color.r,
                                   tile.color.g,
                                   tile.color.b,
                                   SDL_ALPHA_OPAQUE);

            draw_dst.x = tile.pos.x * m_cell_size;
            draw_dst.y = tile.pos.y * m_cell_size;

            SDL_RenderFillRect(renderer.get(), &draw_dst);
        }
    }

    if (m_cell_size >= 7) {
        draw_grid();
    }

    SDL_RenderPresent(renderer.get());

}


void Drawer::draw_grid() {
    SDL_Rect draw_dst;

    SDL_SetRenderDrawColor(renderer.get(), 125, 125, 125, SDL_ALPHA_OPAQUE);
    draw_dst.x = draw_dst.y = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            draw_dst.x = x * m_cell_size;
            draw_dst.y = y * m_cell_size;

            SDL_RenderDrawRect(renderer.get(), &draw_dst);
        }
    }
}