//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by 米田 拓男 on 2017/08/30.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

//#pragma once

#include "FBullCowGame.hpp"
#include <map>

// to make syntax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32) MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries
    {
        {3,4},{4,7},{5,10},{6,16},{7,20}
    };
    
    return WordLengthToMaxTries[(int32)MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
    const FString HIDDEN_WORD =  "last"; // this MUST be an isogram
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if(!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess))
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    
    int32 WordLength = int32(MyHiddenWord.length());
    
    for (int32 i = 0; i < WordLength; i++)
    {
        for(int32 j = 0; j < WordLength; j++)
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
    
    if(BullCowCount.Bulls == WordLength)
    {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }
    
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    if(Word.length() <= 1) { return true; }
    
    TMap<char, bool> LetterSeen;
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
        if (LetterSeen[Letter])
        {
            return false;
        }
        else
        {
            LetterSeen[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if(!islower(Letter))
        {
            return false;
        }
    }
    
    return true;
}
