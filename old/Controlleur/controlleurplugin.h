#ifndef CONTROLLEURPLUGIN_H
#define CONTROLLEURPLUGIN_H

#include "abstractcontrolleur.h"
#include "controlleur_global.h"
#include "InterfacePlugin.h"

class CONTROLLEURSHARED_EXPORT AbstractControlleurPlugin : public AbstractControlleur
{
    Q_OBJECT

private:
    AbstractMedia* m_courant;
    InterfacePlugin* m_plugin;

protected:
    QDialog* m_vue;

public:
    explicit AbstractControlleurPlugin(QString nom, InterfacePlugin* plugin, QObject* parent = 0): AbstractControlleur(parent)
    {
        m_plugin = plugin;

        if(!getModel(m_plugin->getNomAffichage()).contains(nom))
        {
            throw m_plugin->getNomAffichage() + " inexistant " + nom;
        }

        m_courant = getModel(m_plugin->getNomAffichage())[nom];

    }

    ~AbstractControlleurPlugin()
    {
        delete m_vue;
    }

    virtual void setVue() = 0;
    QDialog* getVue() const;
    InterfacePlugin* getPlugin() const;
    virtual QStringList getListeSort() const = 0;
    void exec();

    AbstractMedia *courant() const;
    void setCourant(AbstractMedia *);
};

#endif // CONTROLLEURPLUGIN_H
