#ifndef EQUIVALENTEXPRESSION
#define EQUIVALENTEXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

class EXPRESSIONSHARED_EXPORT EquivalentExpression: public BinaryExpression<bool>
{
public:
    EquivalentExpression() = default;
    EquivalentExpression(const EquivalentExpression&) = default;
    ~EquivalentExpression() = default;

    bool evaluate() const override;
    EquivalentExpression* clone() const override;
};
#endif // EQUIVALENTEXPRESSION

