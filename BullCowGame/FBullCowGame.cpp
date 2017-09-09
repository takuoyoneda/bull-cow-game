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
