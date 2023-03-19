#ifndef FUNCTION_H
#define FUNCTION_H

#include <QDialog>
#include "filelist.h"

namespace Ui {
class Function;
}

class Function : public QDialog
{
    Q_OBJECT

public:
    explicit Function(QWidget *parent = nullptr);
    ~Function();

    void constructComboBoxs();
    void receiveListOfFile(fileList *listOfFile);
    file* calucation(QString ResultNum, QString A, QString symbol, QString B);//do calucation and return the file object
    void plot();
    bool getDisplayFlagInMainWindwos(){return displayFlagInMainWindows;}
    void setDisplayFlagInMainWindwos(bool input){this->displayFlagInMainWindows = input;}
    file* getResult1(){return result1;}
    file* getResult2(){return result2;}
    file* getResult3(){return result3;}
    std::string getResult1_function(){return Result1_function;}
    std::string getResult2_function(){return Result2_function;}
    std::string getResult3_function(){return Result3_function;}
private slots:
    void on_Calucate_Result1_clicked();

    void on_Calucate_Result2_clicked();

    void on_Calucate_Result3_clicked();

    void on_Display_Result1_clicked();

    void on_Hide_Result1_clicked();

    void on_Display_Result2_clicked();

    void on_Hide_Result2_clicked();

    void on_Display_Result3_clicked();

    void on_Hide_Result3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Function *ui;
    bool displayFlagInMainWindows = false;
    fileList *listOfFile = new fileList();
    file *result1 = new file("Result1",listOfFile->getListOfFile().size(),false);
    file *result2 = new file("Result2",listOfFile->getListOfFile().size(),false);
    file *result3 = new file("Result3",listOfFile->getListOfFile().size(),false);
    std::string Result1_function;
    std::string Result2_function;
    std::string Result3_function;
};

#endif // FUNCTION_H
