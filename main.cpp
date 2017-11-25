#include <iostream>
#include <stdexcept>

#include "Field.h"
#include "Application.h"

int main(int argc, char *argv[]) {

    if (argc < 5) {
        throw std::runtime_error("fatal error: not enough arguments input");
    }

    Application app(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    app.begin();



    return 0;
}
