#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidats.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_candidat->setModel(Etmp.afficher());
ui->cin->setValidator(new QIntValidator(0,99999999,this));

}


MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButtonAjouter_clicked()
{
    int  CIN=ui->cin->text().toInt();
    QString ADRESSE=ui->ADRESSE->text();
     QString NOM=ui->NOM->text();
      QString PRENOM=ui->PRENOM->text();
       QString MAIL=ui->MAIL->text();
     int GSM=ui->GSM->text().toInt();
    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL);
bool test=C.ajouter();
if (test)
        { //Actualiser
     ui->tab_candidat->setModel(Etmp.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    candidats c;c.setCIN(ui->cin_2->text().toInt());
    bool test=Etmp.supprimer(c.get_CIN());
    QMessageBox msgBox;
    if (test)
            {
        //actualiser
         ui->tab_candidat->setModel(Etmp.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("Suppression effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButtonModifier_clicked()
{


        int  CIN=ui->cin->text().toInt();
        QString ADRESSE=ui->ADRESSE->text();
         QString NOM=ui->NOM->text();
          QString PRENOM=ui->PRENOM->text();
           QString MAIL=ui->MAIL->text();
         int GSM=ui->GSM->text().toInt();
        candidats C(CIN,NOM,PRENOM,ADRESSE,GSM,MAIL);
    bool test=C.modifier();
    if (test)
            { //Actualiser
         ui->tab_candidat->setModel(Etmp.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("Ajout effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);

}

