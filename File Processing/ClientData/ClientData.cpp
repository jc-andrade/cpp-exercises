
// Class ClientData stores customer's credit info
#include <string>
#include "ClientData.h"
using namespace std;

// default const
ClientData::ClientData(int accountNumberValue, string lastNameValue, string firstNameValue, double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setLastName(lastNameValue);
	setFirstName(firstNameValue);
	setBalance(balanceValue);
} // end CLientData constructor

// get account-number value
int ClientData::getAccountNumber() const
{
	return accountNumber;
}

// set account-number value
void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue; // should validate
}

// get last-name value
string ClientData::getLastName() const
{
	return lastName;
} // end function getLastName

// set last-name value
void ClientData::setLastName(string lastNameString)
{
	// copy at most 15 characters from string to lastName
	int length = lastNameString.size();
	length = (length < 15 ? length : 14);
	lastNameString.copy(lastName, length);
	lastName[length] = '\0'; // apend null character to lastName
} // end function setLastName

// get first-name value
string ClientData::getFirstName() const
{
	return firstName;
}

// set first-name value
void ClientData::setFirstName (string firstNameString) 
{
	int length = firstNameString.size();
	length = (length < 10 ? length : 9);
	firstNameString.copy(firstName, length);
	firstName[length] = '\0'; // append null character to firstName
} // end function setFirstName

// get balance value
double ClientData::getBalance() const
{
	return balance;
} // end function getBalance

// set balance value
void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
} // end function setBalance


