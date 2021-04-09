/****************************************/
/* Implementation of the File.cpp class */
/*                                      */
/* @Author Cosimo Davide Viggiano       */
/****************************************/

/* Includes */
#include "file.h"

File::File(string nomeFile)
{
    this->nomeFile = nomeFile;
}


void File::saveFile(string nome, int score)
{
    ofstream myfile;
    myfile.open("res/high_scores.txt", ofstream::out | ofstream::app);
    if(myfile.is_open())
    {
        myfile << nome << endl;
        myfile << score << endl;
        myfile.close();
    }
    else
    {
        cout << "Errore nel salvataggio del file." << endl;
    }
}

vector<string> File::loadFile()
{
    vector<string> listWords;
    ifstream myfile("res/" + this->nomeFile);
    if(myfile.is_open())
    {
        string line;
        while(getline(myfile, line))
        {
            listWords.push_back(line);
        }
        myfile.close();
    }
    return listWords;
}
