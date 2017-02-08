#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QPair>
#include <QListWidget>
#include <QTableWidget>
#include <QDebug>
#include <QPointer>
#include <QToolTip>
#include "view_global.h"
#include "user.h"

namespace Ui {
class MainWindow;
}

class VIEWSHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setUserOk(User::UserType);
    void setMediaTable(QStringList, QList<QColor>);
    void setCurrentMedia(QString);
    void setCategoryList(QStringList);
    void setCurrentCategory(QString);
    QString currentMedia() const;
    QString currentCategory() const;
    void setShortcut(QMap<QString, QString>);
    void clean();

protected:
    void changeEvent(QEvent *);
    void resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui;
    User::UserType m_currentUserType;

public slots:
    void save();
    void saveAs();
    void load();
    void newBase();
    void seeMedia(QTableWidgetItem* = nullptr);
    void addMedia();
    void removeMedia();
    void addCategory();
    void removeCategory();
    void seeCategory(QListWidgetItem* = nullptr);
    void categoryClicked(QListWidgetItem*);
    void about();
    void aboutQt();
    void showUser();
    void settings();

signals:
    void s_save(QString);
    void s_load(QString);
    void s_newBase();
    void s_seeMedia();
    void s_addMedia(QString);
    void s_removeMedia(QString, QString);
    void s_addCategory(QString);
    void s_removeCategory(QString);
    void s_seeCategory();
    void s_showCategory();
    void s_showUser();
    void s_search();
    void s_settings();
};

typedef QPointer<MainWindow> MainWindowPointer;
#endif // MAINWINDOW_H
