#ifndef MINUSEXPRESSION
#define MINUSEXPRESSION

#include "binaryexpression.h"

template<class T>
class MinusExpression: public BinaryExpression<T>
{
public:
    MinusExpression() = default;
    MinusExpression(const MinusExpression<T>&) = default;
    ~MinusExpression() = default;

    T evaluate() const
    {
        return this->e1()->evaluate() - this->e2()->evaluate();
    }

    MinusExpression<T>* clone() const
    {
        return new MinusExpression<T>(*this);
    }
};

#endif // MINUSEXPRESSION

