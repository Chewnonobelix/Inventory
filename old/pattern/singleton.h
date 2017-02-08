#ifndef SINGLETON_H
#define SINGLETON_H

#include "pattern_global.h"
#include <QDebug>

/*Les classes dérivant la l'interface Singleton doivent avoir TOUS leurs constructeurs privé */
template<class S>
class PATTERNSHARED_EXPORT Singleton
{
private:
    static S* m_sing;

public:
    static S* get()
    {
        if(m_sing == NULL)
        {
            m_sing = new S();
        }

        return m_sing;
    }

    static void kill()
    {
        delete m_sing;
        m_sing = NULL;
    }
};

template<class S>S* Singleton<S>::m_sing = NULL;


/*
Exemple: 

La déclaration d'amitié permet à singleton de pouvoir instancié l'objet
class Exemple:public Singleton<Exemple>
{
	friend class Singleton<Exemple>;
	
private:
	Exemple();
	Exemple(const Exemple&);
	~Exemple();
}; */
#endif // SINGLETON_H
