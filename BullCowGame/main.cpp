//
//  main.cpp
//  BullCowGame
//
//  Created by Takuo Yoneda on 2017/08/27.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game


// the entry point for our application
int main(int argc, const char * argv[])
{
    do
    {
        PrintIntro();
        PlayGame();
    }
    while (AskToPlayAgain());
    
    return 0;
}


void PrintIntro()
{
    // introduce the game
    constexpr int WORLD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
    std::cout << "Can you guess the " << WORLD_LENGTH;
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
    
    constexpr int NUMBER_OF_TURNS = 5;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        std::string Guess = GetGuess();
        
        // repeat the guess back to them
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();
    
    // get a guess from the player
    std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
    std::string Guess = "";
    std::getline(std::cin,Guess);

    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n)";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
