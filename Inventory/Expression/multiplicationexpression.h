#ifndef MULTIPLICATIONEXPRESSION
#define MULTIPLICATIONEXPRESSION

#include "binaryexpression.h"

template<class T>
class MultiplicationExpression: public BinaryExpression<T>
{
public:
    MultiplicationExpression() = default;
    MultiplicationExpression(const MultiplicationExpression<T>&) = default;
    ~MultiplicationExpression() = default;

    T evaluate() const
    {
        return this->e1()->evaluate() * this->e2()->evaluate();
    }

    MultiplicationExpression<T>* clone() const
    {
        return new MultiplicationExpression<T>(*this);
    }
};

#endif // MULTIPLICATIONEXPRESSION

