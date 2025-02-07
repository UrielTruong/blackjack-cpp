#ifndef READFILE_H
#define READFILE_H

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// req: tao 1 class readfile => de su dung chung => write/read file theo 1 format
// input: path
// output: 2 methods read and write
// step:
// todo 1: constructor readFile (path){ifstream - save path}
// todo 2:

class FileAction
{
public: // constructor
    FileAction(string path)
    {
        this->path = path;
    };

public: // attributes
    string path;

public: // methods
    string read()
    {
        string fileContent;
        string fileResult;
        // todo: connect path
        ifstream read(path);

        // todo: read file line by line - while => concat fileContent
        while (getline(read, fileContent))
        {
            fileResult += fileContent;
        }
        // todo: close connection
        read.close();
        return fileResult;
    }

    void write(string save) // assign (truyền) a param "save" into a function to save a file
    {
        // todo: connect path (create / open file) ofstream
        ofstream write(path);

        // todo: write to file
        write << save;
        // todo: close connection
        write.close();
    }

    void append(string newSave)
    {
        ofstream write(path, ios::app);

        write << newSave;
        write.close();
    }

    void writeVector(vector<Card> arrayString, bool isAppend = false)
    {
        // vector {"1. K Heart", "2. 3 Heart"}
        // loop a vector
        // save each element into file
        if (isAppend)
        {
            ofstream write(path, ios::app);

            for (int i = 0; i < arrayString.size(); i++)
            {
                write << arrayString[i].toString() << "\n";
            }

            write.close();

            return;
        }

        ofstream write(path);

        for (int i = 0; i < arrayString.size(); i++)
        {
            write << arrayString[i].toString() << "\n";
        }

        write.close();
    }
};

#endif // READFILE_H

// main
// ReadFile file('saveGame.txt")
// string fileContent = file.read();
// string save ="abc,,,,";
// file.write(save);

// tạo conn
// int count = 0;
// while (getLine(....))
// if count == 2 -> break;
// đọc file
// count++