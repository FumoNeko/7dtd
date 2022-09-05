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

int termGui(int menu) {
    int selection{};
/*
    "exit" menu = 0;
    "main" menu = 1;
    "weapon" menu = 2;
    "quality" menu = 3;
    "perkLevel" menu = 4;
    "mods" menu = ?;
    "numMods" = 5;
    "buffs" menu = 6;
    "ammoType" menu = 7;
    "enemtType" menu = 8;
*/
    // while loop to select caseMenu int? going to bed.
    switch(menu) {
        case 0:
        // exit program
        break;
        case 1:
            cout << "------Main Menu------"                                                             << endl;
            cout << "Select an option from the menu:"                                                   << endl;
            cout << "0. Exit Program"                                                                   << endl;
            cout << "1. Set Variable: Weapon"             << " Selected: " << selected.weapon    << " " << endl;
            cout << "2. Set Variable: Quality"            << " Selected: " << selected.quality   << " " << endl;
            cout << "3. Set Variable: Perk Level"         << " Selected: " << selected.perkLevel << " " << endl;
            //cout << "Set Array: Mods"                   << " Selected: " << selected.mods      << " " << endl;
            cout << "4. Set Variable: # of Mods"          << " Selected: " << selected.numMods   << " " << endl;
            cout << "5. Set Array: Buffs"                 << " Selected: " << selected.buffs     << " " << endl;
            cout << "6. Set Variable: Ammo Type"          << " Selected: " << selected.ammoType  << " " << endl;
            cout << "7. Set Variable: Enemy Type (Armor)" << " Selected: " << sekected.enemyType << " " << endl;
            badAnswer = true;
            while (badAnswer == true) {
                selection = checkInput();
                if (selection != -1) {
                    badAnswer = false;
                }
            }
            return selection;
            break;
        case 2:
            cout << "------Set Variable: Weapon------"                                                                               << endl;
            cout << "0) Return to Main Menu"                                                                                         << endl;
            cout << "     1) Stone Axe          2) Tazas Stone Axe     3) Claw Hammer       4) Iron Fireaxe   5) Steel Axe"          << endl;
            cout << "     6) Iron Pickaxe       7) Steel Pickaxe       8) Stone Shovel      9) Iron Shovel   10) Steel Shovel"       << endl;
            cout << "    11) Chainsaw          12) Auger              13) Wrench           14) Ratchet       15) Impact Driver"      << endl;
            cout << "    16) Bone Knife        17) Hunting Knife      18) Candy Knife      19) Machete       20) Wooden Club"        << endl;
            cout << "    21) Baseball Bat      22) Candy Club         23) Steel Club       24) Pipe Baton    25) Stun Baton"         << endl;
            cout << "    26) Plasma Baton      27) Stone Spear        28) Iron Spear       29) Steel Spear   30) Stone Sledgehammer" << endl;
            cout << "    31) Iron Sledgehammer 32) Steel Sledgehammer 33) Leather Knuckles 34) Iron Knuckles 35) Steel Knuckles"     << endl;
            cout << "    36) Iron Hoe          37) Flashlight         38) Torch"                                                     << endl;
            while (badAnswer == true) {
                selection = checkInput();
                if (selection != -1) {
                    badAnswer = false;
                }
            }
            return selection+100;
            break;
        case 3:
            cout << "------Set Variable: Quality------" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "1. Quality 1" << endl;
            cout << "2. Quality 2" << endl;
            cout << "3. Quality 3" << endl;
            cout << "4. Quality 4" << endl;
            cout << "5. Quality 5" << endl;
            cout << "6. Quality 6" << endl;
            while (badAnswer == true) {
                selection = checkInput();
                if (selection != -1) {
                    badAnswer = false;
                }
            }
            return selection+200;
            break;
        case 4:
            cout << "------Set Variable: Perk Level------" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "1. Perk Level 0" << endl;
            cout << "2. Perk Level 1" << endl;
            cout << "3. Perk Level 2" << endl;
            cout << "4. Perk Level 3" << endl;
            cout << "5. Perk Level 4" << endl;
            cout << "6. Perk Level 5" << endl;
            while (badAnswer == true) {
                selection = checkInput();
                if (selection != -1) {
                    badAnswer = false;
                }
            }
            return selection+300;
            break;
        default:
            cout << "This feature has not been implemented yet." << endl;
            return 1;
    }
}