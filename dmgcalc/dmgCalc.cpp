// g++ -std=c++17 -o dmgCalc.o dmgCalc.cpp data.h
#ifndef commonheaders
#define commonheaders
#include "data.h"
#endif

#include <iostream>
#include <string>
#include "termGui.cpp"
#include "loader.cpp"
using namespace std;

// Todo:
// start testing and debugging of the GUI and weapon properties
// begin coding the equations and math that calculate the damage.
// refactor data.h out of a main() function since that's redundant

int checkCode(int rCode) {
    // basic GUI pages
    if (rCode <=7) {
        //int optionsMain[8] = {0, 1, 2, 3, 4, 5, 6, 7};
       return rCode;
    }
    // Weapon Options
    /*
    int optionsWeapon[39] = {}; // {100, 101, ... 138}
    for (int i = 0; i < 39; i++) {
        optionsWeapon[i] = 100 + i;
    }
    */
    if (99 < rCode < 139) {
        // set var to selected weapon and return main menu
        int xCode = rCode - 100;
        selected.weapon = dataMelee.Name[xCode];
        selected.entityDmg = dataMelee.EntityDmg[xCode];
        selected.blockDmg = dataMelee.BlockDmg[xCode];
        return 1;
    }
    // Quality Options
    //int optionsQuality[7] = {200, 201, 202, 203, 204, 205, 206};
    if (199 < rCode < 207) {
        int xCode = rCode - 200;
        selected.quality = xCode;
        return 1;
    }
    // Perk Options
    //int optionsPerkLevel[7] = {300, 301, 302, 303, 304, 305, 306};
    if (299 < rCode < 307) {
        int xCode = rCode - 300;
        selected.perkLevel = xCode;
        return 1;
    }
}

// Wooden club is used as an example here.
int main() {
    // data.h definitions
    selected.weapon = "NONE";
    selected.entityDmg = 0.0f;
    selected.blockDmg = 0.0f;
    selected.quality = 1;
    selected.perkLevel = 0;
    for (int i = 0; i < 4; i++) {
        selected.mods[i] = "NONE";
    }
    selected.numMods = 0;
    selected.ammoType = "NONE";
    selected.enemyType = "NONE"; // for armor
    selected.buffs = "NONE";

    initData();
    // define return codes
    int returnCode{};
    // menu
    int menuState = 1; // main menu
    returnCode = termGui(menuState);
    while (menuState == 1){
        returnCode = termGui(checkCode(returnCode));
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