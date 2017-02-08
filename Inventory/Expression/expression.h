#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QSharedPointer>

template<class T>
class Expression;

template<class T>
class Expression
{
private:

public:
    Expression() = default;

    Expression(const Expression<T>&) = default;

    virtual ~Expression() = default;

    Expression<T>& operator=(const Expression<T>&)
    {
        return *this;
    }

    virtual T evaluate() const = 0;
    virtual Expression<T>* clone() const = 0;
};

#endif // EXPRESSION_H
