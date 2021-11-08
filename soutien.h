#ifndef SOUTIEN_H
#define SOUTIEN_H
#include <QString>

class soutien
{
public:
    soutien();
    soutien(int num_sou,QString type_sou,double quantite_sou,QString date_sou);
    int getnum_sou();
    QString gettype_sou();
    double getquantite_sou();
    QString getdate_sou();
    void setnum_sou(int);
    void settype_sou(QString);
    void setquantite_sou(double);
    void setdate_sou(QString);
private :
    int num_sou;
    QString type_sou;
    double quantite_sou;
    QString date_sou;
};

#endif // SOUTIEN_H
