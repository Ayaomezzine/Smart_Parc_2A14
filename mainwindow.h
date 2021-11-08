#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sponsors.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajoutersp_clicked();


    void on_supprimersp_clicked();

    void on_ouvrireajouter_clicked();

    void on_afficheraceuille_clicked();

    void on_pushButton_5_clicked();

    void on_actualitesaccuille_clicked();

    void on_statistiquesaceuille_clicked();

    void on_ajouteraceuille_clicked();

private:
    Ui::MainWindow *ui;
    Sponsors sp;

};

#endif // MAINWINDOW_H
