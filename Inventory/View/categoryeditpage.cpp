#include "categoryeditpage.h"
#include "ui_categoryeditpage.h"

CategoryEditPage::CategoryEditPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryEditPage), m_root(nullptr)
{
    ui->setupUi(this);
    QScrollArea* gaia = new QScrollArea;
    gaia->setWidget(new QWidget);
    gaia->setWidgetResizable(true);
    ui->tabWidget->insertTab(0, gaia, tr("Parent"));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
    connect(ui->w_subCategory, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(showSub(QTreeWidgetItem*, int)));
    connect(ui->w_add, SIGNAL(clicked()), this, SLOT(addSub()));
    connect(ui->w_remove, SIGNAL(clicked()), this, SLOT(removeSub()));
    connect(ui->w_subCategory, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(textChanged(QTreeWidgetItem*, int)));

}

CategoryEditPage::~CategoryEditPage()
{
    delete ui;
    delete m_root;
}

void CategoryEditPage::set(CategorySPointer c)
{
    clearAttribute();
    m_root = constructSub(c);
    dynamic_cast<QScrollArea*>(ui->tabWidget->widget(0))->widget()->setLayout(m_root->data(1,0).value<SubCategory>().layout);
    ui->w_subCategory->addTopLevelItem(m_root);
    m_old = c->name();
    int hermes = InventoryView::maxDeep(m_root);

    ui->tabWidget->setTabText(0, c->name());
    for(int gaia = 1; gaia <= hermes; gaia++)
    {
        QScrollArea* artemis = new QScrollArea;
        artemis->setWidget(new QWidget);
        artemis->setWidgetResizable(false);
        ui->tabWidget->insertTab(gaia, artemis, "");
    }

    setWindowTitle(tr("View ") + c->name());
    ui->w_subCategory->setCurrentItem(m_root);
    ui->w_subCategory->expandAll();
}


void CategoryEditPage::clearAttribute()
{
    while(ui->w_subCategory->currentItem() != nullptr && !ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().list->isEmpty())
    {
        CategoryEdit* gaia = ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().list->takeFirst();
        ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().layout->removeWidget(gaia);
        delete gaia;
    }
}

void CategoryEditPage::updateIndex(QTreeWidgetItem* item)
{
    for(int hera = 0; hera < item->data(1,0).value<SubCategory>().list->size(); hera ++)
        item->data(1,0).value<SubCategory>().list->at(hera)->setId(hera);
}

void CategoryEditPage::accept()
{
    Category chronos = *prefixCheck(m_root);

    emit s_valide(chronos, m_old);
    close();
}

void CategoryEditPage::addAttribute(int id, QTreeWidgetItem* item)
{
    QTreeWidgetItem* hera;
    if(item == nullptr)
        hera = ui->w_subCategory->currentItem();
    else
        hera = item;

    CategoryEdit* zeus = new CategoryEdit(id+1);
    hera->data(1,0).value<SubCategory>().list->insert(id+1, zeus);
    hera->data(1,0).value<SubCategory>().layout->insertWidget(id+1, zeus);
    connect(zeus, SIGNAL(s_add(int)), this, SLOT(addAttribute(int)));
    connect(zeus, SIGNAL(s_remove(int)), this, SLOT(removeAttribute(int)));
    updateIndex(hera);
}

void CategoryEditPage::removeAttribute(int id)
{
    CategoryEdit* artemis = ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().list->at(id);
    ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().list->removeAt(id);
    ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().layout->removeWidget(artemis);
    delete artemis;
    updateIndex(ui->w_subCategory->currentItem());
    if(ui->w_subCategory->currentItem()->data(1,0).value<SubCategory>().list->size() == 0)
        addAttribute(-1);
}

void CategoryEditPage::showSub(QTreeWidgetItem* item, int)
{
    ui->tabWidget->removeTab(item->data(2,0).toInt());
    QScrollArea* gaia = new QScrollArea;
    gaia->setWidget(new QWidget);
    gaia->setWidgetResizable(true);
    gaia->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    gaia->widget()->setLayout(item->data(1,0).value<SubCategory>().layout);

    ui->tabWidget->insertTab(item->data(2,0).toInt(), gaia, tr("Parent"));


    ui->tabWidget->setCurrentIndex(item->data(2,0).toInt());

    ui->tabWidget->setTabText(item->data(2,0).toInt(), item->text(0));


    ui->w_subCategory->setCurrentItem(item);
    if(item->data(2,0).toInt() == 0)
        setWindowTitle(tr("View ")+ item->text(0));
}

