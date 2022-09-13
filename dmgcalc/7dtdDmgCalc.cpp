// g++ -std=c++17 -o dmgCalc.o dmgCalc.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits>
using namespace std;
// I've become UNHINGED with multiple definitions so I'm just throwing it all into main
// I've literally wasted like 3 days on this. I hate it.

// data.h
struct {
    string weapon{};
    float entityDmg{};
    float blockDmg{};
    int quality{};
    int perkLevel{};
    string mods[4] = {};
    int numMods{};
    string ammoType{};
    string enemyType{}; // for armor
    string buffs{};
    string difficultyName{};
    float difficultyMod{};
}selected;
struct {
    string Name[38]{};
    float EntityDmg[38]{};
    float BlockDmg[38]{};
}dataMelee;
/*
struct {
    string Name[];
    float EntityDmg[];
    float BlockDmg[];
} dataGun;

struct {
    string Name[];
    float EntityDmg[];
    float BlockDmg[];
} dataAmmo;

struct {
    string Name[];
    float EntityDmg[];
    float BlockDmg[];
} dataTurret;
*/

//loader.cpp
void initData() {
    int i = 0;
    string dumpText{};
    int lineTotal{};
    string* lineArr = NULL;

    // Figure out number of lines
    ifstream myfile("dump.txt");
    while (!myfile.eof()) {
        getline(myfile, dumpText);
        lineTotal++;
    }
    myfile.close();

    // Dynamic memory allocation to alloc size of (lineTotal) to line array
    lineArr = new string[lineTotal];
    ifstream myFile("dump.txt");
    while (!myFile.eof()) {
        getline(myFile, lineArr[i]);
        i++;
    }
    myFile.close();

    // get label locations to start and stop scanning
    string labelMelee{};
    string labelRobot{};
    int labelMeleeLocation{};
    int labelRobotLocation{};
    labelMelee = "----MELEE WEAPONS----";
    labelRobot = "----ROBOTIC TURRETS----";
    // Search for labels
    for (int i = 0; i <= lineTotal - 2; i++) {
        if (lineArr[i] == labelMelee) {
            labelMeleeLocation = i;
        }
        else if (lineArr[i] == labelRobot) {
            labelRobotLocation = i;
        }
    }

    // Create arrays to store the results of reading the dump
    string arrMeleeName[38] = {};
    float arrMeleeEntityDmg[38] = {};
    float arrMeleeBlockDmg[38] = {};

    // Insert Melee items into their arrays
    for (int i = labelMeleeLocation + 1; i < labelRobotLocation; i = i + 3) {
        string itemName = lineArr[i];                    // itemName
        arrMeleeName[(i - 1) / 3] = itemName;
        string entityDamageStr = lineArr[i + 1];           // entityDamage string
        float entityDamageFloat = stof(entityDamageStr); // convert to float
        arrMeleeEntityDmg[(i - 1) / 3] = entityDamageFloat;
        string blockDamageStr = lineArr[i + 2];            // blockDamage string
        float blockDamageFloat = stof(blockDamageStr);   // convert to float
        arrMeleeBlockDmg[(i - 1) / 3] = blockDamageFloat;
    }

    // Copy arrays into global structs
    for (int i = 0; i < 38; i++) {
        dataMelee.Name[i] = arrMeleeName[i];
        dataMelee.EntityDmg[i] = arrMeleeEntityDmg[i];
        dataMelee.BlockDmg[i] = arrMeleeBlockDmg[i];
    }


    // I've decided I don't need pointers, but will leave commented code anyway in case I do need them.
    // Create pointers to each item in the array
    /*
    float* ptrArrMeleeEntityDmg[labelRobotLocation-labelMeleeLocation/3] = {};
    float* ptrArrMeleeBlockDmg[labelRobotLocation-labelMeleeLocation/3] = {};
    for (int i = 0; i < (labelRobotLocation-labelMeleeLocation)/3; i++) {
        ptrArrMeleeEntityDmg[i] = &arrMeleeEntityDmg[i];
        ptrArrMeleeBlockDmg[i] = &arrMeleeBlockDmg[i];
    }
    //cout << *ptrArrMeleeEntityDmg[0] << endl;
    */
}
// termGui.cpp
// apparently this doesn't work on windows so we're scorching it until a fix can be found. no user input checking I guess!
/*
bool badAnswer{};

int checkInput() {
    try {
        string str{};
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i]) == true) {
                cout << endl << "OK" << endl;
            }
            else {
                throw (str);
            }
        }
        return stoi(str);
    }
    catch (string uinput) {
        cout << "User input is not an integer!" << endl;
        cout << "Input was: " << uinput << endl;
        return -1;
    }
}
*/

