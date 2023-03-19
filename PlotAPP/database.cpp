#include "database.h"
#include <iostream>
#include <string>
#include <QVector>
#include <math.h>
#include <QDebug>
#include <float.h>
#include <cmath>
#include <QtMath>
using namespace std;
Database::Database(int size){
    this->x.resize(size);
    this->y.resize(size);
    this->size = size;
}
void Database::setONEx(double in, int index){
    if (size == 0){
        x.resize(index+1);//resize vector in order to insert value
        y.resize(index+1);//resize vector in order to match with x vector
        size = index + 1;//record size value
        x[index] = in;//set x
        qWarning() << "The size of the database is zero. Please check it.";//through an warning
    }
    else{//size>0
        if(index < size){
            x[index] = in;
        }
        else{//index>=size
            qWarning() << "The index is out off the range of database size. Please check if there is any problem";
            x.resize(index+1);//resize vector in order to insert value
            y.resize(index+1);//resize vector in order to match with x vector
            size = index + 1;//record size value
            x[index] = in;
        }
    }
}
void Database::setONEy(double in, int index){
    if (size == 0){
        x.resize(index+1);//resize vector in order to match with y vector
        y.resize(index+1);//resize vector in order to insert value
        size = index + 1;//record size value
        y[index] = in;//set y
        qWarning() << "The size of the database is zero. Please check it.";//through an warning
    }
    else{//size>0
        if(index < size){
            y[index] = in;
        }
        else{//index>=size
            qWarning() << "The index is out off the range of database size. Please check if there is any problem";
            x.resize(index+1);//resize vector in order to match with y vector
            y.resize(index+1);//resize vector in order to insert value
            size = index + 1;//record size value
            y[index] = in;
        }
    }
}
double Database::getONEx(int index){
    if(index<size){
        return x[index];
    }
    else{
        qCritical() << "the index is out off the range of size";
        exit(1);//finish the program when this mistake happend
    }
}
double Database::getONEy(int index){
    if(index<size){
        return y[index];
    }
    else{
        qCritical() << "the index is out off the range of size";
        exit(1);//finish the program when this mistake happend
    }
}
int Database::getSize(){return size;}
QVector<double> Database::getx(){return x;}
QVector<double> Database::gety(){return y;}
//operators
Database Database::operator+(Database rightOne){
    Database output(this->size);
    if(rightOne.size == this->size && this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            output.y[i] = this->y[i] + rightOne.y[i];//add y
        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
Database Database::operator-(Database rightOne){
    Database output(this->size);
    if(rightOne.size == this->size && this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            output.y[i] = this->y[i] - rightOne.y[i];//substract y
        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
Database Database::operator*(Database rightOne){
    Database output(this->size);
    if(rightOne.size == this->size && this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            output.y[i] = this->y[i] * rightOne.y[i];//multiply y
        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
Database Database::operator/(Database rightOne){
    Database output(this->size);
    if(rightOne.size == this->size && this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            if(rightOne.y[i]!=0){
                output.y[i] = this->y[i] / rightOne.y[i];//divide y
            }
            else{//rightOne.y[i]==0
                //determine positive infinite or negative infinite
                if(this->y[i]<0){//negative situation
                    output.y[i] = -DBL_MAX;
                }
                else if(this->y[i]>0){//positive situation
                    output.y[i] = DBL_MAX;
                }
                else{//zero situation
                    output.y[i] = 0;
                }
            }
        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
Database Database::ln(){
    Database output(this->size);
    if(this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            if(this->y[i]>=0){
                output.y[i] = qLn(this->y[i]);//set y
            }
            else{
                qCritical() << "The database has negative numbers which causes ln cannot processing!";
                QMessageBox msgBox;
                msgBox.setText("The current database has negative numbers which causes 'ln()' cannot processing!\nThe programm will close!");
                msgBox.exec();
                exit(1);
            }

        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
Database Database::log(){
    Database output(this->size);
    if(this->size > 0){
        for(int i=0; i<size; i++){
            output.x[i] = this->x[i];
            if(this->y[i]>=0){
                output.y[i] = log10(this->y[i]);//set y
            }
            else{
                qCritical() << "The database has negative numbers which causes ln cannot processing!";
                QMessageBox msgBox;
                msgBox.setText("The databasee has negative numbers which causes 'ln()' cannot processing!\nThe program will exit!");
                msgBox.exec();
                exit(1);
            }
        }
        return output;
    }
    else{
        qCritical() << "The size of two databases are different or equal to zero!";
        QMessageBox msgBox;
        msgBox.setText("The size of two databases are different or equal to zero!\nThe program will exit!");
        msgBox.exec();
        exit(1);//program stop
    }
}
void Database::print(){
    for(int i=0;i<size;i++){
        qDebug()<<i<<": ("<<x[i]<<", "<<y[i]<<")";
    }
}
