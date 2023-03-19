#ifndef FILELIST_H
#define FILELIST_H

#include <QDialog>
#include <QVector>
#include "file.h"

namespace Ui {
class fileList;
}

class fileList : public QDialog
{
    Q_OBJECT

public:
    explicit fileList(QWidget *parent = nullptr);
    ~fileList();
    file getFile(int index);//using index to get the file
    void setFile(int index, file newFile);
    //void setupListOfFile(int numberOfFiles);
    void setupListofFile(QString fileName, QString fileFullPath);
    void setFileDisplayFlag(int index, bool newFlag);
    QVector<file> getListOfFile(){return ListOfFile;}
    void addOneFile(file *input, std::string newFileName);
    void changeFileColor(int index, QColor *color);
private:
    Ui::fileList *ui;
    QVector<file> ListOfFile;
    int numberOfFiles=0;
};

#endif // FILELIST_H
