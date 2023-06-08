//
//  CommonStatistics.h
//  Assignment3
//
//  Created by Morgan Lucas on 12/5/20.
//

#ifndef CommonStatistics_h
#define CommonStatistics_h
using namespace std;

class CommonStatistics
{
protected:
    string characterName;
    int BaseAttackDie;
    double health;
    double armor;
    


public:
  
    CommonStatistics(string n,double h, double a)
    {
        characterName = n;
        health = h;
        armor = a;
    }
    
    virtual void introduction() = 0; 
    virtual void currentStats() = 0;
    virtual int whoseMove() = 0;
    virtual int myMove() = 0;
    virtual double takeDamage() = 0;
  
};

#endif /* CommonStatistics_h */
