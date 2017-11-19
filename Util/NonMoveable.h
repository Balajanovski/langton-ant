// 
// Created by Balajanovski on 18/11/2017.
//

#ifndef LANGTON_NONMOVEABLE_H
#define LANGTON_NONMOVEABLE_H

#include "NonCopyable.h"

struct NonMovable
{
    NonMovable() = default;
    NonMovable& operator = (NonCopyable&&) = delete;
    NonMovable(NonCopyable&&) = delete;
};

#endif //LANGTON_NONMOVEABLE_H
