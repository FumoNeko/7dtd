#include <string>
#include <fstream>
#include <map>
using namespace std;

// Create and open text file
ifstream dumpFile("dump.txt");

// Read the file
while (getline (dumpFile, dumpText)) {
    // Output text
    cout << dumpText;
}

// Close the file
dumpFile.close();

struct {
    float baseEntityDamage = 6.0f;
    float baseBlockDamage = 21.5f;
} StoneAxe;

struct {
    float baseEntityDamage = 8.0f;
    float baseBlockDamage = 22.6f;
} TazasStoneAxe;

struct {
    float baseEntityDamage = 12.0f;
    float baseBlockDamage = 22.0f;
} ClawHammer;

struct {
    float baseEntityDamage = 15.1f;
    float baseBlockDamage = 47.0f;
} IronFireAxe;

struct {
    float baseEntityDamage = 28.9f;
    float baseBlockDamage = 86.2f;
} SteelAxe;

struct {
    float baseEntityDamage = 11.2f;
    float baseBlockDamage = 35.5f;
} IronPickaxe;

struct {
    float baseEntityDamage = 23.2f;
    float baseBlockDamage = 62.8f;
} SteelPickaxe;

struct {
    float baseEntityDamage = 9.6f;
    float baseBlockDamage = 38.4f;
} StoneShovel;

struct {
    float baseEntityDamage = 11.6f;
    float baseBlockDamage = 51.0f;
} IronShovel;

struct {
    float baseEntityDamage = 17.4f;
    float baseBlockDamage = 69.0f;
} SteelShovel;

struct {
    float baseEntityDamage = 6.0f;
    float baseBlockDamage = 24.3f;
} Chainsaw;

struct {
    float baseEntityDamage = 4.2f;
    float baseBlockDamage = 20.7f;
} Auger;

struct {
    float baseEntityDamage = 16.5f;
    float baseBlockDamage = 38.5f;
} Wrench;

struct {
    float baseEntityDamage = 16.5f;
    float baseBlockDamage = 48.5f;
} Ratchet;

struct {
    float baseEntityDamage = 16.5f;
    float baseBlockDamage = 58.0f;
} ImpactDriver;

struct {
    float baseEntityDamage = 5.1f;
    float baseBlockDamage = 4.0f;
} BoneKnife;

struct {
    float baseEntityDamage = 6.1f;
    float baseBlockDamage = 5.3f;
} HuntingKnife;

struct {
    float baseEntityDamage = 6.6f;
    float baseBlockDamage = 5.5f;
} CandyKnife;

struct {
    float baseEntityDamage = 19.8f;
    float baseBlockDamage = 21.0f;
} Machete;

struct {
    float baseEntityDamage = 13.8f;
    float baseBlockDamage = 11.6f;
} WoodenClub;

struct {
    float baseEntityDamage = 17.4f;
    float baseBlockDamage = 14.6f;
} BaseballBat;

struct {
    float baseEntityDamage = 19.2f;
    float baseBlockDamage = 16.0f;
} CandyClub;

struct {
    float baseEntityDamage = 26.2f;
    float baseBlockDamage = 22.1f;
} SteelClub;

struct {
    float baseEntityDamage = 13.8f;
    float baseBlockDamage = 11.6f;
} PipeBaton;

struct {
    float baseEntityDamage = 10.8f;
    float baseBlockDamage = 6.0f;
} StunBaton;

struct {
    float baseEntityDamage = 10.8f;
    float baseBlockDamage = 6.0f;
} PlasmaBaton;

struct {
    float baseEntityDamage = 10.3f;
    float baseBlockDamage = 5.0f;
} StoneSpear;

struct {
    float baseEntityDamage = 12.4f;
    float baseBlockDamage = 7.0f;
} IronSpear;

struct {
    float baseEntityDamage = 18.6f;
    float baseBlockDamage = 9.0f;
} SteelSpear;

struct {
    float baseEntityDamage = 17.5f;
    float baseBlockDamage = 27.2f;
} StoneSledgehammer;

struct {
    float baseEntityDamage = 30.8f;
    float baseBlockDamage = 58.3f;
} IronSledgehammer;

struct {
    float baseEntityDamage = 46.2f;
    float baseBlockDamage = 85.0f;
} SteelSledgehammer;

struct {
    float baseEntityDamage = 6.2f;
    float baseBlockDamage = 2.2f;
} LeatherKnuckles;

struct {
    float baseEntityDamage = 9.1f;
    float baseBlockDamage = 3.0f;
} IronKnuckles;

struct {
    float baseEntityDamage = 13.6f;
    float baseBlockDamage = 5.2f;
} SteelKnuckles;

struct {
    float baseEntityDamage = 13.2f;
    float baseBlockDamage = 26.0f;
} IronHoe;

struct {
    float baseEntityDamage = 7.2f;
    float baseBlockDamage = 6.0f;
} Flashlight;

struct {
    float baseEntityDamage = 10.2f;
    float baseBlockDamage = 7.0f;
} Torch;

struct {
    float baseEntityDamage = 11.5f;
    float baseBlockDamage = 17.0f;
} RoboticSledge;

