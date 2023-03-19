#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdialog.h"
#include <QMainWindow>
#include <QDebug>
#include <QMenu>
#include <QContextMenuEvent>
#include "file.h"
#include "filelist.h"
#include <QVector>
#include <QFile>
#include <QFileDialog>
#include "colordialog.h"
#include "choosedatasets.h"
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printPlot();//Plot the graph of the data sets.
    //void setupFileList(int numberOfFiles);//initiallize fileList at first.
    void ConstructContextMenu();// initiallize context menu
    void contextMenuEvent(QContextMenuEvent *event);//dealing with Context Menu Event
    bool checkFile(std::string file_fullPath, std::string file_name);//check whether the file in the standard type

private slots:
    void on_actionSave_triggered();

    void on_actionChange_color_triggered();

    void on_customplot_Widget_customContextMenuRequested(const QPoint &pos);

    void on_actionChoose_data_triggered();

    void on_actionFunction_triggered();

    void on_actionLoad_file_triggered();

private:
    Ui::MainWindow *ui;
    fileList *ListOfFile = new fileList();
    //build color dialog
    ColorDialog *ColorDlg = new ColorDialog();
    //build context menu
    QMenu *contextMenu = new QMenu();
    ChooseDataSets *ChooseDS = new ChooseDataSets();
    Function *FunctionDS = new Function();
};
#endif // MAINWINDOW_H
