#include <iostream>
#include <set>
#include <memory>

#include "Field.h"
#include "Application.h"

int main(int argc, char *argv[]) {

    Application app(100, 100, 1);
    app.begin();

    //Field field(100, 100, std::make_shared< std::set<Coords> >() );
    //field.flip_tile({10, 10});
    //std::cout << field.get_field_width() << " " << field.get_field_height() << std::endl;



    return 0;
}
