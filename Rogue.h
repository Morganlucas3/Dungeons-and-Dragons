//
//  Rogue.h
//  Assignment3
//
//  Created by Morgan Lucas on 12/5/20.
//

#ifndef Rogue_h
#define Rogue_h
#include "CommonStatistics.h"

class Rogue : public CommonStatistics
{
private:
    double agility; // attack modifier
    double speed; // initiative modifier
    double dodge; // 50% chance to dodge an incoming attack
    
    
    
public:
    //Rogue overloaded constructor
   Rogue(string n, double h, double a, double ag, double sp) : CommonStatistics(n, h, a)
    {
        agility = ag;
        speed = sp;
    }
    
    //Rogue introduction function
    virtual void introduction()
    {
        cout << "A Rogue named " << characterName << "appears and is ready for battle!" << endl;
    }
    
    //Rogue current stats function
    virtual void currentStats()
    {
        cout << "Rogue " << characterName << "'s current stats:" << endl;
        cout << "Health: " << health << endl;
        cout << "Base Attack Die: 2 D4" << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Agility): " << agility << endl;
        cout << "Initiative Modifier (Speed): " << speed << endl;
        cout << "Dodge: 50% chance to dodge an incoming attack " << endl;
    }
    
    //Rolling dice to see which character goes first
    virtual int whoseMove()
    {
       int randomNum = rand() % 20 + 1;
        int initiativeScore = (randomNum + speed);
    cout << "The Rogue rolled one dice (1-20): initiative score of " << randomNum << " + a speed modifier of " << speed << "for a total score of " << initiativeScore << endl;
        return initiativeScore;
    }
    
    //the Rogue's turn
    virtual int myMove()
    {
        int randomAttack = rand() % 4 + 1;
        cout << characterName << "'s Move: " << endl;
        cout << characterName << "rolled one dice(1-4): Damage score of " << randomAttack << " + an agility modifier of" << agility << " for a total of " << (randomAttack + agility) << endl;
        return (randomAttack + agility);
    }
    
    // a dodge function
    void Dodge()
    {
        cout << "Assassin Jim Dodged the attack!" << endl;
    }
    
    //rogue take damage
    virtual double takeDamage(int damage)
    {
        int randomDodge = rand() % 2 + 1;
        if ((randomDodge == 1) && (damage > 0))// if statement to make sure this number is positive
        {
            damage = damage - armor;
            cout << characterName << " has taken " << damage << " damage and is now at " << (health - damage) << " HP" << endl;
            health = (health - damage);
        }else
        {
            Dodge();
        }
        return health;
    }
    
    
};

#endif /* Rogue_h */


