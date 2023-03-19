#include "file.h"
using namespace std;

file::file(string fileName){
    this->fileName = fileName.substr(0,fileName.find_last_of("."));
    //set number of lines
    string line;
    int count = 1;
    ifstream fin(fileName);//open the file data.csv
    while (true)
    {
        getline(fin, line);
        if (fin.eof() != 0) {
            fin.close();
            lineNumber = count;//set lineNumber
            break;
        }
        else {
            count++;
        }
    }
    //set database
    ifstream infile(fileName);
    string x,y;
    for(int i=0;i<lineNumber;i++){
        getline(infile, x, '\t');
        getline(infile, y);
        DB.setONEx(stod(x),i);
        DB.setONEy(stod(y),i);
    }
}
file::file(std::string fileName, int lineNumber, bool displayFlag){
    this->fileName = fileName;
    this->lineNumber = lineNumber;
    this->displayFlag = displayFlag;
}
string file::getFileName(){return fileName;}
Database file::getDatabase(){return DB;}
int file::getNumberofLines(){return lineNumber;}
void file::setFileName(std::string fileName){
    this->fileName = fileName.substr(0,fileName.find_last_of("."));
    //set number of lines
    string line;
    int count = 1;
    ifstream fin(fileName);//open the file data.csv
    while (true)
    {
        getline(fin, line);
        if (fin.eof() != 0) {
            fin.close();
            lineNumber = count;//set lineNumber
            break;
        }
        else {
            count++;
        }
    }
    //set database
    ifstream infile(fileName);
    string x,y;
    for(int i=0;i<lineNumber;i++){
        getline(infile, x, '\t');
        getline(infile, y);
        DB.setONEx(stod(x),i);
        DB.setONEy(stod(y),i);
    }
}
void file::print(){
    cout << "File Name: " <<fileName<<std::endl;
    cout << "Number of Lines: "<<lineNumber<<std::endl;
    DB.print();
}

void file::setDisplayFlag(bool input){
    displayFlag = input;
}

