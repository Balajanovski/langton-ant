// 
// Created by Balajanovski on 12/11/2017.
//

#ifndef LANGTON_ANTMANAGER_H
#define LANGTON_ANTMANAGER_H

#include "Field.h"
#include "Ant.h"

#include <thread>
#include <vector>
#include <memory>

class AntManager {
private:
    std::vector<Ant> m_ants;

    std::shared_ptr<Field> m_field;

    TileState get_block_on(const Ant& ant);

    void move_ant(Ant& ant);
public:
    AntManager(std::shared_ptr<Field> field);
    AntManager() = default;

    void generate_ants(int number);

    void iterate();

};


#endif //LANGTON_ANTMANAGER_H
