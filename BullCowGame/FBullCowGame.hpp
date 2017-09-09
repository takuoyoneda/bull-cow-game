//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by 米田 拓男 on 2017/08/30.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>

#endif /* FBullCowGame_hpp */


#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame
{
public:
    FBullCowGame(); // constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(FString); // TODO make a more rich return value.
    
    // counts bulls and cows, and increases try # assuming valid guess
    FBullCowCount SubmitGuess(FString);
    
// ^^ Please try and ignore this and focus on the interface above ^^
private:
    // see constructor for initilization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
