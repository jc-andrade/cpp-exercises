// Copyright Julio Andrade
// This is just a program I made as an exercise, practicing bitwise operations.

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

// display bits o an unsigned integer value
void displayBits(unsigned value)
{
	const int SHIFT = 8 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT; // mask = 1000 000 000 000 rn
	
	cout << setw(10) << value << " = ";

	// display bits
	for (unsigned i = 1; i <= SHIFT + 1; ++ i)
	{
	  cout << (value & MASK ? '1' : '0');
	value <<= 1; // shift value left by 1

	if (i % 8 == 0) // every 8 bits
	  cout << ' '; // output space
	}
  cout << endl;
}

