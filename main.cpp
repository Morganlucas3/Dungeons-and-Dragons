//
//  main.cpp
//  Assignment3
//
//  Created by Morgan Lucas on 12/5/20.
//

#include <iostream>
#include "CommonStatistics.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include <time.h>
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(0)); // for randomly generating dice rolls
    int Tdamage = 0; //temporary damage variable
    
    //creating ptr to warrior character constructor
    shared_ptr<Warrior> warrior = make_shared<Warrior>("Knight Timmy", 20, 5, 3, 4 );
    warrior->introduction(); //intoducing warrior character
    
    //creating ptr to mage
    shared_ptr<Mage> mage = make_shared<Mage>("Wizard Gandolfo", 15, 2, 7);
    mage->introduction(); // introducing mage character
    
    //current stats 
    warrior->currentStats();
    mage->currentStats();
   
    while ((mage->takeDamage(Tdamage) > 0) && (warrior->takeDamage(Tdamage) > 0))
    {
    //point to warrior and mage whoseMove() functions to see who will go first
    warrior->whoseMove();
    mage->whoseMove();
    
    // if statements determining whose move based off of the initiativeScore
    if (warrior->whoseMove() > mage->whoseMove())
    {
        Tdamage = warrior->myMove();
        mage->takeDamage(Tdamage);
        Tdamage = mage->myMove();
        warrior->takeDamage(Tdamage);
    } else
    {
        Tdamage = mage->myMove();
        warrior->takeDamage(Tdamage);
        Tdamage = warrior->myMove();
        mage->takeDamage(Tdamage);
    }
    }
    
    //if statements--if one of the characters health falls below 0, then that characters takeDamage() function is called and that character is slained
    if (mage->takeDamage(Tdamage) <= 0)
    {
        mage->takeDamage(Tdamage);
        cout << "The Mage has been slain!" << endl;
    } else if (warrior->takeDamage(Tdamage) <= 0)
    {
        warrior->takeDamage(Tdamage);
        cout << "You have been slain! You died and lost the game" << endl;
    }
    
    //magical fairy visit- resets warrior health back to 20
    cout << "A magical fairy visits you, health has been reset to " << warrior->resetHealth() << " !" << endl;
    
    //rogue introduction
    shared_ptr<Rogue> rogue = make_shared<Rogue>("Assassin Jim", 10, 3, 4, 5);
    rogue->introduction();
    
    //warrior and rogue current stats
    warrior->currentStats();
    rogue->currentStats();
    
    while ((rogue->takeDamage(Tdamage) > 0) && (warrior->takeDamage(Tdamage) > 0))
    {
    //point to warrior and mage whoseMove() functions to see who will go first
    warrior->whoseMove();
    rogue->whoseMove();
    
    // if statements determining whose move based off of the initiativeScore
    if (warrior->whoseMove() > rogue->whoseMove())
    {
        Tdamage = warrior->myMove();
        rogue->takeDamage(Tdamage);
        Tdamage = rogue->myMove();
        warrior->takeDamage(Tdamage);
    } else
    {
        Tdamage = rogue->myMove();
        warrior->takeDamage(Tdamage);
        Tdamage = warrior->myMove();
        rogue->takeDamage(Tdamage);
    }
    }
    
    
    //if statements--if one of the characters health falls below 0, then that characters takeDamage() function is called and that character is slained
    if (rogue->takeDamage(Tdamage) <= 0)
    {
        rogue->takeDamage(Tdamage);
        cout << "The Rogue has been slain!" << endl;
        cout << "You won the video game!" << endl;
    } else if (warrior->takeDamage(Tdamage) <= 0)
    {
        warrior->takeDamage(Tdamage);
        cout << "You have been slain! You died and lost the game" << endl;
    }

    
    
    
    
    
    return 0;
}
