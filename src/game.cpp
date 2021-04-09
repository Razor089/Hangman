/**************************************/
/* Implementation of the Game.h class */
/*                                    */
/* @Author Cosimo Davide Viggiano     */
/**************************************/

#include "game.h"

Game::Game()
{
    this->score = 0;
    this->errors = 0;
    this->gameOver = false;

    File *file = new File("words.txt");
    this->wordList = file->loadFile();
    
    this->createPlayer();

    cout << endl;
    cout << "Benvenuto/a " << player->getName() << endl;
    this->difficulty = setDifficulty();
    this->play();
}

Game::Game(string name)
{
    this->score = 0;
    this->errors = 0;
    this->gameOver = false;
    File *file = new File("words.txt");
    this->wordList = file->loadFile();    
}

Game::~Game()
{
    this->player->~Player();
}

void Game::createPlayer()
{
    string name;

    cout << "Inserire il nome del giocatore" << endl;
    cin >> name;
    this->player = new Player(name);
}

int Game::setDifficulty()
{
    int difficulty;
    cout << "Inserisci la difficolta'" << endl;
    cout << "------------------------" << endl;
    cout << " 1 - EASY" << endl;
    cout << " 2 - NORMAL" << endl;
    cout << " 3 - HARD" << endl;
    cout << "------------------------" << endl;
    cout << "-> ";
    cin >> difficulty;

    while(difficulty < EASY || difficulty > HARD)
    {
        cout << "Errore! Scelta non valida, riprovare -> ";
        cin >> difficulty;
    }
   
    return difficulty;
}

void Game::play()
{
    int times;
    
    switch(this->difficulty)
    {
        case EASY:
            times = 3;
            break;
        case NORMAL:
            times = 5;
            break;
        case HARD:
            times = 8;
            break;
    }

    for(int i = 1; i < times-1; i++)
    {
        this->word = loadWord();
        this->initializeGuessWord();
        this->errors = 0;
        this->letters.clear();
        while(true)
        {
            display();
            displayWord();
            if(this->errors == 6)
            {
                this->gameOver = true;
                break;
            }
            if(checkWord())
            {
                cout << "Bravissimo/a hai indovinato!" << endl;
                break;
            }
        }

        if(this->gameOver)
        {
            cout << endl; 
            cout << "**********************" << endl;
            cout << "* Peccato hai perso! *" << endl;
            cout << "**********************" << endl;
            break;
        }
    }

    if(!(this->gameOver))
    {
        cout << endl; 
        cout << "*************************" << endl;
        cout << "* Hai vinto la partita! *" << endl;
        cout << "*************************" << endl;
    }
    if(this->score > 0)
    {
        this->saveScores(this->player->getName(), this->score);
    }
}

void Game::saveScores(string name, int score)
{
    File *file = new File("high_scores.txt");
    file->saveFile(name, score);
}

bool Game::used(char c)
{
    if(this->letters.size() > 0)
    {
        for(int i = 0; i < this->letters.size(); i++)
        {
            if(c == this->letters[i]) return true;
        }
    }
    letters.push_back(c);
    return false;
}

bool Game::checkWord()
{
    char c;
    cout << "-> ";
    cin >> c;
    
    while(this->used(c))
    {
        cout << endl;
        cout << "Lettera gia' usata!" << endl;
        cout << "-> ";
        cin >> c;
    }

    bool found = false;
    for(int i = 0; i < this->word.length(); i++)
    {
        if(c == word[i])
        {
            found = true;
            this->guess_word[i] = c;
        }
    }

    if(!found) this->errors++;
    if(this->word == this->guess_word)
    {
        this->score++;
        return true;
    }
    return false;
}

void Game::initializeGuessWord()
{
    this->guess_word = "";
    for(int i = 0; i < this->word.length(); i++)
    {
        this->guess_word += "_";
    }
}

void Game::displayWord()
{
    for(int i = 0; i < this->guess_word.length(); i++)
    {
        cout << guess_word[i] << " ";
    }
    cout << endl;
}

string Game::loadWord()
{
    string word;
    int num;

    srand(time(NULL));
   
    num = rand() % this->wordList.size();
    word = this->wordList[num];
    this->wordList.erase(this->wordList.begin() + num);

    return word;
}

void Game::display()
{
  cout << endl;
  cout << "*************" << endl;
  cout << "* SCORE: " << this->score << "  *" << endl;
  cout << "*************" << endl;

  switch(this->errors)
  {
      case 0:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 1:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 2:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 3:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                   /|    |  *" << endl;
          cout << "*                  / |    |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 4:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                   /|\\   |  *" << endl;
          cout << "*                  / | \\  |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*                         |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 5:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                   /|\\   |  *" << endl;
          cout << "*                  / | \\  |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   /     |  *" << endl;
          cout << "*                  /      |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
      case 6:
          cout << "******************************" << endl;
          cout << "*                    ------  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   ( )   |  *" << endl;
          cout << "*                   /|\\   |  *" << endl;
          cout << "*                  / | \\  |  *" << endl;
          cout << "*                    |    |  *" << endl;
          cout << "*                   / \\   |  *" << endl;
          cout << "*                  /   \\  |  *" << endl;
          cout << "*               __________|_ *" << endl;
          cout << "*               |         |  *" << endl;
          cout << "******************************" << endl;
          break;
  }
}