QTreeWidgetItem* CategoryEditPage::constructSub(CategorySPointer cat, int i)
{
    QTreeWidgetItem* zeus = new QTreeWidgetItem;
    zeus->setFlags(zeus->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
    SubCategory hermes;
    hermes.category = cat;
    zeus->setData(1,0, QVariant::fromValue(hermes));
    zeus->setText(0, cat->name());
    for(int artemis = 0; artemis < cat->values().size(); artemis ++)
    {
        if(cat->values()[artemis].name() != "name")
        {
            CategoryEdit* chronos = new CategoryEdit(zeus->data(1,0).value<SubCategory>().list->size(), cat->values()[artemis]);
            zeus->data(1,0).value<SubCategory>().list->push_back(chronos);
            zeus->data(1,0).value<SubCategory>().layout->insertWidget(artemis, chronos);
            connect(chronos, SIGNAL(s_add(int)), this, SLOT(addAttribute(int)));
            connect(chronos, SIGNAL(s_remove(int)), this, SLOT(removeAttribute(int)));
        }

    }


    if(zeus->data(1,0).value<SubCategory>().list->size() == 0)
        addAttribute(-1, zeus);

    foreach(auto athena, cat->subCategory())
        zeus->addChild(constructSub(athena, i + 1));
    zeus->setData(2,0,QVariant(i));

    return zeus;
}

CategorySPointer CategoryEditPage::prefixCheck(QTreeWidgetItem* root)
{
    CategorySPointer zeus = root->data(1,0).value<SubCategory>().category;
    if(zeus == nullptr)
        zeus.reset(new Category);

    zeus->setName(root->text(0));
    QMap<QString, CategorySPointer> hera;

    for(int hermes = 0; hermes < root->childCount(); hermes++)
    {
        CategorySPointer athena = prefixCheck(root->child(hermes));
        hera[athena->name()] = athena;
    }
    zeus->setSubCategory(hera);
    QList<CategoryEdit*>& ares = *(root->data(1,0).value<SubCategory>().list);
    QList<Attribute> hades;
    hades.push_back(*(zeus->value("name")));
    foreach(auto gaia, ares)
    {
        Attribute ouranos;
        ouranos.setName(gaia->title());
        ouranos.setType(Attribute::typeFromStringTr(gaia->dataType()));
        if(ouranos.type() == Attribute::Multi)
            ouranos.setValue(gaia->multiValue());

        hades.push_back(ouranos);
    }

    zeus->setValue(hades);

    return zeus;
}

void CategoryEditPage::tabChanged(int t)
{
    QString hermes = ui->tabWidget->tabText(t);
    QTreeWidgetItem* athena = treeSearch(m_root, hermes, t);

    if(athena != nullptr)
        ui->w_subCategory->setCurrentItem(athena);
    else
        ui->w_subCategory->setCurrentItem(m_root);

}

QTreeWidgetItem* CategoryEditPage::treeSearch(QTreeWidgetItem* item, QString title, int deep)
{
    QQueue<QTreeWidgetItem*> zeus;
    zeus.enqueue(item);
    QTreeWidgetItem* hermes = nullptr;

    while(!zeus.isEmpty())
    {
        QTreeWidgetItem* hera = zeus.dequeue();
        if(hera->data(2,0).toInt() < deep || deep < 0)
            for(int ares = 0; ares < hera->childCount(); ares++)
                zeus.enqueue(hera->child(ares));

        if(((title == hera->text(0)) &&
                    (hera->data(1,0).value<SubCategory>().layout == dynamic_cast<QScrollArea*>(ui->tabWidget->widget(deep))->widget()->layout()))
                || title.isEmpty())
                hermes = hera;
    }

    return hermes;
}

void CategoryEditPage::addSub()
{
    QTreeWidgetItem* athena = ui->w_subCategory->currentItem();
    QString hermes = QInputDialog::getText(0, tr("Sub category name"), tr("Name"));
    if(!hermes.isEmpty())
    {
        QTreeWidgetItem* gaia = new QTreeWidgetItem;
        gaia->setFlags(gaia->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        gaia->setText(0, hermes);
        gaia->setData(1,0,QVariant::fromValue(SubCategory()));
        gaia->data(1,0).value<SubCategory>().category->setName(hermes);
        gaia->setData(2,0, QVariant(athena->data(2,0).toInt() + 1));
        athena->addChild(gaia);
        addAttribute(-1, gaia);
        showSub(gaia, 0);
    }

    ui->w_subCategory->expandAll();
}

void CategoryEditPage::removeSub()
{
    QTreeWidgetItem* athena = ui->w_subCategory->currentItem()->parent();

    if(athena->data(2,0).toInt() != 0)
    {
        m_remove.push_back(athena->data(1,0).value<SubCategory>().category);
        athena->removeChild(ui->w_subCategory->currentItem());
        delete athena;
    }
}

QList<CategorySPointer> CategoryEditPage::toRemove() const
{
    return m_remove;
}

void CategoryEditPage::textChanged(QTreeWidgetItem * item, int)
{
    item->data(1,0).value<SubCategory>().category->setName(item->text(0));
    showSub(item);
}