struct {
    float baseEntityDamage{};
    float baseBlockDamage{};
} structMelee;

struct {
    float baseEntityDamage{};
    float baseBlockDamage{};
} structRobot;

// turn this into a map because this is gorilla monkey code
void obtainMeleeWeapon(string meleeWeapon) {
    string arrayMeleeName[38] = {"StoneAxe", "TazasStoneAxe", "ClawHammer", "IronFireAxe", "SteelAxe",
    "IronPickaxe", "SteelPickaxe", "StoneShovel", "IronShovel", "SteelShovel", "Chainsaw", "Auger",
    "Wrench", "Ratchet", "ImpactDriver", "BoneKnife", "HuntingKnife", "CandyKnife", "Machete",
    "WoodenClub", "BaseballBat", "CandyClub", "SteelClub", "PipeBaton", "StunBaton", "PlasmaBaton",
    "StoneSpear", "IronSpear", "SteelSpear", "StoneSledgehammer", "IronSledgehammer", "SteelSledgehammer",
    "LeatherKnuckles", "IronKnuckles", "SteelKnuckles", "IronHoe", "Flashlight", "Torch"
    };

    float* arrayMeleeEntityDmg[38] = {&StoneAxe.baseEntityDamage, &TazasStoneAxe.baseEntityDamage,
    &ClawHammer.baseEntityDamage, &IronFireAxe.baseEntityDamage, &SteelAxe.baseEntityDamage,
    &IronPickaxe.baseEntityDamage, &SteelPickaxe.baseEntityDamage, &StoneShovel.baseEntityDamage,
    &IronShovel.baseEntityDamage, &SteelShovel.baseEntityDamage, &Chainsaw.baseEntityDamage,
    &Auger.baseEntityDamage, &Wrench.baseEntityDamage, &Ratchet.baseEntityDamage, 
    &ImpactDriver.baseEntityDamage, &BoneKnife.baseEntityDamage, &HuntingKnife.baseEntityDamage,
    &CandyKnife.baseEntityDamage, &Machete.baseEntityDamage, &WoodenClub.baseEntityDamage,
    &BaseballBat.baseEntityDamage, &CandyClub.baseEntityDamage, &SteelClub.baseEntityDamage,
    &PipeBaton.baseEntityDamage, &StunBaton.baseEntityDamage, &PlasmaBaton.baseEntityDamage,
    &StoneSpear.baseEntityDamage, &IronSpear.baseEntityDamage, &SteelSpear.baseEntityDamage,
    &StoneSledgehammer.baseEntityDamage, &IronSledgehammer.baseEntityDamage, &SteelSledgehammer.baseEntityDamage,
    &LeatherKnuckles.baseEntityDamage, &IronKnuckles.baseEntityDamage, &SteelKnuckles.baseEntityDamage,
    &IronHoe.baseEntityDamage, &Flashlight.baseEntityDamage, &Torch.baseEntityDamage
    };

    float* arrayMeleeBlockDmg[38] = {&StoneAxe.baseBlockDamage, &TazasStoneAxe.baseBlockDamage,
    &ClawHammer.baseBlockDamage, &IronFireAxe.baseBlockDamage, &SteelAxe.baseBlockDamage,
    &IronPickaxe.baseBlockDamage, &SteelPickaxe.baseBlockDamage, &StoneShovel.baseBlockDamage,
    &IronShovel.baseBlockDamage, &SteelShovel.baseBlockDamage, &Chainsaw.baseBlockDamage,
    &Auger.baseBlockDamage, &Wrench.baseBlockDamage, &Ratchet.baseBlockDamage, 
    &ImpactDriver.baseBlockDamage, &BoneKnife.baseBlockDamage, &HuntingKnife.baseBlockDamage,
    &CandyKnife.baseBlockDamage, &Machete.baseBlockDamage, &WoodenClub.baseBlockDamage,
    &BaseballBat.baseBlockDamage, &CandyClub.baseBlockDamage, &SteelClub.baseBlockDamage,
    &PipeBaton.baseBlockDamage, &StunBaton.baseBlockDamage, &PlasmaBaton.baseBlockDamage,
    &StoneSpear.baseBlockDamage, &IronSpear.baseBlockDamage, &SteelSpear.baseBlockDamage,
    &StoneSledgehammer.baseBlockDamage, &IronSledgehammer.baseBlockDamage, &SteelSledgehammer.baseBlockDamage,
    &LeatherKnuckles.baseBlockDamage, &IronKnuckles.baseBlockDamage, &SteelKnuckles.baseBlockDamage,
    &IronHoe.baseBlockDamage, &Flashlight.baseBlockDamage, &Torch.baseBlockDamage
    };

    for (int i = 0; i < 38; i++) {
        if (meleeWeapon == arrayMeleeName[i]) {
        	structMelee.baseEntityDamage = *arrayMeleeEntityDmg[i];
            structMelee.baseBlockDamage = *arrayMeleeBlockDmg[i];
        }
    }

}


//arrayRobots[1]
//arrayGuns
