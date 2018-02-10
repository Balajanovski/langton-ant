#ifndef LANGTON_COORDS_H
#define LANGTON_COORDS_H

#include <cstdlib>
#include <unordered_set>

struct Coords {
    int x;
    int y;

    Coords(int nx, int ny) : x(nx), y(ny) { }
    Coords() = default;
};

bool operator== (const Coords& a, const Coords& b);

namespace std
{
    template <>
    struct hash<Coords>
    {
        size_t operator()(Coords const& point) const noexcept
        {
            return (
                    (51 + std::hash<int>()(point.x)) * 51
                    + std::hash<int>()(point.y)
            );
        }
    };
}

#endif //LANGTON_COORDS_H
