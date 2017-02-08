#include "equivalentexpression.h"

bool EquivalentExpression::evaluate() const
{
    return (e1()->evaluate() && e2()->evaluate()) || !(e1()->evaluate() || e2()->evaluate());
}

EquivalentExpression* EquivalentExpression::clone() const
{
    return new EquivalentExpression(*this);
}
