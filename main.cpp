#include <iostream>
#include <stdexcept>

#include "Field.h"
#include "Application.h"

int main(int argc, char *argv[]) {

    Application app("Config/config.yaml");
    app.begin();



    return 0;
}
