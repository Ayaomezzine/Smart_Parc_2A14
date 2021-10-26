#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;
    candidats Etmp;
};

#endif // MAINWINDOW_H
