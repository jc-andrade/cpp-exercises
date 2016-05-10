

#include <iostream>
#include <string>
#include <fstream> // file stream
#include <cstdlib>
using namespace std;

int main()
{
	// ofsstream constructor opens file
	ofstream outClientFile("clients.txt", ios::out);

	// exit program if unable to create file
	if (!outClientFile) // overloaded ! operator
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}// end if

	cout << "Enter the account, name and balance." << endl
		<< "Enter end-of-file to en input.\n? ";

	int account;
	string name;
	double balance;

	// read account, name and balance from cin, then place in file
	while (cin >> account >> name >> balance)
	{
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	}// end while
}
