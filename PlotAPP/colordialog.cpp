#include "colordialog.h"
#include "ui_colordialog.h"


ColorDialog::ColorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorDialog)
{
    ui->setupUi(this);
    constructCombobox();
    advanceFlag = false;
}

ColorDialog::~ColorDialog()
{
    delete ui;
    delete ListOfFile;
}

//Normal Functions:
void ColorDialog::constructCombobox(){
    QString dataSetName;
    ui->comboBox_Color->clear();
    ui->comboBox_DataSet->clear();
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        dataSetName = QString::fromStdString(ListOfFile->getFile(i).getFileName());
        ui->comboBox_DataSet->addItem(dataSetName);
    }
//    ui->comboBox_Color->addItem("Red");
//    ui->comboBox_Color->addItem("Green");
//    ui->comboBox_Color->addItem("Blue");

    QStringList colorList = QColor::colorNames();
    QString color;
    foreach(color,colorList)
    {
        QPixmap pix(QSize(70,20));
        pix.fill(QColor(color));
        ui->comboBox_Color->addItem(QIcon(pix),NULL);
        ui->comboBox_Color->setIconSize(QSize(70,20));
        ui->comboBox_Color->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void ColorDialog::receiveListOfFile(fileList *listOfFile){
    this->ListOfFile=listOfFile;
    constructCombobox();
}

//ACTIONS:
void ColorDialog::on_ColorDialog_accepted()
{
    dataSetName = ui->comboBox_DataSet->currentText();
    colorName = ui->comboBox_Color->currentText();
    QStringList colorList = QColor::colorNames();
    if(advanceFlag==false){
        color = new QColor(colorList[ui->comboBox_Color->currentIndex()]);
    }
    else{
        //don't change color
    }


}


void ColorDialog::on_AdvanceButton_clicked()
{
    color = new QColor(QColorDialog::getColor(Qt::white,this,"Get Color"));
    advanceFlag = true;
    on_ColorDialog_accepted();
}


void ColorDialog::on_comboBox_Color_currentIndexChanged(int index)
{
    advanceFlag = false;
}