int checkInput() {
    int input{};
    cin >> input;
    return input;
}
void checkWeapon(int selection) {
    selection = selection - 1;
    selected.weapon = dataMelee.Name[selection];
    selected.entityDmg = dataMelee.EntityDmg[selection];
    selected.blockDmg = dataMelee.BlockDmg[selection];
}
void checkQuality(int selection) {
    selected.quality = selection;
}
void checkPerkLevel(int selection) {
    selected.perkLevel = selection-1;
}
void checkDifficulty(int selection) {
    string listDifficulty[6] = { "Scavenger", "Adventurer", "Nomad", "Warrior", "Survivalist", "Insane" };
    float listDifficultyMod[6] = {2.0f, 1.5f, 1.0f, 0.83f, 0.66f, 0.50f};
    selected.difficultyName = listDifficulty[selection-1];
    selected.difficultyMod = listDifficultyMod[selection-1];
}
void clearScreen() {
    if (system("CLS")) system("clear");
}
void pauseIOStream() {
    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
    std::cin.get(); // get one more char from the user (waits for user to press enter)
}
void calculateDamage() {
    //((base * [1+qualitymod+perkmod]) * [difficultymod])
    float baseEntity = selected.entityDmg;
    float baseBlock = selected.blockDmg;
    float qualitymod = 0.1 * selected.quality - 0.1;
    float perkmod = 0.1 * selected.perkLevel;

    int modEntity = baseEntity * (1+qualitymod+perkmod);
    int modBlock = baseBlock * (1 + qualitymod + perkmod);

    int finalEntityDamage = modEntity * selected.difficultyMod;
    int finalBlockDamage = modBlock * selected.difficultyMod;
    cout << "Base Entity Damage: " << selected.entityDmg << endl;
    cout << "Base Block Damage: " << selected.blockDmg << endl;
    cout << "Quality:    "<< selected.quality   << " = qualityMod:  "<< qualitymod << endl;
    cout << "PerkLevel:  "<< selected.perkLevel << " = perkMod:     "<< perkmod    << endl;
    cout << endl;
    cout << "((base * [1+qualitymod+perkmod]) * [difficultymod])" << endl;
    cout << endl;
    cout << "Entity Damage:" << endl;
    cout << "((" << baseEntity << " * [1 + " << qualitymod << " + " << perkmod << "]) * [" << selected.difficultyMod << "])" << endl;
    cout << "((" << baseEntity << " * [" << 1 + qualitymod + perkmod << "]) * [" << selected.difficultyMod << "])" << endl;
    int tempEntity = baseEntity * (1 + qualitymod + perkmod);
    cout << baseEntity << " * " << 1 + qualitymod + perkmod << " = " << baseEntity * (1 + qualitymod + perkmod) << " -> " << tempEntity << endl;
    cout << modEntity << " * " << selected.difficultyMod << endl;
    cout << "Entity Damage: " << finalEntityDamage << endl;
    cout << endl;
    cout << "Block Damage:" << endl;
    cout << "((" << baseBlock << " * [1 + " << qualitymod << " + " << perkmod << "]) * [" << selected.difficultyMod << "])" << endl;
    cout << "((" << baseBlock << " * [" << 1 + qualitymod + perkmod << "]) * [" << selected.difficultyMod << "])" << endl;
    int tempBlock = baseBlock * (1 + qualitymod + perkmod);
    cout << baseBlock << " * " << 1 + qualitymod + perkmod << " = " << baseBlock * (1 + qualitymod + perkmod) << " -> " << tempBlock << endl;
    cout << modBlock << " * " << selected.difficultyMod << endl;
    cout << "Block Damage: " << finalBlockDamage << endl;
    cout << endl;
    cout << "Press <Enter> to continue..." << endl;
    pauseIOStream();
    clearScreen();
}
void termGui() {
    int selection{};
    /*
        "exit" menu = 0;
        "main" menu = 9999;
        "weapon" menu = 2;
        "quality" menu = 3;
        "perkLevel" menu = 4;
        "mods" menu = ?;
        "numMods" = 5;
        "buffs" menu = 6;
        "ammoType" menu = 7;
        "enemyType" menu = 8;
        "difficulty" menu = 9;
    */
    // while loop to select caseMenu int? going to bed.
    bool menuState = true;
    int menu = 9999;
    while (menuState == true) {
        switch (menu) {
        case 0:
            exit(3);
            break;
        case 9999:
            cout << "------Main Menu------" << endl;
            cout << "Select an option from the menu:" << endl;
            cout << "0. Exit Program" << endl;
            cout << "1. Set Variable: Weapon             "<< " Selected: " << selected.weapon         << " " << endl;
            cout << "2. Set Variable: Quality            "<< " Selected: " << selected.quality        << " " << endl;
            cout << "3. Set Variable: Perk Level         "<< " Selected: " << selected.perkLevel      << " " << endl;
            //cout << "Set Array: Mods                   "<< " Selected: " << selected.mods           << " " << endl;
            cout << "4. Set Variable: # of Mods          "<< " Selected: " << selected.numMods        << " " << endl;
            cout << "5. Set Array: Buffs                 "<< " Selected: " << selected.buffs          << " " << endl;
            cout << "6. Set Variable: Ammo Type          "<< " Selected: " << selected.ammoType       << " " << endl;
            cout << "7. Set Variable: Enemy Type (Armor) "<< " Selected: " << selected.enemyType      << " " << endl;
            cout << "8. Set Variable: Difficulty         "<< " Selected: " << selected.difficultyName << " " << endl;
            cout << "9. Calculate final damage" << endl;
            selection = checkInput();
            if (selection == 9) {
                clearScreen();
                calculateDamage();
            }
            else {
                clearScreen();
                menu = selection;
            }
            break;
        case 1:
            cout << "------Set Variable: Weapon------" << endl;
            cout << "0) Return to Main Menu" << endl;
            cout << "     1) Stone Axe          2) Tazas Stone Axe     3) Claw Hammer       4) Iron Fireaxe   5) Steel Axe" << endl;
            cout << "     6) Iron Pickaxe       7) Steel Pickaxe       8) Stone Shovel      9) Iron Shovel   10) Steel Shovel" << endl;
            cout << "    11) Chainsaw          12) Auger              13) Wrench           14) Ratchet       15) Impact Driver" << endl;
            cout << "    16) Bone Knife        17) Hunting Knife      18) Candy Knife      19) Machete       20) Wooden Club" << endl;
            cout << "    21) Baseball Bat      22) Candy Club         23) Steel Club       24) Pipe Baton    25) Stun Baton" << endl;
            cout << "    26) Plasma Baton      27) Stone Spear        28) Iron Spear       29) Steel Spear   30) Stone Sledgehammer" << endl;
            cout << "    31) Iron Sledgehammer 32) Steel Sledgehammer 33) Leather Knuckles 34) Iron Knuckles 35) Steel Knuckles" << endl;
            cout << "    36) Iron Hoe          37) Flashlight         38) Torch" << endl;
            selection = checkInput();
            if (selection == 0) {
                clearScreen();
                menu = 9999;
            }
            else {
                clearScreen();
                checkWeapon(selection);
                menu = 9999;
            }
            break;
        case 2:
            cout << "------Set Variable: Quality------" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "1. Quality 1" << endl;
            cout << "2. Quality 2" << endl;
            cout << "3. Quality 3" << endl;
            cout << "4. Quality 4" << endl;
            cout << "5. Quality 5" << endl;
            cout << "6. Quality 6" << endl;
            selection = checkInput();
            if (selection == 0) {
                clearScreen();
                menu = 9999;
            }
            else {
                clearScreen();
                checkQuality(selection);
                menu = 9999;
            }
            break;
        case 3:
            cout << "------Set Variable: Perk Level------" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "1. Perk Level 0" << endl;
            cout << "2. Perk Level 1" << endl;
            cout << "3. Perk Level 2" << endl;
            cout << "4. Perk Level 3" << endl;
            cout << "5. Perk Level 4" << endl;
            cout << "6. Perk Level 5" << endl;
            selection = checkInput();
            if (selection == 0) {
                clearScreen();
                menu = 9999;
            }
            else {
                clearScreen();
                checkPerkLevel(selection);
                menu = 9999;
            }
            break;
        case 8:
            cout << "------Set Variable: Difficulty------" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "1. Scavenger"           << endl;
            cout << "2. Adventurer"          << endl;
            cout << "3. Nomad"               << endl;
            cout << "4. Warrior"             << endl;
            cout << "5. Survivalist"         << endl;
            cout << "6. Insane"              << endl;
            selection = checkInput();
            if (selection == 0) {
                clearScreen();
                menu = 9999;
            }
            else {
                clearScreen();
                checkDifficulty(selection);
                menu = 9999;
            }
            break;
        default:
            clearScreen();
            cout << "This feature has not been implemented yet." << endl;
            cout << "Press <Enter> to continue..." << endl;
            pauseIOStream();
            clearScreen();
            menu = 9999;
        }
    }
}

