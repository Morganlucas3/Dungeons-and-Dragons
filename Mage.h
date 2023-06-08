//
//  Mage.h
//  Assignment3
//
//  Created by Morgan Lucas on 12/5/20.
//

#ifndef Mage_h
#define Mage_h
#include "CommonStatistics.h"

class Mage : public CommonStatistics
{
private:
    double intellect; //attack modifier
    
    
    
    
public:
    //Mage overloaded constructor
    Mage(string n, double h, double a, double i) : CommonStatistics(n, h, a)
    {
        intellect = i;
    }
    
    //Mage introduction function
    virtual void introduction()
    {
        cout << "A Mage named " << characterName << " appears and is read to battle!" << endl;
    }
    
    //Mage Current Stats
    virtual void currentStats()
    {
        cout << "Mage " << characterName << "'s current stats: " << endl;
        cout << "Health: " << health << endl;
        cout << "Base Attack Die: 1 D4" << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Intellect): " << intellect << endl;
    }
    
    //Rolling dice to see which character goes first
    virtual int whoseMove()
    {
       int initiativeScore = rand() % 20 + 1;
    cout << "The Mage rolled one dice(1-20): Inititative score of" << initiativeScore << " and has no bonus speed modifier" << endl;
        return initiativeScore;
    }
    
    //the Mage's turn
    virtual int myMove()
    {
        int randomAttack = rand() % 4 + 1;
        cout << characterName << "'s Move: " << endl;
        cout << characterName << "rolled one dice(1-4): Damage score of " << randomAttack << " + an intellect modifier of" << intellect << " for a total of " << (randomAttack + intellect) << endl;
        return (randomAttack + intellect);
    }
    
    //mage take damage
    virtual double takeDamage(int damage)
    {
        if (damage > 0) //to make sure the damage is positive
        {
        damage = damage - armor;
        cout << characterName << " has taken " << damage << " damage and is now at " << (health - damage) << " HP" << endl;
        health = (health - damage);
        }
        return health;
    }
};

#endif /* Mage_h */
