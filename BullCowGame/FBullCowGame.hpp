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

class FBullCowGame {
public:
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset(); // TODO make a more rich return value.
    bool CheckGuessValidity(std::string); // TODO make a more rich return value.
    
    
// ^^ Please try and ignore this and focus on the interface above ^^
private:
    int MyCurrentTry = 1;
    int MyMaxTries = 10;
};
