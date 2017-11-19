// 
// Created by Balajanovski on 12/11/2017.
//

#ifndef LANGTON_RANDOMNUMBERGEN_H
#define LANGTON_RANDOMNUMBERGEN_H

#include <random>

namespace {
    std::mt19937 gen;
    bool gen_initalised = false;
}

namespace RandomNumberGen {
    int rng(int lower_bound, int upper_bound);
};





#endif //LANGTON_RANDOMNUMBERGEN_H
