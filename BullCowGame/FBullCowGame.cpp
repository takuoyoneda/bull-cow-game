//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by 米田 拓男 on 2017/08/30.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32) MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    const FString HIDDEN_WORD =  "donkey";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(false)
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false)
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
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
            
            if (Guess[j] == MyHiddenWord[i]) {
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

