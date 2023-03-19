#include "function.h"
#include "ui_function.h"

Function::Function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Function)
{
    ui->setupUi(this);
    constructComboBoxs();
}

Function::~Function()
{
    delete ui;
    delete result1;
    delete result2;
    delete result3;
}

void Function::constructComboBoxs(){
    //clear all comboBox items
    ui->A_Result1->clear();
    ui->symbol_Result1->clear();
    ui->B_Result1->clear();
    ui->A_Result2->clear();
    ui->symbol_Result2->clear();
    ui->B_Result2->clear();
    ui->A_Result3->clear();
    ui->symbol_Result3->clear();
    ui->B_Result3->clear();
    for(int i=0;i<listOfFile->getListOfFile().size();i++){
        ui->A_Result1->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
        ui->B_Result1->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
        ui->A_Result2->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
        ui->B_Result2->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
        ui->A_Result3->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
        ui->B_Result3->addItem(QString::fromStdString(listOfFile->getFile(i).getFileName()));
    }
    //construct symbol_Result1
    ui->symbol_Result1->addItem("+");
    ui->symbol_Result1->addItem("-");
    ui->symbol_Result1->addItem("x");
    ui->symbol_Result1->addItem("ln");
    ui->symbol_Result1->addItem("log");
    //construct symbol_Result2
    ui->symbol_Result2->addItem("+");
    ui->symbol_Result2->addItem("-");
    ui->symbol_Result2->addItem("x");
    ui->symbol_Result2->addItem("ln");
    ui->symbol_Result2->addItem("log");
    //construct symbol_Result3
    ui->symbol_Result3->addItem("+");
    ui->symbol_Result3->addItem("-");
    ui->symbol_Result3->addItem("x");
    ui->symbol_Result3->addItem("ln");
    ui->symbol_Result3->addItem("log");
    //construct 0 part and result1-3 objects
    ui->A_Result1->addItem("0");
    ui->A_Result1->addItem("Result1");
    ui->A_Result1->addItem("Result2");
    ui->A_Result1->addItem("Result3");
    ui->B_Result1->addItem("Result1");
    ui->B_Result1->addItem("Result2");
    ui->B_Result1->addItem("Result3");

    ui->A_Result2->addItem("0");
    ui->A_Result2->addItem("Result1");
    ui->A_Result2->addItem("Result2");
    ui->A_Result2->addItem("Result3");
    ui->B_Result2->addItem("Result1");
    ui->B_Result2->addItem("Result2");
    ui->B_Result2->addItem("Result3");

    ui->A_Result3->addItem("0");
    ui->A_Result3->addItem("Result1");
    ui->A_Result3->addItem("Result2");
    ui->A_Result3->addItem("Result3");
    ui->B_Result3->addItem("Result1");
    ui->B_Result3->addItem("Result2");
    ui->B_Result3->addItem("Result3");
}



