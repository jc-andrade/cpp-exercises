
// Create a randomly accessed file
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h" // ClientData class definition
using namespace std;

int main()
{
	ofstream outCredit("credit.dat", ios::out | ios::binary);

	// exit program if ofstream could not open file
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // end if

	ClientData bankClient; // constructor zeros out each data member

	// output 100 blank records to file
	for (int i = 0; i < 100; ++i)
		outCredit.write(reinterpret_cast<const char *>(&bankClient), sizeof(ClientData ));
}
