#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QInputDialog>
#include <QMainWindow>
#include "candidats.h"

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

    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonChercher_clicked();










    void on_radioButton_croissant_clicked();

    void on_radioButton_dcroissant_clicked();





    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_2_clicked();

   // void on_pushButton_clicked();


    void on_pushButton_4_clicked();

   // void on_pushButton_5_clicked();





    void on_pushButtonAjouter_2_clicked();

    void on_pushButtonSupprimer_2_clicked();

    void on_pushButtonModifier_2_clicked();

    void on_pushButtonChercher_2_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_croissant_2_clicked();

    void on_radioButton_dcroissant_2_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_12_clicked();

  //  void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButtonAjouter_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButtonSupprimer_3_clicked();

    void on_pushButtonModifier_3_clicked();

    void on_pushButtonChercher_3_clicked();

    void on_radioButton_croissant_3_clicked();

    void on_radioButton_dcroissant_3_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

private:
    Ui::MainWindow *ui;

    candidats Etmp;
};

#endif // MAINWINDOW_H
