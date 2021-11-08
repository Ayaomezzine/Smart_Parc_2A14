#include "sponsors.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QString>
#include <QObject>
Sponsors::Sponsors()
{
    id_sponsor=1;
    nom_sp="";
    nature="";
}

Sponsors::Sponsors(int id_sponsor,QString nom_sp,QString nature)
{
    this->id_sponsor=id_sponsor;
    this->nom_sp=nom_sp;
    this->nature=nature;


}


int Sponsors::getid_sponsor(){return id_sponsor;}
QString Sponsors::getnom_sp(){return nom_sp;}
QString Sponsors::getnature(){return nature;}


void Sponsors::setid_sponsor(int id_sponsor){this->id_sponsor=id_sponsor;}
void Sponsors::setnom_sp(QString nom_sp){this->nom_sp=nom_sp;}
void Sponsors::setnature(QString nature){this->nature=nature;}


bool Sponsors::ajouter()
{
    QSqlQuery query;
    QString id_string = QString :: number(id_sponsor);
        query.prepare("INSERT INTO sponsors (ID_SPON, NOM_SPONSOR, NATURE) ""VALUES (:ID_SPON, :NOM_SPONSOR, :NATURE)");
        query.bindValue(":ID_SPON", id_string);
        query.bindValue(":NOM_SPONSOR", nom_sp);
        query.bindValue(":NATURE", nature);
        return query.exec();

}
QSqlQueryModel* Sponsors::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM sponsors");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom du sponsor"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nature du sponsor"));
    return model;
}
bool Sponsors::supprimer(int id_sponsor)
{
    QSqlQuery query;
     QString id_string = QString :: number(id_sponsor);
    query.prepare("Delete FROM sponsors where ID_SPON = :ID_SPON");
    query.bindValue(":ID_SPON", id_string);
    return query.exec();
}
