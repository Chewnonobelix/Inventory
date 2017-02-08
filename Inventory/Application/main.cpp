#include <QApplication>
#include <QDebug>
#include <QVariant>
#include <assert.h>

#include "maincontroller.h"

#include "constantexpression.h"
#include "multiplicationexpression.h"
#include "additionexpression.h"
#include "minusexpression.h"
#include "divisionexpression.h"
#include "impliedexpression.h"
#include "equivalentexpression.h"

/*
 * TODO V2
 * */

bool testExpressionBool();
bool testExpressionArith();
bool testExpressionCopy();
bool testExpressionComplexe();

int main(int argc, char *argv[])
{
    assert(testExpressionCopy());
    qDebug()<<"Expression copy ok";
    assert(testExpressionBool());
    qDebug()<<"Expression bool ok";
    assert(testExpressionArith());
    qDebug()<<"Expression arithmetique ok";
    assert(testExpressionComplexe());


    qDebug()<<"Expression complexe ok";

    QApplication a(argc, argv);

    MainController c;
    c.exec();
    return a.exec();
}

bool testExpressionBool()
{
    OrExpression o1, o2, o3, o4;
    AndExpression a1, a2, a3, a4;
    ImpliesExpression i1, i2, i3, i4;
    EquivalentExpression e1, e2, e3, e4;
    NoExpression n1, n2;

    ConstantExpression<bool> v1(false), v2(true);
    o1.setE1(v1.clone()); o1.setE2(v1.clone());
    o2.setE1(v1.clone()); o2.setE2(v2.clone());
    o3.setE1(v2.clone()); o3.setE2(v1.clone());
    o4.setE1(v2.clone()); o4.setE2(v2.clone());
    a1.setE1(v1.clone()); a1.setE2(v1.clone());
    a2.setE1(v1.clone()); a2.setE2(v2.clone());
    a3.setE1(v2.clone()); a3.setE2(v1.clone());
    a4.setE1(v2.clone()); a4.setE2(v2.clone());
    i1.setE1(v1.clone()); i1.setE2(v1.clone());
    i2.setE1(v1.clone()); i2.setE2(v2.clone());
    i3.setE1(v2.clone()); i3.setE2(v1.clone());
    i4.setE1(v2.clone()); i4.setE2(v2.clone());
    e1.setE1(v1.clone()); e1.setE2(v1.clone());
    e2.setE1(v1.clone()); e2.setE2(v2.clone());
    e3.setE1(v2.clone()); e3.setE2(v1.clone());
    e4.setE1(v2.clone()); e4.setE2(v2.clone());
    n1.setE(v1.clone());
    n2.setE(v2.clone());

    bool ret =  n1.evaluate() && !n2.evaluate();
    ret &= !o1.evaluate() && o2.evaluate() && o3.evaluate() && o4.evaluate();
    ret &= !a1.evaluate() && !a2.evaluate() && !a3.evaluate() && a4.evaluate();
    ret &= e1.evaluate() && !e2.evaluate() && !e3.evaluate() && e4.evaluate();
    ret &= i1.evaluate() && i2.evaluate() && !i3.evaluate() && i4.evaluate();

    return ret;
}

bool testExpressionArith()
{
    AdditionExpression<int> a1, a2, a3, a4;
    MultiplicationExpression<int> mu1, mu2, mu3, mu4;
    DivisionExpression<int> d1, d2, d3, d4;
    MinusExpression<int> mi1, mi2, mi3, mi4;

    ConstantExpression<int> v1(42), v2(7), v3(49), v4(36);

    a1.setE1(v1.clone()); a1.setE2(v2.clone());
    a2.setE1(v3.clone()); a2.setE2(v4.clone());
    a3.setE1(v1.clone()); a3.setE2(v4.clone());
    a4.setE1(v2.clone()); a4.setE2(v3.clone());
    d1.setE1(v1.clone()); d1.setE2(v2.clone());
    d2.setE1(v3.clone()); d2.setE2(v4.clone());
    d3.setE1(v1.clone()); d3.setE2(v4.clone());
    d4.setE1(v2.clone()); d4.setE2(v3.clone());
    mu1.setE1(v1.clone()); mu1.setE2(v2.clone());
    mu2.setE1(v3.clone()); mu2.setE2(v4.clone());
    mu3.setE1(v1.clone()); mu3.setE2(v4.clone());
    mu4.setE1(v2.clone()); mu4.setE2(v3.clone());
    mi1.setE1(v1.clone()); mi1.setE2(v2.clone());
    mi2.setE1(v3.clone()); mi2.setE2(v4.clone());
    mi3.setE1(v1.clone()); mi3.setE2(v4.clone());
    mi4.setE1(v2.clone()); mi4.setE2(v3.clone());

    bool ret = (a1.evaluate() == (v1.evaluate()+v2.evaluate())) && ( a2.evaluate() == (v3.evaluate()+v4.evaluate())) &&
            (a3.evaluate() == (v1.evaluate()+v4.evaluate())) && (a4.evaluate() == (v2.evaluate()+v3.evaluate()));
    return ret;
}

bool testExpressionCopy()
{
    ConstantExpression<int> v1(42);
    ConstantExpression<int> cv1(v1);
    MultiplicationExpression<int> me1;
    me1.setE1(v1.clone());
    me1.setE2(cv1.clone());
    MultiplicationExpression<int> cme1(me1);

    return (v1.evaluate() == cv1.evaluate()) &&
            (me1.e1() != cme1.e1()) && (me1.e2() != cme1.e2());
}

bool testExpressionComplexe()
{
    //mu1=(a1*mi1)=((v1+mi2)*(v2-v4))=((v1+(v3-v4))*(v2-v4))
    AdditionExpression<int> a1;
    MultiplicationExpression<int> mu1;
    MinusExpression<int> mi1, mi2;

    ConstantExpression<int> v1(42), v2(7), v3(49), v4(36);
    mi1.setE1(v2.clone()); mi1.setE2(v4.clone());
    mi2.setE1(v3.clone()); mi2.setE2(v4.clone());
    a1.setE1(v1.clone()); a1.setE2(mi2.clone());
    mu1.setE1(a1.clone()); mu1.setE2(mi1.clone());

    return (mu1.evaluate() == -1595);
}

