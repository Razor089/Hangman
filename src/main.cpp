#include <iostream>
#include "main.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** args)
{
    while(1)
    {
        mainMenu(choice);
        switch(choice)
        {
            case 0:
                cout << "Bye bye!" << endl;
                return 0;
            case 1:
                cout << "New Game" << endl;
                new Game();
                break;
            case 2:
                highScores();
                break;
            case 3:
                credits();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}

void mainMenu(int &choice)
{
   cout << "/**********************/" << endl;
   cout << "/*    HANGMAN GAME    */" << endl;
   cout << "/**********************/" << endl;
   cout << "/*                    */" << endl;
   cout << "/* 1) New Game        */" << endl;
   cout << "/* 2) High Scores     */" << endl;
   cout << "/* 3) Credits         */" << endl;
   cout << "/*                    */" << endl;
   cout << "/**********************/" << endl;   
   cout << "/* 0) Exit            */" << endl;
   cout << "/**********************/" << endl << endl;   
   cout << "-> ";
   cin >> choice;
}

void credits(void)
{
    cout << "/*********************/" << endl;
    cout << "/*                   */" << endl;
    cout << "/* Hangman Game      */" << endl;
    cout << "/* Ver 1.1           */" << endl;
    cout << "/*                   */" << endl;
    cout << "/* @Author           */" << endl;
    cout << "/* Cosimo Davide     */" << endl;
    cout << "/* Viggiano          */" << endl;
    cout << "/*                   */" << endl;
    cout << "/*********************/" << endl << endl;
}

void highScores(void)
{
    vector<string> scores;
    File *file = new File("high_scores.txt");
    scores = file->loadFile();
    //scores = order(scores);
    cout << endl;
    cout << "+-------------------+-------+" << endl;
    cout << "| NAME              | SCORE |" << endl;
    cout << "+-------------------+-------+" << endl;
    for(int i = 0; i < scores.size(); i += 2)
    {
        string nome = "| " + scores[i];
        while(nome.length() < 20)
        {
            nome += " ";
        }
        string points = "|   " + scores[i+1];
        while(points.length() < 8)
        {
            points += " ";
        }
        points += "|";
        cout << nome << points << endl;
    }
    cout << "+-------------------+-------+" << endl << endl;

}

vector<string> order(vector<string> list)
{
    vector<string> orderedList;
    int times = list.size()/2;
    for(int i = 0; i < times; i++)
    {
        cout << "Size: " << list.size() << endl;
        int numMax = max(list);
        cout << "PosMax: " << numMax << endl;
        string point = list[numMax];
        string name = list[numMax-1];
        orderedList.push_back(name);
        orderedList.push_back(point);
        cout << "Name: " << name << ", point: " << point << endl;
        list.erase(list.begin() + numMax);
        list.erase(list.begin() + numMax-1);
    }
    return orderedList;
}

int max(vector<string> list)
{
    int numMax = 1;
    for(int i = 3; i < list.size(); i += 2)
    {
        if(list[numMax] < list[i])
        {
            numMax = i;
        }
    }

    return numMax;
}
