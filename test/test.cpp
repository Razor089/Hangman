#include <iostream>
#include <string>
#include "game.h"
#include "file.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, const char** argv)
{
    File *file = new File("words.txt");
    Game *game = new Game("test");

    /* Test lettura da file */
    cout << "Test Lettura da File" << endl;
    vector<string> lista = file->loadFile();
    if(lista.size() > 0) cout << "SUCCESSO" << endl;
    else cout << "FALLITO" << endl;
    cout << "Test elementi caricati da file" << endl;
    if(lista.size() == 10) cout << "SUCCESSO" << endl;
    else cout << "FALLITO" << endl;

    /* Test nuova parola */
    cout << "Test nuova parola" << endl;
    string word = game->loadWord();
    if(word.length() > 0) cout << "SUCCESSO" << endl;
    else cout << "FALLITO" << endl; 
}
