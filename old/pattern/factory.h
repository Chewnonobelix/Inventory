#ifndef FACTORY_H
#define FACTORY_H

#include "pattern_global.h"

template<class T>
class PATTERNSHARED_EXPORT Factory
{
public:
    static T* create()
    {
        return new T;
    }
};

#endif // FACTORY_H
