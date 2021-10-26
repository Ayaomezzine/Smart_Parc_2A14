#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <QString>
#include <QSqlQuery>

#include <QSqlQueryModel>
class candidats
{public:
    candidats();
    candidats(int ,QString ,QString ,QString ,int ,QString );
    QString  get_ADRESSE();
    QString get_NOM();
    QString get_PRENOM();
    int get_CIN();
    int get_GSM();
     QString get_MAIL();
   void  setADRESSE(QString);
    void  setNOM(QString);
    void  setPRENOM(QString);
    void  setCIN( int);
      void setMAIL(QString);
      void  setGSM(int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();


private:
    QString NOM,PRENOM,MAIL,ADRESSE;
    int CIN,GSM;
};

#endif // CANDIDATS_H
