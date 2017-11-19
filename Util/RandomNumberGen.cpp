// 
// Created by Balajanovski on 12/11/2017.
//

#include "RandomNumberGen.h"

#include <iostream>

int RandomNumberGen::rng(int lower_bound, int upper_bound) {
    if (!gen_initalised) {
        gen = std::mt19937(std::random_device()());
        gen_initalised = true;
    }

    return std::uniform_int_distribution<std::mt19937::result_type>(lower_bound, upper_bound)(gen);
}