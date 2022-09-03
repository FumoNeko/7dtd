// g++ -std=c++17 -o program.out program.cpp
#include <iostream>
#include <string>
#include <array>
using namespace std;
/*
int main() {
	int i, n;
	cout << "Enter the number of items:" << "\n";
	cin >> n;

	int *arr = new int(n);
	cout << "Enter " << n << " items" << endl;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
    cout << "You entered: ";
	for (i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
*/

int main() {
	string *users = NULL;
	int seatNum = 0;
	
	cout << "Enter seat number: ";
	cin >> seatNum;
	cout << endl;
	
	users = new string[seatNum];
	string name;
	
	cout << "Enter name: ";
	cin >> name;
	cout << endl;
	
	users[seatNum-1] = name;

	cout << "users[0]: " << users[0] << endl;
	cout << "users[1]: " << users[1] << endl;
	cout << "users[2]: " << users[2] << endl;
	cout << "users[3]: " << users[3] << endl;
	cout << "users[4]: " << users[4] << endl;
	cout << "users[5]: " << users[5] << endl;
	cout << "users[6]: " << users[6] << endl;
}