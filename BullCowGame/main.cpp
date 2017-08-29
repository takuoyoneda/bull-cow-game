//
//  main.cpp
//  BullCowGame
//
//  Created by Takuo Yoneda on 2017/08/27.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PrintGame();
string GetGuess();
bool AskToPlayAgain();


// the entry point for our application
int main(int argc, const char * argv[])
{
    PrintIntro();
    PrintGame();
    AskToPlayAgain();
    return 0;
}


void PrintIntro()
{
    // introduce the game
    constexpr int WORLD_LENGTH = 5;
    cout << "Welcome to Bulls and Cows, a fun game." << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram I'm thinking of?" << endl;
    cout << endl;
    return;
}

void PrintGame()
{
    constexpr int NUMBER_OF_TURNS = 5;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        string Guess = GetGuess();
        
        // repeat the guess back to them
        cout << "Your guess was: " << Guess << endl;
        cout << endl;
    }
}

string GetGuess()
{
    // get a guess from the player
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin,Guess);

    return Guess;
}

bool AskToPlayAgain(){
    return false;
}
