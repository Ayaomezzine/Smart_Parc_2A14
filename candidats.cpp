#include "candidats.h"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>

candidats::candidats()
{
ADRESSE="";
NOM="";
PRENOM="";
CIN=0;
MAIL="";
GSM=0;
}
candidats::candidats(int CIN,QString ADRESSE,QString NOM,QString PRENOM,int GSM,QString MAIL )
{
  this->ADRESSE=ADRESSE;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
    this->CIN=CIN;
    this->MAIL=MAIL;
  this->GSM=GSM;
}
QString candidats::get_NOM(){return  NOM;}
QString candidats::get_PRENOM(){return PRENOM;}
QString candidats::get_MAIL(){return MAIL;}
QString candidats::get_ADRESSE(){return  ADRESSE;}
int candidats::get_CIN(){return  CIN;}
int candidats::get_GSM(){return  GSM;}
void  candidats::setADRESSE(QString ADRESSE ){this->ADRESSE=ADRESSE;}
void  candidats::setNOM(QString NOM){this->NOM=NOM;}
void  candidats::setPRENOM(QString PRENOM){this->PRENOM=PRENOM;}
void  candidats::setCIN( int CIN){this->CIN=CIN;}
void  candidats::setMAIL(QString MAIL) {this->MAIL=MAIL;}
void  candidats::setGSM(int GSM) {this->GSM=GSM;}

bool candidats::ajouter()
{
QSqlQuery query;
QString CIN_string=QString::number(CIN);
QString GSM_string=QString::number(GSM);
query.prepare("INSERT INTO CANDIDATS (CIN,NOM,PRENOM,ADRESSE,MAIL,GSM) "
                    "VALUES (:CIN, :NOM,:PRENOM,:ADRESSE,:MAIL,:GSM)");
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":CIN", CIN_string );
query.bindValue(":MAIL", MAIL);
query.bindValue(":GSM",GSM_string);
  return query.exec();

}
bool candidats::supprimer(int CIN )
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from candidats where CIN = :CIN ");
query.bindValue(":CIN", res);
return    query.exec();
}
QSqlQueryModel * candidats::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from candidats");


    return model;
}

bool candidats::modifier()
{
    QSqlQuery query;
    QString CINstring=QString::number(CIN);
    QString GSM_string=QString::number(GSM);
    query.prepare("UPDATE client SET CIN=CIN,REF=:REF,NOM=:NOM,PRENOM=:PRENOM,ADRESSE_Email=:ADRESSE_Email WHERE CIN=:CIN");
    query.bindValue(":ADERESSE", ADRESSE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":CIN", CINstring );
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":GSM",GSM_string);
    return    query.exec();

}

