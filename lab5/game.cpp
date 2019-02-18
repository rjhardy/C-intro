#include <iostream>
#include <ctime>

using namespace std;



int rolldie()   {
    int number = rand()%6;
    return number;
}

bool playOneGame()   {
    int numGuess;
    int i;
    int numChoice;

    cout << "Enter a number 1-6" << endl;
    cin >> numChoice;

    for(i = 0; i < 3; ++i)   {

         numGuess = rolldie();

        if(numGuess  == numChoice)   {
            cout << "You Win" << endl;
            return true;
        }
        else   {
            cout << "You Lose" << endl;
        }
    }
    return false;
}

int finalbalance(int wager)   {
    int balance;

    balance = 100;
    if(playOneGame() == true)   {
       balance = balance + wager;
       return balance;
    }
    else {
       balance = balance - wager;
       return balance;
    }
}


void playTheGame(int wager)   {
    int x;
    int numWins;
    int numLosses;
    numWins = 0;
    numLosses = 0;
    do {
                                    //removing the firstncall to playOneGame() which fixed the repeated calls
    if(playOneGame() == true)   {
        numWins = numWins + 1;
    }else   {
        numLosses = numLosses + 1;
    }
    cout << "Number of Wins " << numWins << endl;
    cout << "Number of Losses " << numLosses << endl;

    cout << finalbalance(wager) << endl;

    cout << "give x. 0 ends the game. any other integer continues the game "<<endl;
    cin >> x;
    }while(x!=0);
}

int main()   {
    srand(time(0));

    int wager;

    cout << "Enter your wager" << endl;
    cin >> wager;

    finalbalance(wager);
    playTheGame(wager);

}
