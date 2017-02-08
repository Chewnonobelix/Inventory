#include "search.h"

Search::Search(QWidget *parent) :
    QWidget(parent)
{
}

Search::~Search()
{}

int Search::id() const
{
    return m_id;
}

void Search::setId(int id)
{
    m_id = id;
}

