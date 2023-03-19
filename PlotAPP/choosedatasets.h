#ifndef CHOOSEDATASETS_H
#define CHOOSEDATASETS_H

#include <QDialog>
#include <QStringListModel>
#include <QModelIndex>
#include "filelist.h"

namespace Ui {
class ChooseDataSets;
}

class ChooseDataSets : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDataSets(QWidget *parent = nullptr);
    ~ChooseDataSets();

    void constructListWidiget();

    void constructComboBox();

    fileList* getListOfFile(){return ListOfFile;}

    void receiveListOfFile(fileList *ListOfFile);
private slots:
    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_ChooseDataSets_accepted();

private:
    Ui::ChooseDataSets *ui;
    QStringListModel *Model;
    fileList *ListOfFile = new fileList();
};

#endif // CHOOSEDATASETS_H
