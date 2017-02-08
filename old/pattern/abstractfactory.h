#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "pattern_global.h"

template<class T>
class PATTERNSHARED_EXPORT AbstractFactory
{
    
public:
    virtual T* create() = 0;
};

#endif // ABSTRACTFACTORY_H
