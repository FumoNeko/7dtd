//unused cpp code that didn't make it or was removed

// part of dmgCalc.cpp
// checkCode Function was used for termGui.cpp to prevent recursion and return to the main stack on every call to the GUI
// was removed because it caused a bug where memory would not be saved.
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


// termGui.cpp
// apparently this doesn't work on windows so we're scorching it until a fix can be found. no user input checking I guess!

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
