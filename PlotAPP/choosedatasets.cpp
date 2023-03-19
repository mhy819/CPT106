#include "choosedatasets.h"
#include "ui_choosedatasets.h"

ChooseDataSets::ChooseDataSets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseDataSets)
{
    ui->setupUi(this);
    constructComboBox();
    constructListWidiget();

}

ChooseDataSets::~ChooseDataSets()
{
    delete ui;
    delete Model;
    delete ListOfFile;
}

void ChooseDataSets::constructListWidiget(){
    QStringList strlist;
    QString fileName;
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        if(ListOfFile->getFile(i).getDisplayFlag()){
            strlist.append(QString::fromStdString(ListOfFile->getFile(i).getFileName()));
        }
    }
    Model = new QStringListModel(strlist);//QStringListModel makes QStringListbe packaged.
    ui->listView->setModel(Model);        //insert into the listview
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void ChooseDataSets::constructComboBox(){
    QString dataSetName;
    ui->graphSelected->clear();
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        dataSetName = QString::fromStdString(ListOfFile->getFile(i).getFileName());
        ui->graphSelected->addItem(dataSetName);
    }
}

void ChooseDataSets::receiveListOfFile(fileList *listOfFile){
    this->ListOfFile=listOfFile;
    constructComboBox();
    constructListWidiget();
}

void ChooseDataSets::on_insertButton_clicked()
{
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        if(ui->graphSelected->currentText()==QString::fromStdString(ListOfFile->getFile(i).getFileName())&&(ListOfFile->getFile(i).getDisplayFlag()==false)){
            ListOfFile->setFileDisplayFlag(i,true);
        }
    }
    constructListWidiget();
}


void ChooseDataSets::on_deleteButton_clicked()
{
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        if(ui->graphSelected->currentText()==QString::fromStdString(ListOfFile->getFile(i).getFileName())&&(ListOfFile->getFile(i).getDisplayFlag()==true)){
            ListOfFile->setFileDisplayFlag(i,false);
        }
    }
    constructListWidiget();
}


void ChooseDataSets::on_ChooseDataSets_accepted()
{

}


