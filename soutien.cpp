 #include "soutien.h"

soutien::soutien()
{
    num_sou=0;
   type_sou="";
    quantite_sou=0;
     date_sou="";
}
soutien::soutien(int num_sou,QString type_sou,double quantite_sou,QString date_sou)
{
    this->num_sou=num_sou;
    this->type_sou=type_sou;
    this->quantite_sou=quantite_sou;
    this->date_sou=date_sou;
}
int soutien::getnum_sou(){return num_sou;}
QString soutien::gettype_sou(){return type_sou;}
double soutien::getquantite_sou(){return quantite_sou;}
QString soutien::getdate_sou(){return date_sou;}

void soutien::setnum_sou(int num_sou){this->num_sou=num_sou;}
void soutien::settype_sou(QString type_sou){this->type_sou=type_sou;}
void soutien::setquantite_sou(double quantite_sou){this->quantite_sou=quantite_sou;}
void soutien::setdate_sou(QString date_sou){this->date_sou=date_sou;}
