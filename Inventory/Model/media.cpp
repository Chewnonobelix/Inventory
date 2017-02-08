#include "media.h"
#include "category.h"


Media::Media(): m_category(nullptr)
{
    m_attributes["name"] = QString();
}

Media::~Media()
{
    m_attributes.clear();
    m_subMedia.clear();
}

QString Media::name() const
{
    return m_attributes["name"];
}

void Media::setName(QString name)
{
    MediaSPointer hera;
    bool zeus = (category() != nullptr && category()->containAssociation(this));
    if(zeus)
    {
        hera = *this;
        category()->removeAssociations(hera);
    }

    m_attributes["name"] = name;

    if(zeus)
          category()->addAssociations(hera);
}

Category *Media::category() const
{
    return m_category;
}

void Media::setCategory(Category* category)
{
    m_category = category;
}

QMap<QString, QString> Media::attributes() const
{
    return m_attributes;
}

QString Media::attribute(QString aname) const
{
    return attributes()[aname];
}

void Media::setAttributes(const QMap<QString, QString> &attributes)
{
    m_attributes = attributes;
}

bool Media::addAttribute(QString aname, QString avalue)
{
    if(!attributes().contains(aname))
    {
        m_attributes[aname] = avalue;
        return true;
    }
    return false;
}

const QMap<QString, MediaSPointer>& Media::subMedias() const
{
    return m_subMedia;
}

MediaSPointer Media::subMedia(QString name) const
{
    return m_subMedia[name];
}

void Media::setSubMedia(QMap<QString, MediaSPointer> sub)
{
    m_subMedia = sub;
}

void Media::addSubMedia(MediaSPointer m)
{
    if(!m_subMedia.contains(m->name()))
        m_subMedia[m->name()] = m;
}

void Media::save(QXmlStreamWriter & stream) const
{
    stream.writeStartElement("entry");
       stream.writeTextElement("categoryRef", category()->name());
       QStringList athena = attributes().keys();
       foreach(auto hermes, athena)
       {
           stream.writeStartElement("attribute");
           stream.writeAttribute("aname", hermes);
           stream.writeCharacters(attribute(hermes));
           stream.writeEndElement();
       }

       stream.writeStartElement("subMedia");
       foreach(auto hermes, subMedias())
       {
           hermes->save(stream);
       }

       stream.writeEndElement();
    stream.writeEndElement();
}

void Media::load(QDomElement & element, const QMap<QString, CategorySPointer> & cat)
{
    QString hera = element.elementsByTagName("categoryRef").at(0).toElement().text();
    CategorySPointer ares = cat[hera];

    setCategory(ares.data());
    QDomNodeList hermes = element.elementsByTagName("attribute");

    for(int zeus = 0; zeus < hermes.size(); zeus++)
    {
        QString athena;
        if(hermes.at(zeus).parentNode().toElement() == element)
        {
            hera = hermes.at(zeus).toElement().attribute("aname");
            athena = hermes.at(zeus).toElement().text();

            if(hera == "name")
                setName(athena);
            else
                addAttribute(hera, athena);
        }
    }
    category()->addAssociations(*this);
    QDomNode hades = element.firstChildElement("subMedia").firstChild();

    while(!hades.isNull())
    {
        MediaSPointer artemis(new Media);
        QDomElement demeter = hades.toElement();
        artemis->load(demeter, category()->subCategory());
        m_subMedia[artemis->name()] = artemis;
        hades = hades.nextSibling();
    }
}

Media& Media::operator= (const Media& media)
{
    setName(media.name());
    setAttributes(media.attributes());
    setCategory(media.category());
    setSubMedia(media.subMedias());

    return *this;
}

bool operator==(const Media& m1, const Media& m2)
{
    return m1.name() == m2.name() &&
            m1.category() == m2.category() &&
            m1.attributes() == m2.attributes() &&
            m1.subMedias() == m2.subMedias();
}

bool operator < (const Media& m1, const Media& m2)
{
    return m1.name() < m2.name() && m1.category() < m2.category();
}

bool Media::validate() const
{
    bool chronos = (m_attributes.size() == category()->values().size());

    for(auto zeus = m_attributes.begin(); zeus != m_attributes.end(); zeus++)
    {
        Attribute* typhon = category()->value(zeus.key());
        if(typhon == nullptr)
        {
            chronos = false;
        }
        else
        {
            Attribute::AttributeType ouranos = typhon->type();
            chronos &= (typhon->name() == zeus.key() && (ouranos != Attribute::Multi || typhon->asValue(zeus.value())));
        }
    }

    foreach(auto zeus, m_subMedia)
        chronos &= zeus->validate();

    return chronos;
}

void Media::removeSub(QString category)
{
    QStack<MediaSPointer> artemis;

    foreach(auto demeter, m_subMedia)
        if(demeter->category()->name() == category)
            artemis.push(demeter);

    while(!artemis.isEmpty())
    {
        MediaSPointer hermes = artemis.pop();
        m_subMedia.remove(hermes->name());
    }
}
