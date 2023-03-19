#include "filelist.h"
#include "ui_filelist.h"

fileList::fileList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileList)
{
    ui->setupUi(this);
    //setupListOfFile(3);
}

fileList::~fileList()
{
    delete ui;
}

file fileList::getFile(int index){
    return ListOfFile[index];
}

void fileList::setFile(int index, file newFile){
    ListOfFile[index] = newFile;
}

void fileList::setupListofFile(QString fileName, QString fileFullPath){
    numberOfFiles++;
    ListOfFile.resize(numberOfFiles);
    file *newFile = new file(fileFullPath.toStdString());
    ListOfFile[numberOfFiles-1] = *newFile;
    ListOfFile[numberOfFiles-1].setOnlyFileName(fileName.toStdString());
}

void fileList::setFileDisplayFlag(int index, bool newFlag){
    ListOfFile[index].setDisplayFlag(newFlag);
}
void fileList::addOneFile(file *input, std::string newFileName){
    ListOfFile.resize(ListOfFile.size()+1);
    ListOfFile[ListOfFile.size()-1] = *input;
    ListOfFile[ListOfFile.size()-1].FunctionNameAsFileName(newFileName);
}

void fileList::changeFileColor(int index, QColor *color){
    ListOfFile[index].setColor(color);
}
