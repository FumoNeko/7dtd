// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include "data.cpp"
using namespace std;

/*
Current Paradigm:
(base * [1+qualitymod+perkmod]) * (difficultymod)
each item in paranthesis is decimal dropped.
Item in brackets as decimals are OK.

i.e.
13.8 * [1+0.5+0.5] * (1.5)

Wrong:

13.8 * (2) = 27.6 
27.6 * 1.5 = 41.4

Correct:

13.8 * 2 = 27.6 --> 27
27 * 1.5 = 40.5 --> 40

Needs testing:

Recog and other buffs need testing.
Body part damage modifiers need testing.
Armor needs testing.

Needs to be understood:

What kind of worn items affect damage other than mods? 
Does it mean the +1 perception glasses and stuff?

What does it mean if an item is "passed in"?
does held item mean you can shoot something and then switch 
to another weapon to deal different damage on projectile weapons? 
Why would this be different?

Have no idea about entity class.
Do different zombies just have different damage modifiers
without respect to armor? Or is it just player vs zombie damage?
*/


// Wooden club is used as an example here.
int main() {
    // user variables
    int qualLevel = 1;
    int perkLevel = 5;
//  int ammoType
//  int enemyType // for Armor
//  int numMods
//  int Buffs
    
    // weapon variables
    float base = 13.8;
    float qualitymod = 0.1*qualLevel-0.1;
    float perkmod = 0.1*perkLevel;
    float difficultymod = 1.5;
    
    int mod1 = base * (1+qualitymod+perkmod);
    
    int finaldamage = mod1 * difficultymod;
    
    cout << finaldamage << endl;


    return 0;
}