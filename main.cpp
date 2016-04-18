#include <QApplication>
#include<Eigen/Dense>
#include <vector>
#include<QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include <cmath>


using namespace Eigen;
using namespace std;

void get_dimensions(QString filename, int & row, int & column, vector<QString> & filecontents);
void load_into_matrix(vector<QString> & filecontents, MatrixXd M);
void log_of_Matrix(MatrixXd M, vector<QString> & filecontents);
int main()
{

    int row = 0, column = 0;
    QString file0 = "C:/Users/bec100/Desktop/data/d0.dat";
    QString file1 = "C:/Users/bec100/Desktop/data/d1.dat";
    QString file2 = "C:/Users/bec100/Desktop/data/d2.dat";
    vector<QString> file0contents;
    vector<QString> file1contents;
    vector<QString> file2contents;

    get_dimensions(file0, row, column, file0contents);
    MatrixXd Matrix0(row, column);
    row = 0,column = 0;
    get_dimensions(file1, row, column, file1contents);
    MatrixXd Matrix1(row, column);
    row = 0,column = 0;
    get_dimensions(file2, row, column, file2contents);
    vector<QString> file2contentCopy = file2contents;
    MatrixXd Matrix2(row, column);
    load_into_matrix(file0contents, Matrix0);
    load_into_matrix(file1contents, Matrix1);
    load_into_matrix(file2contents, Matrix2);


    int numXrows = Matrix2.rows();
    int numXcols = Matrix2.cols();
    MatrixXd logOfX(Matrix2.rows(), Matrix2.cols());
    log_of_Matrix(logOfX, file2contentCopy);
    MatrixXd Xmean(1, 9); //hard coded for now
    MatrixXd Xstd(1, 9);    //hard coded for now
    MatrixXd Xz(2000, 9);   //hard coded for now

    for(int i = 0; i < numXcols; i++){
        Xmean(i) = X.col(i).sum();
        //Xstd(i) = X.col(i).standardDeviation
        //Xz.col(i) = X.col(i) - Xmean(i) / Xstd(i);
    }
    MatrixXd Y= [Matrix0, Matrix1];
    //Y.col(1) -> need to take log of this col
    //Y.col(3) -> need to take log of this col

    int numYrows = Y.rows();
    int numYcols = Y.cols();
    double Yact[9];
    Yact[0]= 77.36266321;
    Yact[1] = log(383.1850001);
    Yact[2] = 0.1156615854;
    Yact[3] = log(123.5);
    Yact[4] = 9.644044609;
    Yact[5] = -53.61381482;
    Yact[6] =  0.0006670786559;
    Yact[7] = 138.66;
    Yact[8] = 0.0001757001353;

    MatrixXd Ymean(1, 9); //hard coded for now
    MatrixXd Ystd(1, 9);    //hard coded for now
    MatrixXd Yz(2000, 9);   //hard coded for now
    MatrixXd Yact1(1, 9);
    for(int i = 0; i < numYcols; i++){
        Ymean(i) = Y.col(i).sum();
        Ystd(i) = Y.col(i).std();
        Yz.col(i) = Y.col(i) - Ymean(i) / Y.std(i);
        Yact1.col(i) = Yact[i] - Ymean(i) / Ystd(i);
    }
            return 0;
}
void get_dimensions(QString filename, int & row, int & column, vector<QString> & filecontents){
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"error", file.errorString());
    }
    else{
        QTextStream in(&file);
        QString line = in.readLine();
        QStringList split_line = line.split("\t");
        column = split_line.length();
        while(!in.atEnd()){
            QString line = in.readLine();
            filecontents.push_back(line);
            row++;
        }
        file.close();
    }
    column--;
}
void load_into_matrix(vector<QString> & filecontents, MatrixXd M){
    int i = 0;
    while(filecontents.size() > 0){
        QString line = filecontents.back();
        QStringList values= line.split("\t");
        //these value 7, 4, 10 are to account for the "" that is persistant with splitting strings to arrays
        if(values.length() == 7){
            M.row(i) <<  values[0].toDouble(), values[1].toDouble(), values[2].toDouble(), values[3].toDouble(),values[4].toDouble(), values[5].toDouble();}
        else if(values.length() == 4){
            M.row(i) << values[0].toDouble(), values[1].toDouble(), values[2].toDouble(); }
        else if(values.length() == 10){
            M.row(i) << values[0].toDouble(), values[1].toDouble(), values[2].toDouble(), values[3].toDouble(),values[4].toDouble(), values[5].toDouble(), values[6].toDouble(), values[7].toDouble(), values[8].toDouble();}
        else{
            qDebug() << "That dimension not yet supported" << endl;
            exit(0);
        }
        i++;
        filecontents.pop_back();
    }
}
void log_of_Matrix(MatrixXd M, vector<QString> & filecontents){
    int i = 0;
    while(filecontents.size() > 0){
        QString line = filecontents.back();
        QStringList values= line.split("\t");
        //these value 7, 4, 10 are to account for the "" that is persistant with splitting strings to arrays
        if(values.length() == 7){
            M.row(i) <<  log(values[0].toDouble()), log(values[1].toDouble()), log(values[2].toDouble()), log(values[3].toDouble()),log(values[4].toDouble()), log(values[5].toDouble());}
        else if(values.length() == 4){
            M.row(i) << log(values[0].toDouble()), log(values[1].toDouble()), log(values[2].toDouble()); }
        else if(values.length() == 10){
            M.row(i) << log(values[0].toDouble()), log(values[1].toDouble()), log(values[2].toDouble()), log(values[3].toDouble()),log(values[4].toDouble()), log(values[5].toDouble()), log(values[6].toDouble()), log(values[7].toDouble()), log(values[8].toDouble());}
        else{
            qDebug() << "That dimension not yet supported" << endl;
            exit(0);
        }
        i++;
        filecontents.pop_back();
    }
}
