#include "mediaview.h"
#include "ui_mediaview.h"

MediaView::MediaView(MediaSPointer m, User::UserType type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MediaView), l_attribute(new QVBoxLayout), m_user(type), m_old(m->name())
{
    ui->setupUi(this);
    m_root = constructTree(m, 0);
    int terra = InventoryView::maxDeep(m_root);
    for(int hermes = 0; hermes <= terra; hermes++)
    {
        QScrollArea* artemis = new QScrollArea;
        artemis->setWidget(new QWidget);
        artemis->setWidgetResizable(true);
        ui->tabWidget->insertTab(hermes, artemis, tr("Parent"));
    }
    setWindowTitle(tr("View ") + m->name());
    if(type == User::Viewer)
    {
        for(int ouranos = 0; ouranos <  m_root->data(1,0).value<SubMedia>().list->size(); ouranos++)
             m_root->data(1,0).value<SubMedia>().list->at(ouranos)->setEnabled(false);
    }


    ui->treeWidget->insertTopLevelItem(0, m_root);
    ui->treeWidget->setCurrentItem(m_root);
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *,int )), this, SLOT(showSub(QTreeWidgetItem*, int)));
    connect(ui->w_add, SIGNAL(clicked()), this, SLOT(addSub()));
    connect(ui->w_remove, SIGNAL(clicked()), this, SLOT(removeSub()));
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(editName(QTreeWidgetItem*,int)));

    showSub(m_root, 0);
    ui->treeWidget->expandAll();
}

MediaView::~MediaView()
{
    delete ui;
}

void MediaView::accept()
{
    if(m_user != User::Viewer)
        emit s_send(m_root, m_old);

    close();
}

QTreeWidgetItem* MediaView::constructTree(MediaSPointer m, int deep)
{
    QTreeWidgetItem* zeus = new QTreeWidgetItem;
    zeus->setFlags(zeus->flags() | Qt::ItemIsEditable);
    zeus->setText(0, m->name());
    zeus->setToolTip(0, m->name());
    SubMedia gaia;
    foreach(auto ares, m->category()->values())
    {
        if(ares.name() != "name" && !ares.name().isEmpty())
        {
            gaia.list->push_back(new MediaWidget);
            gaia.list->last()->set(ares, m->attribute(ares.name()));
            gaia.layout->insertWidget(gaia.layout->count(),gaia.list->last());
        }
    }

    gaia.category = m;

    zeus->setData(1,0, QVariant::fromValue(gaia));
    zeus->setData(2,0, QVariant(deep));

    foreach(auto hera, m->subMedias())
        zeus->addChild(constructTree(hera, deep+1));

    return zeus;
}

void MediaView::showSub(QTreeWidgetItem* item, int)
{
    ui->tabWidget->removeTab(item->data(2,0).toInt());
    QScrollArea* demeter = new QScrollArea;
    demeter->setWidget(new QWidget);
    demeter->setWidgetResizable(true);
    demeter->widget()->setLayout(item->data(1,0).value<SubMedia>().layout);
    ui->tabWidget->insertTab(item->data(2,0).toInt(), demeter, item->text(0));
    ui->tabWidget->setCurrentIndex(item->data(2,0).toInt());
    ui->w_add->setEnabled(!(item->data(1,0).value<SubMedia>().category->category()->subCategory().isEmpty()));

    ui->tabWidget->setTabText(item->data(2,0).toInt(), item->text(0));
    setWindowTitle(tr("View ") + item->text(0));
}


void MediaView::addSub()
{
    SubMedia hades = ui->treeWidget->currentItem()->data(1,0).value<SubMedia>();
    Category* zeus = hades.category->category();

    QStringList artemis = zeus->subCategory().keys();
    if(artemis.isEmpty())
    {
        QMessageBox::information(this, tr("No subcategory"), tr("No subcategory found"));
        return;
    }

    QString demeter = QInputDialog::getItem(this, tr("New subcategory"), tr("Name"), artemis,0, false);

    QString gaia = QInputDialog::getText(this, tr("Submedia name"), tr("Name"));

    if(!demeter.isEmpty() && !gaia.isEmpty())
    {
        MediaSPointer ares(new Media);
        ares->setName(gaia);
        ares->setCategory(zeus->subCategory()[demeter].data());
        SubMedia hermes;
        hermes.category = ares;
        QTreeWidgetItem* hephaistos = constructTree(ares, ui->treeWidget->currentItem()->data(2,0).toInt() + 1);

        hephaistos->setToolTip(0, hephaistos->text(0));

        ui->treeWidget->currentItem()->addChild(hephaistos);
        ui->treeWidget->expandAll();
        showSub(hephaistos,0);
        ui->treeWidget->setCurrentItem(hephaistos);
    }
}

void MediaView::removeSub()
{
    QTreeWidgetItem* artemis = ui->treeWidget->currentItem();
    if(artemis->data(2,0).toInt() != 0)
    {
        ui->treeWidget->removeItemWidget(artemis, 0);
        delete artemis;
    }
}

void MediaView::editName(QTreeWidgetItem * item, int)
{
    item->data(1,0).value<SubMedia>().category->setName(item->text(0));
    ui->tabWidget->setTabText(item->data(2,0).toInt(), item->text(0));
    item->setToolTip(0, item->text(0));
    showSub(item,0);
}
