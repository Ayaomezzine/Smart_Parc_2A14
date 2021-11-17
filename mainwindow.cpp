#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidats.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QIntValidator>
#include <QFontDialog>
#include <QDate>
#include "valider.h"
#include <QTranslator>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tab_candidat->setModel(Etmp.afficher());
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
      if (!file.open(QIODevice::ReadOnly))
      {
          QMessageBox::information(0,"info",file.errorString());
      }
      QTextStream in (&file);
     ui->textBrowser->setText(in.readAll());


     QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_2->setText(to.readAll());

      QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
        if (!file3.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file3.errorString());
        }
        QTextStream too (&file2);
       ui->textBrowser_3->setText(too.readAll());



    //controle de saisie
ui->cin->setMaxLength(8);

ui->gsmm->setMaxLength(8);
ui->GSM->setMaxLength(8);
ui->cin->setValidator(new QIntValidator(0,99999999,this));
ui->GSM->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm->setValidator(new QIntValidator(0,99999999,this));

ui->NOM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->cin->setMaxLength(8);

ui->gsmm_2->setMaxLength(8);
ui->GSM_2->setMaxLength(8);
ui->cin_2->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_2->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm_2->setValidator(new QIntValidator(0,99999999,this));

ui->NOM_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->gsmm_3->setMaxLength(8);
ui->GSM_3->setMaxLength(8);
ui->cin_3->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_3->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm_3->setValidator(new QIntValidator(0,99999999,this));

ui->NOM_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit->setMaxLength(8);
ui->lineEdit->setValidator(new QIntValidator(0,99999999,this));

ui->lineEdit_9->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_9->setMaxLength(8);

ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_5->setMaxLength(8);



ui->lineEdit_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_4->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit_6->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_7->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_8->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit_10->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_11->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_12->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

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
      int GSM=ui->GSM->text().toInt();
       QString MAIL=ui->MAIL->text();
       QDate DATEN=ui->dateEdit->date();
       QString POSTE=ui->POSTE->text();
       QString SALAIRE=ui->SALAIRE->text();
       QString PRETS=ui->PRETS->text();
       QString EXP=ui->EXP->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("Le remplissage des champs vides est Obligatoire."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="Vous avez ajouté un candidat\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
    ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButtonSupprimer_clicked()
{
    int CIN = ui->tab_candidat->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez supprimé un candidat\n";
            cout <<""<< message2;

            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser->setText(in.readAll());
        ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }




void MainWindow::on_pushButtonModifier_clicked()
{
    candidats c;

        int CIN = ui->tab_candidat->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm->text().toInt();

        QString ADRESSE=ui->adressem->text();


        QString MAIL=ui->mailm->text();


        QString POSTE=ui->postem->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez modifié un candidat\n";
            cout << message2;


            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser->setText(in.readAll());
        ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_clicked()
{

QString findText;
       QString text = ui->chercher->text();

   QTableView* table=ui->tab_candidat;
       if (text.isEmpty()) {
           QMessageBox::information(this, tr("Empty Field"),
               tr("Entrez le nom a rechercher."));
           ui->tab_candidat->setModel(Etmp.afficher());
           return;
       } else {
           findText = text;
           Etmp.recherche(table,findText);
}

}




void MainWindow::on_radioButton_croissant_clicked()
{

                  ui->tab_candidat->setModel(Etmp.tri());

}


void MainWindow::on_radioButton_dcroissant_clicked()
{

                  ui->tab_candidat->setModel(Etmp.trid());
}




void MainWindow::on_radioButton_clicked()
{
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_2_clicked()
{
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_4_clicked()
{
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer1());
}




void MainWindow::on_radioButton_3_clicked()
{
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer4());
}



//valider fr
void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;

    int  CIN=ui->lineEdit->text().toInt();

    QString NOM=ui->lineEdit_2->text();
    QString PRENOM=ui->lineEdit_3->text();
   QString DESC=ui->lineEdit_4->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file2);
if(test)
{

    QString message2="\n CIN:";
    QString message3="\n NOM:";
    QString message4="\n PRENOM:";
    QString message5="\n DESCRIPTION:";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_2->setText(to.readAll());


}}

/*void MainWindow::on_pushButton_clicked()
{

}*/


//return
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}






//ANG-----------------------------------------------------------------------------------------------------------------------------------



void MainWindow::on_pushButtonAjouter_2_clicked()
{
    int  CIN=ui->cin_2->text().toInt();

    QString ADRESSE=ui->ADRESSE_2->text();
     QString NOM=ui->NOM_2->text();
      QString PRENOM=ui->PRENOM_2->text();
      int GSM=ui->GSM_2->text().toInt();
       QString MAIL=ui->MAIL_2->text();
       QDate DATEN=ui->dateEdit_2->date();
       QString POSTE=ui->POSTE_2->text();
       QString SALAIRE=ui->SALAIRE_2->text();
       QString PRETS=ui->PRETS_2->text();
       QString EXP=ui->EXP_2->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("The filling of empty fields is Obligatory."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="You had added a candidate\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser_4->setText(in.readAll());
    ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



    }ui->stackedWidget_3->setCurrentIndex(1);}

void MainWindow::on_pushButtonSupprimer_2_clicked()
{
    int CIN = ui->tab_candidat_2->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="You had deleted a candidate\n";
            cout <<""<< message2;

            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser_4->setText(in.readAll());
        ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }




