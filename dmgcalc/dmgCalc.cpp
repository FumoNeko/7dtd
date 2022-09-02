// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include "data.h"
#include <string>
using namespace std;

void termgui(string menu) {
    string weapon = "NONE";
    int quality = 1;
    int perkLevel = 0;
//  string mods[4] = {"NONE", "NONE", "NONE", "NONE"};
//  int numMods = 0;
//  string ammoType = "NONE";
//  enemyType = "NONE"; // for armor
//  buffs = "NONE";

    int caseMenu{};

    if (menu == "exit") {
        caseMenu = 0;
    }
    else if (menu == "main") {
        caseMenu = 1;
    }
    else if (menu == "weapon") {
        caseMenu = 2;
    }
    else if (menu == "quality") {
        caseMenu = 3;
    }
    else if (menu == "perkLevel") {
        caseMenu = 4;
    }
    /*
    else if (menu == "mods") {
        caseMenu = ?;
    }
    */
    else if (menu == "numMods") {
        caseMenu = 5;
    }
    else if (menu == "buffs") {
        caseMenu = 6;
    }
    else if (menu == "ammoType") {
        caseMenu = 7;
    }
    else if (menu == "enemyType") {
        caseMenu = 8;
    }
    // while loop to select caseMenu int? going to bed.
    switch(caseMenu) {
        case 1:
            cout << "------Main Menu------"                                                    << endl;
            cout << "Select an option from the menu:"                                          << endl;
            cout << "0. Exit Program"                                                          << endl;
            cout << "1. Set Variable: Weapon"             << " Selected: " << weapon    << " " << endl;
            cout << "2. Set Variable: Quality"            << " Selected: " << quality   << " " << endl;
            cout << "3. Set Variable: Perk Level"         << " Selected: " << perkLevel << " " << endl;
            //cout << "Set Array: Mods"                   << " Selected: " << mods      << " " << endl;
            cout << "4. Set Variable: # of Mods"          << " Selected: " << numMods   << " " << endl;
            cout << "5. Set Array: Buffs"                 << " Selected: " << buffs     << " " << endl;
            cout << "6. Set Variable: Ammo Type"          <<
            cout << "7. Set Variable: Enemy Type (Armor)" << " Selected: " << enemyType << " " << endl;
            break;
        case 2:
            // code block
            break;
        default:
            cout << "error" << endl;
    }
}



// Wooden club is used as an example here.
int main() {
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


    return 0;
}

/*
int main() {
    obtainMeleeWeapon("WoodenClub");
    cout << structMelee.baseEntityDamage << endl;
    cout << structMelee.baseBlockDamage << endl;
}
*/