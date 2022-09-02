#include <iostream>
#include <string>
using namespace std;

struct {
    string var = "foo";
} stinger;

struct {
    string var = "boo";
} blinger;

struct {
    string var{};
} weapon;

int main() {
    string cond = "blinger"; // condition
    
    /* //too long if then chain
    if (x == "blinger"){
        x.var = &blinger.var;
    }
    else if (x == "stinger"){
        x.var = &stinger.var;
    }
    */
    
    string arrayName[2] = {"stinger", "blinger"};
    string* arrayAddress[2] = {&stinger.var, &blinger.var};
    for (int i = 0; i < 2; i++) {
    	cout << "arrayName: " << arrayName[i] << endl;
        cout << "arrayPtr: " << *arrayAddress[i] << endl;
        if (cond == arrayName[i]) {
        	weapon.var = *arrayAddress[i];
        }
        cout << "weapon.var: " << weapon.var << endl;
    }
    
    /*
    std::cout << stinger.var << endl;
    std::cout << blinger.var << endl;
    std::cout << x.var << endl; // this right here. Desired output is "boo" based on condition
	*/
    return 0;
}