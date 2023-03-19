#include <iostream>
#include <fstream>
#include <QDebug>
#include "database.h"
#include <string>
#include <QVector>
#include <math.h>
#include <float.h>
#include <cmath>
#include <QtMath>
#include <QColor>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
//using namespace std;

#ifndef FILE_H
#define FILE_H
class file
{
private:
    std::string fileName;
    int lineNumber;//the number of lines
    Database DB;
    QColor *color = new QColor(250,0,0);//set it to be "red" at first
    bool displayFlag = true;

public:
    file(){};//default constructor
    file(std::string fileName);//using fileName to construct file object and process database
    file(std::string fileName, int lineNumber, bool displayFlag);
    std::string getFileName();//get file name
    void setFileName(std::string fileName);//set the name of the file
    void setOnlyFileName(std::string fileName){this->fileName=fileName.substr(0,fileName.find_last_of("."));}
    Database getDatabase();//get database
    void setDatabase(Database newDB){this->DB = newDB;}
    int getNumberofLines();//get how many lines this file has
    void FunctionNameAsFileName(std::string functionName){this->fileName = functionName;}

    void print();//show the file object
    //void changeColor(QString colorName);//change the color by using the input color name
    QColor getColor(){return *color;}
    void setColor(QColor* color){this->color=color;}
    void setDisplayFlag(bool input);
    bool getDisplayFlag(){return displayFlag;}
};

#endif // FILE_H
