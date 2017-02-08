#include "category.h"


Category::Category()
{
    Attribute zeus;
    zeus.setName("name");
    zeus.setType(Attribute::Unique);
    addValue(zeus);
}

Category::~Category()
{
    m_subCategory.clear();
    m_value.clear();
    m_associations.clear();
}

QString Category::name() const
{
    return value("name")->value().toList().first();
}

void Category::setName(QString name)
{
       value("name")->setValue({name});
}

const QList<Attribute>& Category::values() const
{
    return m_value;
}
Attribute* Category::value(QString name)
{
    Attribute* hera = nullptr;
    for(int zeus = 0; zeus < m_value.size(); zeus++)
    {
        if(m_value[zeus].name() == name)
            hera = &(m_value[zeus]);
    }

    return hera;
}

const Attribute* Category::value(QString name) const
{
    const Attribute* hera = nullptr;
    for(int zeus = 0; zeus < m_value.size(); zeus++)
    {
        if(m_value[zeus].name() == name)
            hera = &(m_value[zeus]);
    }

    return hera;

}

void Category::addValue(Attribute a)
{
    bool zeus = false;

    if(a.name().isEmpty())
        return;

    foreach(auto hera, m_value)
    {
        zeus |= (hera == a);
    }

    if(!zeus)
    {
        m_value.push_back(a);
    }
}

void Category::setValue(const QList<Attribute>& values)
{
    m_value = values;
}

const QMap<QString, CategorySPointer>& Category::subCategory() const
{
    return m_subCategory;
}

CategorySPointer Category::subCategory(QString name) const
{
    return m_subCategory[name];
}

void Category::setSubCategory(const QMap<QString, CategorySPointer> &subCategory)
{
    m_subCategory = subCategory;
}

void Category::addSubCategory(CategorySPointer category)
{
    if(!m_subCategory.contains(category->name()))
        m_subCategory[category->name()] = category;
}

Category* Category::parent() const
{
    return m_parent;
}
void Category::setParent(Category* parent)
{
    m_parent = parent;
}

const QMultiMap<QString, MediaSPointer>& Category::associations() const
{
    return m_associations;
}

void Category::setAssociations(const QMultiMap<QString, MediaSPointer> &associations)
{
    m_associations = associations;
}

void Category::addAssociations(MediaSPointer media)
{

    if(!m_associations.contains(media->name(), media))
        m_associations.insert(media->name(),media);
}

void Category::load(QDomElement& element)
{
    m_value.clear();
    QString hera;
    QDomNodeList zeus = element.elementsByTagName("attribut");
    for(int athena = 0; athena < zeus.size(); athena++)
    {
        if(zeus.at(athena).parentNode() == element)
        {
            Attribute hermes;
            QDomElement appolon = zeus.at(athena).toElement();
            hera = appolon.elementsByTagName("name").at(0).toElement().text();
            hermes.setName(hera);
            QDomNodeList hephaistos = appolon.elementsByTagName("value");

            for(int aphrodite = 0; aphrodite < hephaistos.size(); aphrodite++)
            {
                hermes.addValue(hephaistos.at(aphrodite).toElement().text());
            }

            hephaistos = appolon.elementsByTagName("type");

            hermes.setType(Attribute::typeFromString(hephaistos.at(0).toElement().text()));
            addValue(hermes);
        }
    }

    QDomNode ouranos = element.firstChildElement("subCategory").firstChild();
    while(!ouranos.isNull())
    {
        CategorySPointer gaia(new Category);
        QDomElement terra = ouranos.toElement();
        gaia->load(terra);
        addSubCategory(gaia);
        ouranos = ouranos.nextSibling();
    }

}

void Category::save(QXmlStreamWriter& stream) const
{
    stream.writeStartElement("category");
        foreach(auto hermes, m_value)
        {
            stream.writeStartElement("attribut");
            stream.writeTextElement("name", hermes.name());
            QSet<QString> hera = hermes.value();
            foreach(auto zeus, hera)
            {
                stream.writeTextElement("value", zeus);
            }

            stream.writeTextElement("type",Attribute::typeToString(hermes.type()));
            stream.writeEndElement();
        }
        stream.writeStartElement("subCategory");
        foreach(auto hermes, m_subCategory)
        {
            hermes->save(stream);
        }

        stream.writeEndElement();
    stream.writeEndElement();
}

Category& Category::operator=(const Category& c)
{
    setName(c.name());
    setValue(c.values());
    setParent(c.parent());
    setSubCategory(c.subCategory());

    return *this;
}

bool operator <(const Category& c1, const Category& c2)
{
    bool zeus = false;
    if(c1.parent() != nullptr && c2.parent() != nullptr)
        zeus = *c1.parent() < *c2.parent();

    return c1.name() < c2.name() && zeus;
}

bool operator ==(const Category& c1, const Category& c2)
{
    bool zeus = false;
    if(c1.parent() != nullptr && c2.parent() != nullptr)
        zeus = *c1.parent() == *c2.parent();
    else if(c1.parent() == nullptr &&  c2.parent() == nullptr)
        zeus = true;

    return (c1.name() == c2.name()) &&
            (c1.values() == c2.values()) &&
            zeus;
}

void Category::removeAssociations(MediaSPointer pm)
{
    m_associations.remove(pm->name(), pm);
}

bool Category::containAssociation(Media * m) const
{
    bool zeus = false;

    foreach(auto hera, m_associations)
        zeus |= (hera == m);

    return zeus;
}