file* Function::calucation(QString ResultNum ,QString A, QString symbol, QString B){
    file *result = new file(ResultNum.toStdString(), listOfFile->getListOfFile().size(), true);
    if(A == "0"){
        if(B=="Result1"){
            if(symbol=="ln"){
                result->setDatabase(result1->getDatabase().ln());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "ln("+Result1_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "ln("+Result1_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "ln("+Result1_function+")";
                }

            }
            else if(symbol=="log"){
                result->setDatabase(result1->getDatabase().log());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "log("+Result1_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "log("+Result1_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "log("+Result1_function+")";
                }
            }
            else{
                ui->messageLabel->setText("The symbol should be 'ln' or 'log' ");
            }
        }
        else if(B=="Result2"){
            if(symbol=="ln"){
                result->setDatabase(result2->getDatabase().ln());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "ln("+Result2_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "ln("+Result2_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "ln("+Result2_function+")";
                }
            }
            else if(symbol=="log"){
                result->setDatabase(result2->getDatabase().log());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "log("+Result2_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "log("+Result2_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "log("+Result2_function+")";
                }
            }
            else{
                ui->messageLabel->setText("The symbol should be 'ln' or 'log' ");
            }
        }
        else if(B=="Result3"){
            if(symbol=="ln"){
                result->setDatabase(result3->getDatabase().ln());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "ln("+Result3_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "ln("+Result3_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "ln("+Result3_function+")";
                }
            }
            else if(symbol=="log"){
                result->setDatabase(result3->getDatabase().log());
                //set function name
                if(ResultNum=="Result1"){
                    Result1_function = "log("+Result3_function+")";
                }
                if(ResultNum=="Result2"){
                    Result2_function = "log("+Result3_function+")";
                }
                if(ResultNum=="Result3"){
                    Result3_function = "log("+Result3_function+")";
                }
            }
            else{
                ui->messageLabel->setText("The symbol should be 'ln' or 'log' ");
            }
        }
        else{
            for(int i=0;i<listOfFile->getListOfFile().size();i++){
                if(listOfFile->getFile(i).getFileName()==B.toStdString()){
                    if(symbol=="ln"){
                        result->setDatabase(listOfFile->getFile(i).getDatabase().ln());
                        //set function name
                        if(ResultNum=="Result1"){
                            Result1_function = "ln("+listOfFile->getFile(i).getFileName()+")";
                        }
                        if(ResultNum=="Result2"){
                            Result2_function = "ln("+listOfFile->getFile(i).getFileName()+")";
                        }
                        if(ResultNum=="Result3"){
                            Result3_function = "ln("+listOfFile->getFile(i).getFileName()+")";
                        }
                    }
                    else if(symbol=="log"){
                        result->setDatabase(listOfFile->getFile(i).getDatabase().log());
                        //set function name
                        if(ResultNum=="Result1"){
                            Result1_function = "log("+listOfFile->getFile(i).getFileName()+")";
                        }
                        if(ResultNum=="Result2"){
                            Result2_function = "log("+listOfFile->getFile(i).getFileName()+")";
                        }
                        if(ResultNum=="Result3"){
                            Result3_function = "log("+listOfFile->getFile(i).getFileName()+")";
                        }
                    }
                    else{
                        ui->messageLabel->setText("The symbol should be 'ln' or 'log' ");
                    }
                }
            }
        }
    }
    //A = "Result1"
    else if(A == "Result1"){
        if(symbol=="ln"||symbol=="log"){
            ui->messageLabel->setText("no 'ln' and 'log' can be accepted here!");
        }
        else{
            if(B == "Result1"){
                if(symbol=="+"){
                    result->setDatabase(result1->getDatabase()+result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "+" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result1->getDatabase()-result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "-" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result1->getDatabase()*result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "x" + "("+Result1_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result2"){
                if(symbol=="+"){
                    result->setDatabase(result1->getDatabase()+result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "+" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result1->getDatabase()-result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "-" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result1->getDatabase()*result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "x" + "("+Result2_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result3"){
                if(symbol=="+"){
                    result->setDatabase(result1->getDatabase()+result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "+" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result1->getDatabase()-result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "-" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result1->getDatabase()*result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result1_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result1_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result1_function+")" + "x" + "("+Result3_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else{//B is data set
                for(int i=0;i<listOfFile->getListOfFile().size();i++){
                    if(listOfFile->getFile(i).getFileName()==B.toStdString()){
                        if(symbol=="+"){
                            result->setDatabase(result1->getDatabase()+listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result1_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result1_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result1_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(result1->getDatabase()-listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result1_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result1_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result1_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(result1->getDatabase()*listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result1_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result1_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result1_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else {
                            //do nothing
                        }
                    }
                }
            }

        }
    }
    //A = "Result2"
    else if(A == "Result2"){
        if(symbol=="ln"||symbol=="log"){
            ui->messageLabel->setText("no 'ln' and 'log' can be accepted here!");
        }
        else{
            if(B == "Result1"){
                if(symbol=="+"){
                    result->setDatabase(result2->getDatabase()+result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "+" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result2->getDatabase()-result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "-" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result2->getDatabase()*result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "x" + "("+Result1_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result2"){
                if(symbol=="+"){
                    result->setDatabase(result2->getDatabase()+result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "+" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result2->getDatabase()-result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "-" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result2->getDatabase()*result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "x" + "("+Result2_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result3"){
                if(symbol=="+"){
                    result->setDatabase(result2->getDatabase()+result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "+" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result2->getDatabase()-result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "-" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result2->getDatabase()*result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result2_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result2_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result2_function+")" + "x" + "("+Result3_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else{//B is data set
                for(int i=0;i<listOfFile->getListOfFile().size();i++){
                    if(listOfFile->getFile(i).getFileName()==B.toStdString()){
                        if(symbol=="+"){
                            result->setDatabase(result2->getDatabase()+listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result2_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result2_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result2_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(result2->getDatabase()-listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result2_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result2_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result2_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(result2->getDatabase()*listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result2_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result2_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result2_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else {
                            //do nothing
                        }
                    }
                }
            }

        }
    }

    //A = "Result3"
    else if(A == "Result3"){
        if(symbol=="ln"||symbol=="log"){
            ui->messageLabel->setText("no 'ln' and 'log' can be accepted here!");
        }
        else{
            if(B == "Result1"){
                if(symbol=="+"){
                    result->setDatabase(result3->getDatabase()+result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "+" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "+" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result3->getDatabase()-result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "-" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "-" + "("+Result1_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result3->getDatabase()*result1->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "x" + "("+Result1_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "x" + "("+Result1_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result2"){
                if(symbol=="+"){
                    result->setDatabase(result3->getDatabase()+result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "+" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "+" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result3->getDatabase()-result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "-" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "-" + "("+Result2_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result3->getDatabase()*result2->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "x" + "("+Result2_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "x" + "("+Result2_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else if(B=="Result3"){
                if(symbol=="+"){
                    result->setDatabase(result3->getDatabase()+result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "+" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "+" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="-"){
                    result->setDatabase(result3->getDatabase()-result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "-" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "-" + "("+Result3_function+")";
                    }
                }
                else if(symbol=="x"){
                    result->setDatabase(result3->getDatabase()*result3->getDatabase());
                    //set function name
                    if(ResultNum=="Result1"){
                        Result1_function = "("+Result3_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result2"){
                        Result2_function = "("+Result3_function+")" + "x" + "("+Result3_function+")";
                    }
                    if(ResultNum=="Result3"){
                        Result3_function = "("+Result3_function+")" + "x" + "("+Result3_function+")";
                    }
                }
                else {
                    //do nothing
                }
            }
            else{//B is data set
                for(int i=0;i<listOfFile->getListOfFile().size();i++){
                    if(listOfFile->getFile(i).getFileName()==B.toStdString()){
                        if(symbol=="+"){
                            result->setDatabase(result3->getDatabase()+listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result3_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result3_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result3_function+")" + "+" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(result3->getDatabase()-listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result3_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result3_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result3_function+")" + "-" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(result3->getDatabase()*listOfFile->getFile(i).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+Result3_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+Result3_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+Result3_function+")" + "x" + "("+listOfFile->getFile(i).getFileName()+")";
                            }
                        }
                        else {
                            //do nothing
                        }
                    }
                }
            }

        }
    }

    //A is a Data set
    else{
        for(int i=0;i<listOfFile->getListOfFile().size();i++){//for A
            if(listOfFile->getFile(i).getFileName()==A.toStdString()){
                for(int j=0;j<listOfFile->getListOfFile().size();j++){//for B
                    if(listOfFile->getFile(j).getFileName()==B.toStdString()){//B is one of the dataset
                        if(symbol=="+"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()+listOfFile->getFile(j).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()-listOfFile->getFile(j).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()*listOfFile->getFile(j).getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+listOfFile->getFile(j).getFileName()+")";
                            }
                        }
                        else {//ln or log
                            ui->messageLabel->setText("'ln' and 'log' not accepted");
                        }
                    }
                    else if(B=="Result1"){
                        if(symbol=="+"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()+result1->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result1_function+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()-result1->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result1_function+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()*result1->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result1_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result1_function+")";
                            }
                        }
                        else {//ln or log
                            ui->messageLabel->setText("'ln' and 'log' not accepted");
                        }
                    }
                    else if(B=="Result2"){
                        if(symbol=="+"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()+result2->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result2_function+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()-result2->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result2_function+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()*result2->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result2_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result2_function+")";
                            }
                        }
                        else {//ln or log
                            ui->messageLabel->setText("'ln' and 'log' not accepted");
                        }
                    }
                    else if(B=="Result3"){
                        if(symbol=="+"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()+result3->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "+" + "("+Result3_function+")";
                            }
                        }
                        else if(symbol=="-"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()-result3->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "-" + "("+Result3_function+")";
                            }
                        }
                        else if(symbol=="x"){
                            result->setDatabase(listOfFile->getFile(i).getDatabase()*result3->getDatabase());
                            //set function name
                            if(ResultNum=="Result1"){
                                Result1_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result2"){
                                Result2_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result3_function+")";
                            }
                            if(ResultNum=="Result3"){
                                Result3_function = "("+listOfFile->getFile(i).getFileName()+")" + "x" + "("+Result3_function+")";
                            }
                        }
                        else {//ln or log
                            ui->messageLabel->setText("'ln' and 'log' not accepted");
                        }
                    }
                }
            }
        }
    }

    return result;
}

void Function::plot(){
    int displaycount = 0;
    ui->customPlot_widget->clearGraphs();
    ui->customPlot_widget->legend->setVisible(true);
    if(result1->getDisplayFlag()==true){
        ui->customPlot_widget->addGraph();
        ui->customPlot_widget->graph(displaycount)->setData(result1->getDatabase().getx(),result1->getDatabase().gety());
        ui->customPlot_widget->graph(displaycount)->setName(QString::fromStdString(result1->getFileName()));
        displaycount++;
    }
    if(result2->getDisplayFlag()==true){
        ui->customPlot_widget->addGraph();
        ui->customPlot_widget->graph(displaycount)->setData(result2->getDatabase().getx(),result2->getDatabase().gety());
        ui->customPlot_widget->graph(displaycount)->setName(QString::fromStdString(result2->getFileName()));
        ui->customPlot_widget->graph(displaycount)->setPen(result2->getColor());
        displaycount++;
    }
    if(result3->getDisplayFlag()==true){
        ui->customPlot_widget->addGraph();
        ui->customPlot_widget->graph(displaycount)->setData(result3->getDatabase().getx(),result3->getDatabase().gety());
        ui->customPlot_widget->graph(displaycount)->setName(QString::fromStdString(result3->getFileName()));
        ui->customPlot_widget->graph(displaycount)->setPen(result3->getColor());
        displaycount++;
    }
    ui->customPlot_widget->rescaleAxes();
    ui->customPlot_widget->replot();

}

void Function::receiveListOfFile(fileList *listOfFile){
    this->listOfFile=listOfFile;
    constructComboBoxs();
    //clear register
    result1 = new file("Result1",listOfFile->getListOfFile().size(),false);
    result2 = new file("Result2",listOfFile->getListOfFile().size(),false);
    result3 = new file("Result3",listOfFile->getListOfFile().size(),false);
    plot();
}

void Function::on_Calucate_Result1_clicked()
{
    result1 = calucation("Result1",ui->A_Result1->currentText(),ui->symbol_Result1->currentText(),ui->B_Result1->currentText());
    result1->setDisplayFlag(true);
    plot();

}


void Function::on_Calucate_Result2_clicked()
{
    result2 = calucation("Result2",ui->A_Result2->currentText(),ui->symbol_Result2->currentText(),ui->B_Result2->currentText());
    result2->setDisplayFlag(true);
    result2->setColor(new QColor(255,255,0));
    plot();
}


void Function::on_Calucate_Result3_clicked()
{
    result3 = calucation("Result3",ui->A_Result3->currentText(),ui->symbol_Result3->currentText(),ui->B_Result3->currentText());
    result3->setDisplayFlag(true);
    result3->setColor(new QColor(255,0,255));
    plot();
}


void Function::on_Display_Result1_clicked()
{
    result1->setDisplayFlag(true);
    plot();
}


void Function::on_Hide_Result1_clicked()
{
    result1->setDisplayFlag(false);
    plot();
}


void Function::on_Display_Result2_clicked()
{
    result2->setDisplayFlag(true);
    plot();
}


void Function::on_Hide_Result2_clicked()
{
    result2->setDisplayFlag(false);
    plot();
}


void Function::on_Display_Result3_clicked()
{
    result3->setDisplayFlag(true);
    plot();
}


void Function::on_Hide_Result3_clicked()
{
    result3->setDisplayFlag(false);
    plot();
}


void Function::on_pushButton_clicked()
{
    this->displayFlagInMainWindows = true;//set it can be shwon
}
