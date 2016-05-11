// Demonstrating function objects
#include <iostream>
#include <vector> // vector class-template definition
#include <algorithm> // copy algorithm
#include <numeric> // accumulate algorithm
#include <functional> // binary_functiond efinition
#include <iterator>
using namespace std;

// binary function that adds square of its SECOND argument and
// the RUNNING total in its FIRST argument, then returns the sum
int sumSquares(int total, int value)
{
	return total + value * value;
} // end function sumSquares

// binary function CLASS TEMPLATE defines overloaded() operator
// that adds the square of its secong arg and running
// total in its first arg, then returns sum
template<typename T>
class sumSquaresClass : public binary_function<T, T, T>
{
	public:
	// add square of value to total and return the result
	T operator()(const T &total, const T &value)
	{
		return total + value * value;
	} // end function operator()
}; // end class sumSquaresClass

int main()
{
	const int SIZE = 10;
	int array[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> integers(array, array+SIZE); // copy of array
	ostream_iterator<int> output(cout, " ");
	int result;

	cout << "vector integers contains:\n";
	copy(integers.begin(), integers.end(), output);

	// calculate the sum of squares of elements of vector integeres
	// using binary function sumSquares
	result = accumulate(integers.begin(), integers.end(), 0, sumSquares);

	cout << "\n\nSum of squares of elements in integeres using " 
		<< "binary\nfunction sumSquares: " << result;

	// calculate sum of squares of elements of vector integers
	// using binary function object
	result = accumulate(integers.begin(), integers.end(), 0, sumSquaresClass<int>() );

	cout << "\n\nSum of squares of elements in integers using "
		<< "binary\nfunction object of type " 
		<< "sumSquaresClass< int >: " << result << endl;
} // end main

