#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include <QColor>
#include "file.h"
#include "filelist.h"
#include <QColorDialog>


namespace Ui {
class ColorDialog;
}

class ColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorDialog(QWidget *parent = nullptr);
    ~ColorDialog();
    void constructCombobox();
    QString getDataSetName(){return dataSetName;}
    QString getColorName(){return colorName;}
    QColor* getColor(){return color;}
    void receiveListOfFile(fileList *listOfFile);


private slots:
    void on_ColorDialog_accepted();

    void on_AdvanceButton_clicked();

    void on_comboBox_Color_currentIndexChanged(int index);

private:
    Ui::ColorDialog *ui;
    QString dataSetName;//store the changed data set name
    QString colorName;//store the changed color name
    fileList *ListOfFile = new fileList();//store the list of file
    QColor *color;
    bool advanceFlag = false;
};

#endif // COLORDIALOG_H
