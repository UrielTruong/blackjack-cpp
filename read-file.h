#ifndef READFILE_H
#define READFILE_H

#include <string>
#include <fstream>

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

    void write(string save)
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