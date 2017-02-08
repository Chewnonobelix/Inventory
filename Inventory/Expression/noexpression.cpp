#include "noexpression.h"

bool NoExpression::evaluate() const
{
    return !e()->evaluate();
}

NoExpression* NoExpression::clone() const
{
    return new NoExpression(*this);
}
