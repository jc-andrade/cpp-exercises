#include "displayBits.h"
#include <iomanip>

int main()
{
	unsigned number1 = 960;

	// demonstrate bitwise left shift
	cout << "The result of left shifting\n";
	displayBits(number1);
	cout << "8 bit positions using the left-shift operator is\n";
	displayBits(number1 << 8);

	/// demonstrate bitwise right shift
	cout << "\nThe result of right shifting\n";
	displayBits(number1);
	cout << "8 bit positions using the right-shift operator is\n";
	displayBits(number1 >> 8);
}
