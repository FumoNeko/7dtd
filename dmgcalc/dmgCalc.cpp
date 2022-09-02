// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include <string>
#include "data.h"
#include "termGui.cpp"
using namespace std;

// Wooden club is used as an example here.
int main() {
    bool menuState = true;
    if (menuState == true){
        returnCode = termGui("main");
        optionsMain[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        optionsWeapon[39] = {}; //100-138
        for (int i = 0; i < 39; i++) {
            optionsWeapon[i] = 100 + i;
        }
        optionsQuality[7] = {200, 201, 202, 203, 204, 205, 206};
        optionsPerkLevel[] = {300, 301, 302, 303, 304, 305, 306};

    }

    /*
    // user variables
    int qualLevel = 1;
    int perkLevel = 5;
//  int ammoType
//  int enemyType // for Armor
//  int numMods
//  int buffs
    
    // weapon variables
    float base = 13.8;
    float qualitymod = 0.1*qualLevel-0.1;
    float perkmod = 0.1*perkLevel;
    float difficultymod = 1.5;
    
    int mod1 = base * (1+qualitymod+perkmod);
    
    int finaldamage = mod1 * difficultymod;
    
    cout << finaldamage << endl;
*/

    return 0;
}

/*
int main() {
    obtainMeleeWeapon("WoodenClub");
    cout << structMelee.baseEntityDamage << endl;
    cout << structMelee.baseBlockDamage << endl;
}
*/