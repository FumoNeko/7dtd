// g++ -std=c++17 -o program.out program.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    int i = 0;
    string dumpText{};
    int lineTotal{};
    string *lineArr = NULL;

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

    // trim data
    string labelMelee{};
    string labelRobot{};
    int labelMeleeLocation{};
    int labelRobotLocation{};
    labelMelee = "----MELEE WEAPONS----";
    labelRobot = "----ROBOTIC TURRETS----";
    // Search for labels
    for (int i = 0; i <= lineTotal-2; i++) {
        if (lineArr[i] == labelMelee) {
            labelMeleeLocation = i; 
        }
        else if (lineArr[i] == labelRobot) {
            labelRobotLocation = i;
        }
    }

    // 1, 4, 7... (+3)
    for (int i = labelMeleeLocation+1; i < labelRobotLocation; i = i + 3) {
        string itemName = lineArr[i];
        regex rgx("(?<=Item Name: meleeToolRepairT\\d).*|(?<=Item Name: meleeToolAxeT\\d).*|(?<=Item Name: meleeToolPickT\\d).*|(?<=Item Name: meleeToolShovelT\\d).*|(?<=Item Name: meleeToolSalvageT\\d).*|(?<=Item Name: meleeWpnBladeT\\d).*|(?<=Item Name: meleeWpnClubT\\d).*|(?<=Item Name: meleeWpnBatonT\\d).*|(?<=Item Name: meleeWpnSpearT\\d).*|(?<=Item Name: meleeWpnSledgeT\\d).*|(?<=Item Name: meleeWpnKnucklesT\\d).*|(?<=Item Name: meleeToolFarmT\\d).*|(?<=Item Name: meleeTool)Flashlight|Torch");
        auto operands_begin = sregex_iterator(itemName.begin(), itemName.end(), rgx);
        auto operands_end = sregex_iterator();
        for (sregex_iterator itr = operands_begin; itr != operands_end; ++itr) {
            cout << itr->str() << "\n";
        }
        //lineArr[i];
    }

    //convert numbers to floats

    return 0;
    /*
    cout << lineArr[118] << endl; // last line = lineTotal - 2
    cout << lineTotal << endl;
    return 0;
    */
}