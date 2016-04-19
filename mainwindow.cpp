#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Eigen::MatrixXd Matrix, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph(Matrix);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::graph(Eigen::MatrixXd Matrix){
    //creating a bar graph for each (6)
    QCPBars *graph1 = new QCPBars(ui->plot1->xAxis, ui->plot1->yAxis);
    QCPBars *graph2 = new QCPBars(ui->plot2->xAxis, ui->plot2->yAxis);
    QCPBars *graph3 = new QCPBars(ui->plot3->xAxis, ui->plot3->yAxis);
    QCPBars *graph4 = new QCPBars(ui->plot4->xAxis, ui->plot4->yAxis);
    QCPBars *graph5 = new QCPBars(ui->plot1->xAxis, ui->plot5->yAxis);
    QCPBars *graph6 = new QCPBars(ui->plot2->xAxis, ui->plot6->yAxis);

    ui->plot1->addPlottable(graph1);
    ui->plot2->addPlottable(graph2);
    ui->plot3->addPlottable(graph3);
    ui->plot4->addPlottable(graph4);
    ui->plot5->addPlottable(graph5);
    ui->plot6->addPlottable(graph6);

    //Graph Titles
    ui->plot1->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot1, "regression vars for CL"));
    ui->plot2->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot2, "regression vars for DDR"));
    ui->plot3->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot3, "regression vars for MDP"));
    ui->plot4->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot4, "regression vars for APA"));
    ui->plot5->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot5, "regression vars for APD"));
    ui->plot6->plotLayout()->addElement(0,0, new QCPPlotTitle(ui->plot6, "regression vars for maxderiv"));

    //Transforming the data from the Matrix
    QVector<double> data1, data2, data3, data4, data5, data6, currentlyUnknown;
    for(int i = 0; i < Matrix.rows(); i++){
        data1.push_back(Matrix(i, 1));
        data2.push_back(Matrix(i, 2));
        data3.push_back(Matrix(i, 5));
        data4.push_back(Matrix(i, 0));
        data5.push_back(Matrix(i, 3));
        data6.push_back(Matrix(i, 4));
    }
    //plotting the data onto a graph
    //unsure of what the second vector should be...hence the name
    ui->plot1->graph(0)->addData(data1, currentlyUnknown);
    ui->plot2->graph(0)->addData(data2, currentlyUnknown);
    ui->plot3->graph(0)->addData(data3, currentlyUnknown);
    ui->plot4->graph(0)->addData(data4, currentlyUnknown);
    ui->plot5->graph(0)->addData(data5, currentlyUnknown);
    ui->plot6->graph(0)->addData(data6, currentlyUnknown);

}
