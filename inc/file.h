/**********************************/
/* Declaration of File.h class    */
/*                                */
/* @Author Cosimo Davide Viggiano */
/**********************************/

#ifndef FILE_H
#define FILE_H

/* Includes */
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

class File
{
    private:
        string nomeFile;

    public:
        File(string nomeFile);
        ~File();
        void saveFile(string nome, int score);
        vector<string> loadFile();
};

#endif
