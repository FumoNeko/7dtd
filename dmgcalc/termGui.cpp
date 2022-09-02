void checkInput(){
    try {
        string str{};
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i]) == true) {
                int selection = stoi(str);
                cout << selection << endl;
            }
            else {
                throw (str);
            }
        }
	}
	catch (string uinput) {
	    cout << "User input is not an integer!" << endl;
        cout << "Input was: " << uinput << endl;
	}
}

void termGui(string menu) {
    string weapon = "NONE";
    int quality = 1;
    int perkLevel = 0;
//  string mods[4] = {"NONE", "NONE", "NONE", "NONE"};
//  int numMods = 0;
//  string ammoType = "NONE";
//  enemyType = "NONE"; // for armor
//  buffs = "NONE";

    int caseMenu{};
    int selection{};

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
            cin >> selection;
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
            cin >> selection;
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
            cin >> selection;
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
            try {
		        string str{};
    	        cin >> str;
                for (int i = 0; i < str.length(); i++) {
                    if (isdigit(str[i]) == true) {
                        int selection = stoi(str);
                        cout << selection << endl;
                    }
                    else {
      		            throw (str);
    	            }
                }
	        }
	        catch (string uinput) {
	            cout << "User input is not an integer!" << endl;
                cout << "Input was: " << uinput << endl;
	        }
            break;
        default:
            cout << "This feature has not been implemented yet." << endl;
    }
}