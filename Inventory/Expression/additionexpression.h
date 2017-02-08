#ifndef ADDITIONEXPRESSION
#define ADDITIONEXPRESSION

#include "binaryexpression.h"

template<class T>
class AdditionExpression: public BinaryExpression<T>
{
public:
    AdditionExpression() = default;
    AdditionExpression(const AdditionExpression<T>&) = default;
    ~AdditionExpression() = default;

    T evaluate() const
    {
        return this->e1()->evaluate() + this->e2()->evaluate();
    }

    AdditionExpression<T>* clone() const
    {
        return new AdditionExpression<T>(*this);
    }
};

#endif // ADDITIONEXPRESSION

