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
    
    const FString HIDDEN_WORD =  "ant";
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // incriment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    int32 HiddenWordLength = int32(MyHiddenWord.length());
    
    for (int32 i = 0; i < HiddenWordLength; i++)
    {
        for(int32 j = 0; j < HiddenWordLength; j++)
        {
            
            if (Guess[i] == MyHiddenWord[i]) {
                if (i == j)
                {
                    BullCowCount.Bulls++;
                }
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}

