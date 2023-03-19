#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->customplot_Widget);
    ConstructContextMenu();
    printPlot();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ListOfFile;
    delete ColorDlg;
    delete contextMenu;
    delete ChooseDS;
    delete FunctionDS;
}
//Normal Functions

void MainWindow::printPlot(){
    int countDisplaySets = 0;
    QString fileName;
    ui->customplot_Widget->clearGraphs();
    ui->customplot_Widget->legend->setVisible(true);
    ui->customplot_Widget->legend->setBrush(QColor(255, 255, 255, 150));
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        if(ListOfFile->getFile(i).getDisplayFlag()){//if it is true, works
            fileName = QString::fromStdString(ListOfFile->getFile(i).getFileName());
            //fileName = QString::number(i);
            ui->customplot_Widget->addGraph();
            ui->customplot_Widget->graph(countDisplaySets)->setData(ListOfFile->getFile(i).getDatabase().getx(),ListOfFile->getFile(i).getDatabase().gety());
            ui->customplot_Widget->graph(countDisplaySets)->setName(fileName);
            ui->customplot_Widget->graph(countDisplaySets)->setPen(QColor(ListOfFile->getFile(i).getColor()));
            countDisplaySets++;
        }
    }
    ui->customplot_Widget->xAxis->setLabel("x");
    ui->customplot_Widget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customplot_Widget->rescaleAxes();
    ui->customplot_Widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectAxes);
    ui->customplot_Widget->replot();
}
//Construct Context Menu
void MainWindow::ConstructContextMenu(){
    contextMenu->addAction(ui->actionSave);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionLoad_file);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionChange_color);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionChoose_data);
    contextMenu->addSeparator();
    contextMenu->addAction(ui->actionFunction);
}

//check the form of file
bool MainWindow::checkFile(string file_fullPath, string file_name){
    bool result = true;
    double Dx,Dy;
    //set number of lines
    string line;
    int LineNumCount = 1;
    ifstream fin(file_fullPath);//open the file data.csv
    while (true)
    {
        getline(fin, line);
        if (fin.eof() != 0) {
            fin.close();
            break;
        }
        else {
            LineNumCount++;
        }
    }
    //check whether there is a same name file in the ListOfFile
    for(int i=0;i<ListOfFile->getListOfFile().size();i++){
        if(ListOfFile->getFile(i).getFileName()==file_name.substr(0,file_name.find("."))){
            result = false;
            QMessageBox msgBox;
            msgBox.setText("The file name has already loaded, please check!");
            msgBox.exec();
            break;
        }
        else{
            //do nothing
        }
    }
    //set database
    ifstream infile(file_fullPath);
    string x,y;
    for(int i=0;i<LineNumCount;i++){
        try {
            getline(infile, x, '\t');
            getline(infile, y);
            Dx = stod(x);
            Dy = stod(y);
        } catch (...) {
            result = false;
            QMessageBox msgBox;
            msgBox.setText("The file has the wrong form!!!!");
            msgBox.exec();
            break;
        }

    }
    return result;
}


//ACTIONS:
void MainWindow::contextMenuEvent(QContextMenuEvent *event){
    contextMenu->popup(event->globalPos());
}

void MainWindow::on_customplot_Widget_customContextMenuRequested(const QPoint &pos)
{
    contextMenu->popup(ui->customplot_Widget->mapToGlobal(pos));
}

void MainWindow::on_actionSave_triggered()
{
    QString file_fullPath, file_name;
    QFileInfo fileinfo;
    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptSave);
    file_fullPath = fileDlg.getSaveFileName(this,tr("Save image"),"untitled.jpg",tr( "Images (*.jpg)" ));
    if(file_fullPath.isEmpty()==false){
        ui->customplot_Widget->saveJpg(file_fullPath,  0, 0, 1.0, -1);
    }
    else{
        //do nothing
    }

}



void MainWindow::on_actionChange_color_triggered()
{
    ColorDlg->receiveListOfFile(ListOfFile);
    if(ColorDlg->exec()==QDialog::Accepted){
        QString fileName;
        for(int i=0; i<ListOfFile->getListOfFile().size();i++){
            fileName = QString::fromStdString(ListOfFile->getFile(i).getFileName());
            if(ColorDlg->getDataSetName()==fileName){
                //ListOfFile->getFile(i).changeColor(ColorDlg->getColorName());
                ListOfFile->changeFileColor(i,ColorDlg->getColor());
            }
        }
        ui->statusbar->showMessage("Changed");
        ui->customplot_Widget->clearGraphs();
        printPlot();
    }
}





void MainWindow::on_actionChoose_data_triggered()
{
    ChooseDS->receiveListOfFile(ListOfFile);
    if(ChooseDS->exec()==QDialog::Accepted){
        ListOfFile = ChooseDS->getListOfFile();
        ui->statusbar->showMessage("Choosed Data set is accepted!");
        ui->customplot_Widget->clearGraphs();
        printPlot();
    }
}


void MainWindow::on_actionFunction_triggered()
{
    FunctionDS->receiveListOfFile(ListOfFile);
    //FunctionDS->exec();
    if(FunctionDS->exec()==QDialog::Accepted){
        if(FunctionDS->getDisplayFlagInMainWindwos()){//==true then display result in the MainWindows customplot
            if(FunctionDS->getResult1()->getDisplayFlag()==true){
                ListOfFile->addOneFile(FunctionDS->getResult1(),FunctionDS->getResult1_function());
            }
            if(FunctionDS->getResult2()->getDisplayFlag()==true){
                ListOfFile->addOneFile(FunctionDS->getResult2(),FunctionDS->getResult2_function());
            }
            if(FunctionDS->getResult3()->getDisplayFlag()==true){
                ListOfFile->addOneFile(FunctionDS->getResult3(),FunctionDS->getResult3_function());
            }
            printPlot();
        }
    }
    else{
        //do nothing
    }
}


void MainWindow::on_actionLoad_file_triggered()
{
    QString file_fullPath, file_name;
    QFileInfo fileinfo;
    file_fullPath = QFileDialog::getOpenFileName(this,"Load a file");
    fileinfo = QFileInfo(file_fullPath);
    file_name = fileinfo.fileName();

    if(file_fullPath.isEmpty()==false){
        if(checkFile(file_fullPath.toStdString(), file_name.toStdString())==false){
            qDebug()<<"false!!!!!";
        }
        else{
            ListOfFile->setupListofFile(file_name,file_fullPath);
            printPlot();
        }
    }
    else{
        QMessageBox::critical(this, tr("Warning"),  tr("No file loading"), QMessageBox::Discard);
    }
}

