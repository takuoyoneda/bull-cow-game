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
FString GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
    std::cout << "\n\nWelcome to Bulls and Cows, a fun game.\n" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FString Guess = GetValidGuess(); // TODO: make loop cheking valid
        
        // submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls << ". ";
        std::cout << "Cows = " << BullCowCount.Cows << "\n\n";
    }
    
    PrintGameSummary();
    
    return;
}

FString GetValidGuess()
{
    FString Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
        std::getline(std::cin,Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
                
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
                
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
                break;
                
            default:
                return Guess;
        }
        
        std::cout << std::endl;
        
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word? (y/n)";
    FString Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
    if(BCGame.IsGameWon())
    {
        std::cout << "WELL DONE - YOU WIN!\n";
    }
    else
    {
        std::cout << "Better luck next time!\n";
    }
    
}
