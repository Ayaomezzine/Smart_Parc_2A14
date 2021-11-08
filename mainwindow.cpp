#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsors.h"
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QTabWidget>
#include<QTabWidget>
#include <QAbstractItemView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tablesp->setModel(sp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_ajoutersp_clicked()
{
     QString nature=ui->typesp->currentText();
    int id_sponsor=ui->idsp->text().toInt();
    QString nom_sp=ui->nomsp->text();

    Sponsors sp(id_sponsor,nom_sp,nature);

    bool test=sp.ajouter();
    if(test)
    {
        ui->tablesp->setModel(sp.afficher());
        QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n"
                                                                        "click cancel to exit.")
                                                                            ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_supprimersp_clicked()
{
int id_sponsor  = ui->tablesp->selectionModel()->currentIndex().data().toInt();

    bool test=sp.supprimer(id_sponsor);
    if(test)
    {
        ui->tablesp->setModel(sp.afficher());
        QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n"
                                                                        "click cancel to exit.")
                                                                            ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_ouvrireajouter_clicked()
{

  ui->tabWidget->setCurrentWidget(ui->tab_4);
}

void MainWindow::on_afficheraceuille_clicked()
{
      ui->tabWidget->setCurrentWidget(ui->tab_3);
}

void MainWindow::on_pushButton_5_clicked()
{
         ui->tabWidget->setCurrentWidget(ui->tab_5);
}

void MainWindow::on_actualitesaccuille_clicked()
{
         ui->tabWidget->setCurrentWidget(ui->tab_2);
}

void MainWindow::on_statistiquesaceuille_clicked()
{
         ui->tabWidget->setCurrentWidget(ui->tab_6);
}

void MainWindow::on_ajouteraceuille_clicked()
{
         ui->tabWidget->setCurrentWidget(ui->tab_4);
}
