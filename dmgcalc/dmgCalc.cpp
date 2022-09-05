// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include <string>
#include "data.h"
#include "termGui.cpp"
using namespace std;

// Todo:
// start testing and debugging of the GUI and weapon properties
// begin coding the equations and math that calculate the damage.
// refactor data.h out of a main() function since that's redundant

struct {
    string weapon = "NONE";
    float EntityDmg{};
    float BlockDmg{};
    int quality = 1;
    int perkLevel = 0;
    string mods[4] = {"NONE", "NONE", "NONE", "NONE"};
    int numMods = 0;
    string ammoType = "NONE";
    enemyType = "NONE"; // for armor
    buffs = "NONE";
} selected;

int checkCode(int rCode) {
    // basic GUI pages
    if {rCode <=7} {
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
        selected.Weapon = arrMeleeName[xCode];
        selected.EntityDmg = arrMeleeEntityDmg[xCode];
        selected.BlockDmg = arrMeleeBlockDmg[xCode];
        return 1;
    }
    // Quality Options
    //int optionsQuality[7] = {200, 201, 202, 203, 204, 205, 206};
    if (199 < rCode < 207) {
        xCode = rCode - 200;
        selected.quality = xCode;
        return 1;
    }
    // Perk Options
    //int optionsPerkLevel[7] = {300, 301, 302, 303, 304, 305, 306};
    if (299 < rCode < 307) {
        xCode = rCode - 300;
        selected.perkLevel = xCode;
        return 1;
    }
}

// Wooden club is used as an example here.
int main() {
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