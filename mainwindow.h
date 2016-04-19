#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Eigen/Dense>
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Eigen::MatrixXd Matrix, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void graph(Eigen::MatrixXd Matrix);
};

#endif // MAINWINDOW_H
