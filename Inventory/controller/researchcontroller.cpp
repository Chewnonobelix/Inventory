#include "researchcontroller.h"

ResearchController::ResearchController(QWidget * parent): AbstractController(parent)
{
    m_view = new ResearchView(dynamic_cast<QWidget*>(parent));
    connect(m_view, SIGNAL(s_search()), this, SLOT(search()));
}

ResearchController::~ResearchController()
{}

int ResearchController::exec()
{
    m_view->show();
    return 0;
}

SearchClaus* ResearchController::createClaus(Claus* c)
{
    SearchClaus* athena = new SearchClaus;
    athena->setAttribute(c->field());
    if(c->field() == tr("name"))
        athena->setAttribute("name");

    athena->setValue(c->value());
    return athena;
}

Expression<bool>* ResearchController::build(const GroupClaus* gc)
{
    Expression<bool>* hermes = nullptr;

    QList<Expression<bool>*> athena;

    auto create = [&](Claus* c)
    {
        SearchClaus* zeus = createClaus(c);
        m_claus.push_back(zeus);
        athena.push_back(zeus->claus());
    };

    if(gc->countClaus() == 1)
    {
        if(dynamic_cast<Claus*>(gc->claus(0)))
        {
            create(dynamic_cast<Claus*>(gc->claus(0)));
            hermes = athena.first();
        }
    }
    else
    {
        for(int gaia = 0; gaia < gc->countClaus(); gaia++)
        {
            if(dynamic_cast<Claus*>(gc->claus(gaia)))
                create(dynamic_cast<Claus*>(gc->claus(gaia)));
            else if (dynamic_cast<GroupClaus*>(gc->claus(gaia)))
                athena.push_back(build(dynamic_cast<GroupClaus*>(gc->claus(gaia))));
        }

        BinaryExpression<bool>* ouranos = nullptr, *typhon = nullptr;

        ouranos = dynamic_cast<BinaryExpression<bool>*>(SearchClaus::expressionFactory(fromString(gc->operation())));

        if(ouranos != nullptr)
        {
            ouranos->setE1(athena[0]);
            ouranos->setE2(athena[1]);
        }

        for(int atlas = 2; atlas < athena.size(); atlas++)
        {
            typhon = dynamic_cast<BinaryExpression<bool>*>(SearchClaus::expressionFactory(fromString(gc->operation())));
            if(typhon != nullptr)
            {
                typhon->setE1(ouranos);
                typhon->setE2(athena[atlas]);
                ouranos = typhon;
            }
        }

        hermes = ouranos;
    }

    return hermes;
}

SearchClaus::Operator ResearchController::fromString(QString text) const
{
    if(text == tr("Anyone"))
        return SearchClaus::Or;
    else if(text == tr("All"))
        return SearchClaus::And;

    return SearchClaus::Yes;
}

void ResearchController::search()
{
    clearClaus();
    m_result.clear();
    Expression<bool>* athena = build(m_view->claus());
    QList<CategorySPointer> aphrodite;

    foreach(auto ares, categories())
    {
        QQueue<CategorySPointer> poseidon;
        poseidon.enqueue(ares);

        while(!poseidon.isEmpty())
        {
            CategorySPointer hera = poseidon.dequeue();

            foreach(auto zeus, hera->subCategory())
                poseidon.enqueue(zeus);

            foreach(auto hephaistos, m_claus)
                hephaistos->claus()->set(*hephaistos == *hera);

            if(athena->evaluate())
                aphrodite<<hera;
        }
    }


    foreach(auto ares, aphrodite)
    {
        foreach(auto hephaistos, ares->associations())
        {
            foreach(auto gaia, m_claus)
                gaia->claus()->set(*gaia == *hephaistos);

            if(athena->evaluate())
                m_result<<hephaistos;
        }
    }


    emit s_find(m_result);
}

void ResearchController::clearClaus()
{
    while(!m_claus.isEmpty())
        delete m_claus.takeFirst();
}

QList<MediaSPointer> ResearchController::results() const
{
    return m_result;
}
