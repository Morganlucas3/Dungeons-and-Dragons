//
//  Warrior.h
//  Assignment3
//
//  Created by Morgan Lucas on 12/5/20.
//

#ifndef Warrior_h
#define Warrior_h
#include "CommonStatistics.h"
#include "Mage.h"
#include <time.h>
using namespace std;


class Warrior : public CommonStatistics
{
private:
    int healingDie;
    double strength; //attack modifier
    double speed; //initiative modifier
    
    
    
public:
    
    //warrior overloaded constructor
    Warrior(string n, double h, double a, double st, double sp) : CommonStatistics(n, h, a)
    {
        strength = st;
        speed = sp;
    }
    
    //warrior introduction function
    virtual void introduction()
    {
        cout << "You are now " << characterName << ", a ferocious Warrior" << endl;
    }
    
    //warrior current stats function
    virtual void currentStats()
    {
        cout << "Warrior " << characterName << "'s current stats:" << endl;
        cout << "Health: " << health << endl;
        cout << "Healing Die: 2 D5 " << endl;
        cout << "Base Attack Die: 1 D6" << endl;
        cout << "Armor: " << armor << endl;
        cout << "Attack Modifier (Strength): " << strength << endl;
        cout << "Initiative Modifier (Speed): " << speed << endl;
    }
    
    //rolling dice to see which character goes first
    virtual int whoseMove()
    {
       int randomNum = rand() % 20 + 1;
        int initiativeScore = (randomNum + speed);
    cout << "You rolled one dice (1-20): initiative score of " << randomNum << " + a speed modifier of " << speed << "for a total score of " << initiativeScore << endl;
        return initiativeScore;
    }
    
    //warriors move
    virtual int myMove()
    {
        int choose;
        cout << characterName << "'s Move: " << endl;
        cout << "What will you do?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;
        cin >> choose;
        
        if (choose == 1)
        {
            int randomAttack = rand() % 6 + 1;
            cout << "You rolled one dice(1-6): Damage score of " << randomAttack << " + a strength modifier of " << strength << "for a total of " << (randomAttack + strength) << endl;
            return (randomAttack + strength);
        } else
        {
            int randomHeal = rand() % 10 + 2;
            cout << " You heal yourself for " << randomHeal << " hit points!" << endl;
            cout << "Total HP now at: " << (health + randomHeal) << endl;
            health = (health + randomHeal);
            return health;
        }
    }
    
    //warrior take damage-returns health to be used for while loop in main.cpp
    virtual double takeDamage(int damage)
    {
        if (damage > 0)  // to make sure that the damage is a positive number
        {
        damage = damage - armor;
        cout << characterName << " has taken " << damage << " damage and is now at " << (health - damage) << " HP" << endl;
        health = health - damage;
        }
        return health;
    }
    
    //magical fairy visits you and your health is reset to 20!
    double resetHealth()
    {
        health = health;
        return health;
    }
};

#endif /* Warrior_h */
