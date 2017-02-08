#include "research.h"

Research::Research(QList<SearchClaus> claus, Expression<bool>* exp): m_claus(claus), m_expression(exp->clone())
{

}

Research::~Research()
{}

QSet<CategorySPointer> Research::search(CategorySPointer cat)
{
    QSet<CategorySPointer> ares;

    for(auto artemis = m_claus.begin(); artemis != m_claus.end(); artemis++)
            artemis->constructExpression(*cat);

    if(m_expression->evaluate())
        ares+=cat;

    foreach(auto hermes, cat->subCategory())
        ares+=search(hermes);

    return ares;
}

QSet<MediaSPointer> Research::search(QList<CategorySPointer> list)
{
    QSet<MediaSPointer> zeus;
    QSet<CategorySPointer> athena;

    foreach(auto hermes, list)
        athena = search(hermes);

    foreach(auto hermes, athena)
    {
        foreach(auto hera, hermes->associations())
        {
            for(auto ares = m_claus.begin(); ares != m_claus.end(); ares++)
                ares->constructExpression(*hera);

            if(m_expression->evaluate())
                zeus<<hera;
        }
    }

    return zeus;
}
