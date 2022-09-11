#include <string>
using namespace std;

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
} selected;

struct {
    string Name[38];
    float EntityDmg[38];
    float BlockDmg[38];
} dataMelee;

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