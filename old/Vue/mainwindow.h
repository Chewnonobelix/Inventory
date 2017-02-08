#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QListWidgetItem>
#include <QTableWidgetItem>

#include "../Model/AbstractMedia.h"

#include <cmath>

#define NOMBRE 3.0 // define pour le nombre d'élément par colonne

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeWindowTitle(QString);
    void activation(bool = false);
    void setCategorie(QStringList);
    void addCategorie(QString);
    void maj(QStringList);
    void setCompteur(int = 0);
    QString getCurrent() const;

private:
    Ui::MainWindow *ui;

public slots:
    void nouveau();
    void chargement();
    void ajouter();
    void sauvegarde();
    void changeCategorie(QListWidgetItem* );
    void selection(QTableWidgetItem*);

signals:
    void s_chargement();
    void s_sauvegarde();
    void s_nouveau(QString);
    void s_ajouter();
    void s_changeCategorie(QString);
    void s_selection(QString, QString);
};

#endif // MAINWINDOW_H
