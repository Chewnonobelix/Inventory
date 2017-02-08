#include "andexpression.h"

bool AndExpression::evaluate() const
{
    return e1()->evaluate() && e2()->evaluate();
}

AndExpression* AndExpression::clone() const
{
    return new AndExpression(*this);
}
