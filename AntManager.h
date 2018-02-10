// 
// Created by Balajanovski on 12/11/2017.
//

#ifndef LANGTON_ANTMANAGER_H
#define LANGTON_ANTMANAGER_H

#include "Field.h"
#include "Ant.h"

#include <vector>
#include <memory>
#include <mutex>

class AntManager {
private:
    std::vector<Ant> m_ants;

    std::shared_ptr<Field> m_field;

    size_t m_thread_num;

    static std::mutex m_mutex;

    TileDirection get_block_on(const Ant& ant);

    void move_ants(int start_index, int end_index);
    void move_ant(Ant& ant);
public:
    AntManager(std::shared_ptr<Field> field);
    AntManager() = default;

    void generate_ants(int number);

    void iterate();

};


#endif //LANGTON_ANTMANAGER_H
