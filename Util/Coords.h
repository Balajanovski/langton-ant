#ifndef LANGTON_COORDS_H
#define LANGTON_COORDS_H

struct Coords {
    int x;
    int y;

    Coords(int nx, int ny) : x(nx), y(ny) { }
    Coords() = default;
};

bool operator<(const Coords& a, const Coords& b);

#endif //LANGTON_COORDS_H
