#ifndef RESEARCH_H
#define RESEARCH_H

#include <QList>
#include <QPair>
#include <QStringList>

#include "model_global.h"
#include "category.h"
#include "media.h"
#include "searchclaus.h"

class MODELSHARED_EXPORT Research
{
private:
    QList<SearchClaus> m_claus;
    Expression<bool>* m_expression;

    QSet<CategorySPointer> search(CategorySPointer);
public:
    Research(QList<SearchClaus>, Expression<bool>*);
    ~Research();
    QSet<MediaSPointer> search(QList<CategorySPointer>);
};

#endif // RESEARCH_H