// Todo:
// start testing and debugging of the GUI and weapon properties
// begin coding the equations and math that calculate the damage.
// refactor data.h out of a main() function since that's redundant
/*
int checkCode(int rCode) {
    // basic GUI pages
    if (rCode <= 7) {
        //int optionsMain[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        return rCode;
    }
    // Weapon Options
    //
    //int optionsWeapon[39] = {}; // {100, 101, ... 138}
    //for (int i = 0; i < 39; i++) {
    //    optionsWeapon[i] = 100 + i;
    //}
    //
    if (99 < rCode < 139) {
        // set var to selected weapon and return main menu
        int xCode = rCode - 100;
        selected.weapon = dataMelee.Name[xCode];
        selected.entityDmg = dataMelee.EntityDmg[xCode];
        cout << dataMelee.Name[1] << endl;
        selected.blockDmg = dataMelee.BlockDmg[xCode];
        return 9999;
    }
    // Quality Options
    //int optionsQuality[7] = {200, 201, 202, 203, 204, 205, 206};
    if (199 < rCode < 207) {
        int xCode = rCode - 200;
        selected.quality = xCode;
        return 9999;
    }
    // Perk Options
    //int optionsPerkLevel[7] = {300, 301, 302, 303, 304, 305, 306};
    if (299 < rCode < 307) {
        int xCode = rCode - 300;
        selected.perkLevel = xCode;
        return 9999;
    }
}
*/

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
    selected.difficultyMod = 1.0f;
    selected.difficultyName = "Nomad";

    // const vars and structures
    initData();
    // menu
    termGui();

    /*
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