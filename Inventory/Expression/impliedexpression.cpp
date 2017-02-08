#include "impliedexpression.h"

bool ImpliesExpression::evaluate() const
{
    return !e1()->evaluate() || e2()->evaluate();
}

ImpliesExpression* ImpliesExpression::clone() const
{
    return new ImpliesExpression(*this);
}
