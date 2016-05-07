// Copyright Julio Andrade
// This is just a program I made as an exercise, practicing bitwise operations.

#include "displayBits.h" // displayBits function
#include <iostream>
#include <iomanip>
using namespace std;

void displayBits(unsigned); // prototype

int main()
{
	unsigned number1;
	unsigned number2;
	unsigned mask;
	unsigned setBits;

	// demonstrate bitwise &
	number1 = 2179876355;
	mask = 1;
	cout << "The result of combining the following\n";
	displayBits(number1);
	displayBits(mask);

	cout << "using the bitwise AND operator & is\n";
	displayBits(number1 & mask);

	// demonstrate bitwise |
	number1 = 15;
	setBits = 241;
	cout << "\nThe result of comining the following\n";
	displayBits(number1);
	displayBits(setBits);
	cout << "using the bitwise inclusive OR operator | is\n";
	displayBits(number1 | setBits);

// demonstrate bitwise excusive OR
	number1 = 139;
	number2 = 199;
	cout << "\nThe result of comining the following\n";
	displayBits(number1);
	displayBits(number2);
	cout << "using the bitwise exclusive OR operator ^ is\n";
	displayBits(number1 ^ number2);

	// demonstrate bitwise complement
	number1 = 21845;
	cout << "\nThe one's complement of\n";
	displayBits(number1);
	cout << "is" << endl;
	displayBits(~number1);
} // end main
