#include <iostream>
using namespace std;

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
