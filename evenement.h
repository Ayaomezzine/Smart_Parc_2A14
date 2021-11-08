#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>

class evenement
{
public:
    evenement();
   evenement(int num_eve,QString nom_eve,QString type_eve,QString date_eve,QString montant_payee,QString montant_gagnee);
    int getnum_eve();
    QString getnom_eve();
    QString gettype_eve();
    QString getdate_eve();
    QString getmontant_payee();
    QString getmontant_gagnee();
    void setnum_eve(int);
    void setnom_eve(QString);
    void settype_eve(QString);
    void setdate_eve(QString);
    void setmontant_payee(QString);
    void setmontant_gagnee(QString);

private:
    int num_eve;
    QString nom_eve;
    QString type_eve;
    QString date_eve;
    QString montant_payee;
    QString montant_gagnee;

};

#endif // EVENEMENT_H
