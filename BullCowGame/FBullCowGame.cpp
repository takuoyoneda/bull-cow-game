//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by 米田 拓男 on 2017/08/30.
//  Copyright © 2017 Takuo Yoneda. All rights reserved.
//

#include "FBullCowGame.hpp"


int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{
    return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}
