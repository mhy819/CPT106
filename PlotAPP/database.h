#include <iostream>
#include <string>
#include <QVector>
#include <math.h>
#include <QDebug>
#include <float.h>
#include <cmath>
#include <QtMath>
#include <QMessageBox>

#ifndef DATABASE_H
#define DATABASE_H


class Database
{
private:
    QVector<double> x,y;//x and y are used to store the value in the file (it needs to be set the size when constructed)
    int size = 0;//record the size of the database
public:
    Database(){};//default constructer
    Database(int size);//constructer with fixed size QVector
    void setONEx(double in, int index);//set a value
    void setONEy(double in, int index);//set a value
    double getONEx(int index);//get the x value which index direct to
    double getONEy(int index);//get the y value which index direct to
    int getSize();//get the size of the database
    QVector<double> getx();//get the QVector of x
    QVector<double> gety();//get the QVector of y
    //operator overloading
    Database operator+ (Database rightOne);
    Database operator- (Database rightOne);
    Database operator* (Database rightOne);
    Database operator/ (Database rightOne);
    Database ln ();
    Database log();
    //print database
    void print();
};

#endif // DATABASE_H
