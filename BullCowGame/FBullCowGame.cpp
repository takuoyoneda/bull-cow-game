//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by 米田 拓男 on 2017/08/30.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 5;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD =  "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
    return false;
}

// receives a VALID guess, incriments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
    // incriment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    BullCowCount BullCowCount;
    
    // loop through all lettewrs in the guess
        // compare letters against the hidden word
    
    return BullCowCount;
}

