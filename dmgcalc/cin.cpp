#include <iostream>
#include <string>
using namespace std;

int checkInput(){
    try {
        string str{};
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i]) == true) {
                cout << "OK" << endl;
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

int main(){
    cout << "------Set Variable: Quality------" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "1. Quality 1" << endl;
    cout << "2. Quality 2" << endl;
    cout << "3. Quality 3" << endl;
    cout << "4. Quality 4" << endl;
    cout << "5. Quality 5" << endl;
    cout << "6. Quality 6" << endl;
    
    int result = checkInput();
    cout << result << endl;

    return 0;
}