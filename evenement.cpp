#include "evenement.h"

evenement::evenement()
{
    num_eve=0;
     nom_eve="";
     type_eve="";
     date_eve="";
     montant_payee="";
     montant_gagnee="";
}
evenement::evenement(int num_eve,QString nom_eve,QString type_eve,QString date_eve,QString montant_payee,QString montant_gagnee)
{
this-> num_eve= num_eve;
this->nom_eve=nom_eve;
this->type_eve=type_eve;
this->date_eve=date_eve;
this->montant_payee=montant_payee;
this->montant_gagnee=montant_gagnee;
}
int evenement::getnum_eve(){return num_eve;}
QString evenement::getnom_eve(){return nom_eve;}
QString evenement::gettype_eve(){return type_eve;}
QString evenement::getdate_eve(){return date_eve;}
QString evenement::getmontant_payee(){return montant_payee;}
QString evenement::getmontant_gagnee(){return montant_gagnee;}

void evenement::setnum_eve(int num_eve){this-> num_eve= num_eve;}
void evenement::setnom_eve(QString nom_eve){this->nom_eve=nom_eve;}
void evenement::settype_eve(QString type_eve){this->type_eve=type_eve;}
void evenement::setdate_eve(QString date_eve){this->date_eve=date_eve;}
void evenement::setmontant_payee(QString montant_payee){this->montant_payee=montant_payee;}
void evenement::setmontant_gagnee(QString montant_gagnee){this->montant_gagnee=montant_gagnee;}
