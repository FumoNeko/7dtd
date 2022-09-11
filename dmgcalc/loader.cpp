// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int initData() {
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

    // get label locations to start and stop scanning
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

    // Create arrays to store the results of reading the dump
    string arrMeleeName[(labelRobotLocation-labelMeleeLocation-1)/3] = {};
    float arrMeleeEntityDmg[(labelRobotLocation-labelMeleeLocation-1)/3] = {};
    float arrMeleeBlockDmg[(labelRobotLocation-labelMeleeLocation-1)/3] = {};

    // Insert Melee items into their arrays
    for (int i = labelMeleeLocation+1; i < labelRobotLocation; i = i + 3) {
        string itemName = lineArr[i];                    // itemName
        arrMeleeName[(i-1)/3] = itemName;
        string entityDamageStr = lineArr[i+1];           // entityDamage string
        float entityDamageFloat = stof(entityDamageStr); // convert to float
        arrMeleeEntityDmg[(i-1)/3] = entityDamageFloat;
        string blockDamageStr = lineArr[i+2];            // blockDamage string
        float blockDamageFloat = stof(blockDamageStr);   // convert to float
        arrMeleeBlockDmg[(i-1)/3] = blockDamageFloat;
    }
/*
    // Copy arrays into global structs
    for (int i = 0; i < 38; i++) {
        dataMelee.Name[i] = arrMeleeName[i];
        dataMelee.EntityDmg[i] = arrMeleeEntityDmg[i];
        dataMelee.BlockDmg[i] = arrMeleeBlockDmg[i];
    }
*/
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
    return 0;
}