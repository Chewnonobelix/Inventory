#include "orexpression.h"

bool OrExpression::evaluate() const
{
    return e1()->evaluate() || e2()->evaluate();
}

OrExpression* OrExpression::clone() const
{
    return new OrExpression(*this);
}
