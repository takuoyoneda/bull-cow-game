//
//  main.cpp
//  BullCowGame
//
//  Created by Takuo Yoneda on 2017/08/27.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

/* This is the console executable, that makes use of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all 
 user interaction. For game logic see the FBullCowGame class.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

//using FString = std::string;
//using int32 = int;

void PrintIntro();
void PlayGame();
FString GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int32 main(int32 argc, const char * argv[])
{
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    
    return 0;
}


void PrintIntro()
{
    // introduce the game
    constexpr int32 WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows, a fun game." << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    //std::cout << MaxTries << std::endl;
    
    for(int32 i = 1; i <= MaxTries; i++)
    {
        FString Guess = GetGuess(); // TODO: make loop cheking valid
        
        // submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
        std::cout << "Cows = " << BullCowCount.Cows << std::endl;
        
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
    
    // TODO: summarise game
}

FString GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    // get a guess from the player
    std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
    FString Guess = "";
    std::getline(std::cin,Guess);

    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n)";
    FString Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
