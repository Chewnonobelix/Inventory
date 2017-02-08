#ifndef DIVISIONEXPRESSION
#define DIVISIONEXPRESSION

#include "binaryexpression.h"

template<class T>
class DivisionExpression: public BinaryExpression<T>
{
public:
    DivisionExpression() = default;
    DivisionExpression(const DivisionExpression<T>&) = default;
    ~DivisionExpression() = default;

    T evaluate() const
    {
        return this->e1()->evaluate() / this->e2()->evaluate();
    }

    DivisionExpression<T>* clone() const
    {
        return new DivisionExpression<T>(*this);
    }
};

#endif // DIVISIONEXPRESSION

