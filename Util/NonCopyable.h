// 
// Created by Balajanovski on 18/11/2017.
//

#ifndef LANGTON_NONCOPYABLE_H
#define LANGTON_NONCOPYABLE_H

struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};

#endif //LANGTON_NONCOPYABLE_H
