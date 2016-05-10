
// Writing to a random-access file
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h" // ClientData class definition
using namespace std;

int main()
{
	int accountNumber;
	string lastName;
	string firstName;
	double balance;

	fstream outCredit("credit.dat", ios::in | ios::out | ios::binary);

	// exit program if fstream annot open file
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // end if

	cout << "Enter account number(1 to 100, 0 to end input)\n" ;

	// require user to specify account number
	ClientData client;
	cin >> accountNumber;

	// user enteres information, which is copied into file
	while (accountNumber > 0 && accountNumber <= 100)
	{
		// user enters lat name, first name and balance
		cout << "Enter lat name, first name, balance\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;

		// set record accountNumber, lastName, firstName, and balance Values
		client.setAccountNumber(accountNumber);
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);

		// seek position in file of user-specified record
		outCredit.seekp( (client.getAccountNumber() - 1 ) * sizeof( ClientData) );

		// write user-specified information in file
		outCredit.write(reinterpret_cast<const char * >(&client), sizeof(ClientData));

		// enable user to enter another account
		cout << "Enter account number\n? ";
		cin >> accountNumber;
	}
}
