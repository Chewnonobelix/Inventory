#ifndef IMPLIESEXPRESSION
#define IMPLIESEXPRESSION

#include "expression_global.h"
#include "binaryexpression.h"

class EXPRESSIONSHARED_EXPORT ImpliesExpression: public BinaryExpression<bool>
{
public:
    ImpliesExpression() = default;
    ImpliesExpression(const ImpliesExpression&) = default;
    ~ImpliesExpression() = default;

    bool evaluate() const override;

    ImpliesExpression* clone() const override;
};
#endif // IMPLIESEXPRESSION

