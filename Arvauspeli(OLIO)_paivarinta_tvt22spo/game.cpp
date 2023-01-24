#include "game.h"
#include <iostream>
#include <ostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

GameObject::GameObject(int a)
{
    getRandNum();
    maxNumber = a;
    cout<<"GAME CONSTRUCTOR: Object initialized with "<<maxNumber<<" as a maximum value."<<endl;

};
GameObject::~GameObject()
{
cout<<"GAME DESTRUCTOR: Object cleared from stack memory."<<endl;
}

void GameObject::play()
{
cout<<"Guess a number between 1-"<<maxNumber<<endl;
while(playerGuess != randomNumber){
    cin>>playerGuess;
    if(cin.fail()) {
        cout<<"Invalid input, please input a valid number."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    numOfGuesses++;

    if(playerGuess > randomNumber){
        cout<<"You guessed too high!"<<endl;
    }
    else if(playerGuess < randomNumber){
        cout<<"You guessed too low!"<<endl;
    }
    else{
        printGameResult();
    }
};
}

void GameObject::getRandNum()
{
    int f=time(NULL);
    srand(f);
    randomNumber = rand()%maxNumber+1;
};

void GameObject::printGameResult()
{
    cout<<"You guessed the right answer = "<<randomNumber<<" with "<<numOfGuesses<<" attempts."<<endl;
    numOfGuesses=0;
}

