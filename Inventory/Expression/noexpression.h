#ifndef NOEXPRESSION
#define NOEXPRESSION

#include "expression_global.h"
#include "unaryexpression.h"

class EXPRESSIONSHARED_EXPORT NoExpression: public UnaryExpression<bool>
{
public:
    NoExpression() = default;
    NoExpression(const NoExpression&) = default;
    ~NoExpression() = default;

    NoExpression* clone() const override;

    bool evaluate() const override;
};

#endif // NOEXPRESSION

