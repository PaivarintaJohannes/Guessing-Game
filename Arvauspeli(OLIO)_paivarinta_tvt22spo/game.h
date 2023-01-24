#ifndef GAME_H
#define GAME_H


class GameObject
{

public:

    GameObject(int a);

    ~GameObject();

    void play();

private:

    int maxNumber;
    double randomNumber;
    int playerGuess;
    int numOfGuesses;
    void getRandNum();
    void printGameResult();

};

#endif // GAME_H