void MainWindow::on_pushButtonModifier_2_clicked()
{
    candidats c;

        int CIN = ui->tab_candidat_2->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm_2->text().toInt();

        QString ADRESSE=ui->adressem_2->text();


        QString MAIL=ui->mailm_2->text();


        QString POSTE=ui->postem_2->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="You had modified a candidate\n";
            cout << message2;


            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser_4->setText(in.readAll());
        ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_2_clicked()
{

QString findText;
       QString text = ui->chercher_2->text();

   QTableView* table=ui->tab_candidat_2;
       if (text.isEmpty()) {
           QMessageBox::information(this, tr("Empty Field"),
               tr("Entrez le nom a rechercher."));
           ui->tab_candidat_2->setModel(Etmp.afficher());
           return;
       } else {
           findText = text;
           Etmp.recherche(table,findText);
}

}




void MainWindow::on_radioButton_croissant_2_clicked()
{

                  ui->tab_candidat_2->setModel(Etmp.tri());

}


void MainWindow::on_radioButton_dcroissant_2_clicked()
{

                  ui->tab_candidat_2->setModel(Etmp.trid());
}




void MainWindow::on_radioButton_5_clicked()
{
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_6_clicked()
{
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_8_clicked()
{
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer1());
}




void MainWindow::on_radioButton_7_clicked()
{
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer4());
}
















// BOUTONS ang
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}
//ml ang lel fr
void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


//valider ang
void MainWindow::on_pushButton_7_clicked()
{
    QSqlQuery query;

    int  CIN=ui->lineEdit_5->text().toInt();

    QString NOM=ui->lineEdit_6->text();
    QString PRENOM=ui->lineEdit_7->text();
   QString DESC=ui->lineEdit_8->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file2);
if(test)
{

    QString message2="\n CIN:";
    QString message3="\n NAME:";
    QString message4="\n FIRST NAME:";
    QString message5="\n DESCRIPTION:";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_3->setText(to.readAll());


}
}



//------------------------------------------------------------arabe------------------------------------------------------------------------------------------







void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButtonAjouter_3_clicked()
{
    int  CIN=ui->cin_3->text().toInt();

    QString ADRESSE=ui->ADRESSE_3->text();
     QString NOM=ui->NOM_3->text();
      QString PRENOM=ui->PRENOM_3->text();
      int GSM=ui->GSM_3->text().toInt();
       QString MAIL=ui->MAIL_3->text();
       QDate DATEN=ui->dateEdit_3->date();
       QString POSTE=ui->POSTE_3->text();
       QString SALAIRE=ui->SALAIRE_3->text();
       QString PRETS=ui->PRETS_3->text();
       QString EXP=ui->EXP_3->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("Le remplissage des champs vides est Obligatoire."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file3);
if(test)
{

    QString message2="تم إضافة مرشح\n";
        cout << message2;
        QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file3.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file3.errorString());
       }
       QTextStream too (&file3);
      ui->textBrowser_6->setText(too.readAll());
    ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}ui->stackedWidget_4->setCurrentIndex(1);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{

    QSqlQuery query;

    int  CIN=ui->lineEdit_9->text().toInt();

    QString NOM=ui->lineEdit_10->text();
    QString PRENOM=ui->lineEdit_11->text();
   QString DESC=ui->lineEdit_12->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file3);
if(test)
{

    QString message2="\n: بطاقة تعريف";
    QString message3="\n: الإسم";
    QString message4="\n: اللقب";
    QString message5="\n :وصف";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file3.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file3.errorString());
       }
       QTextStream too (&file3);
      ui->textBrowser_5->setText(too.readAll());


}
}

void MainWindow::on_pushButtonSupprimer_3_clicked()
{
    int CIN = ui->tab_candidat_3->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file3);
    if(test)
    {

        QString message2="تم حذف مرشح\n";
            cout <<""<< message2;

            QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file3.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file3.errorString());
           }
           QTextStream in (&file3);
          ui->textBrowser_6->setText(in.readAll());
        ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButtonModifier_3_clicked()
{
    candidats c;

        int CIN = ui->tab_candidat_3->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm_2->text().toInt();

        QString ADRESSE=ui->adressem_3->text();


        QString MAIL=ui->mailm_3->text();


        QString POSTE=ui->postem_3->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file3);
    if(test)
    {

        QString message2="تم تعديل مرشح \n";
            cout << message2;


            QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file3.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file3.errorString());
           }
           QTextStream in (&file3);
          ui->textBrowser_6->setText(in.readAll());
        ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_3_clicked()
{
    QString findText;
           QString text = ui->chercher_3->text();

       QTableView* table=ui->tab_candidat_3;
           if (text.isEmpty()) {
               QMessageBox::information(this, tr("Empty Field"),
                   tr("Entrez le nom a rechercher."));
               ui->tab_candidat_3->setModel(Etmp.afficher());
               return;
           } else {
               findText = text;
               Etmp.recherche(table,findText);
    }

}

void MainWindow::on_radioButton_croissant_3_clicked()
{
    ui->tab_candidat_3->setModel(Etmp.tri());
}

void MainWindow::on_radioButton_dcroissant_3_clicked()
{
    ui->tab_candidat_3->setModel(Etmp.trid());
}

void MainWindow::on_radioButton_12_clicked()
{
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer1());
}

void MainWindow::on_radioButton_9_clicked()
{
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_10_clicked()
{
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_11_clicked()
{
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer4());
}
