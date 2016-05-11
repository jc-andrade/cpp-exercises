// Multi-purpose Selection Sort using Function Pointers

// Function selectionSort receives a pointer to a function - either function ascending or descending as an argument
// in addition to the integer array to sort
// and the size of the array.

#include <iostream>
#include <iomanip>
using namespace std;

//prototypes
//					prototype for pointer to a function
void selectionSort(int [], const int, bool(*)(int, int) );
void swap(int * const, int * const); // const pointer to int
bool ascending(int, int); // implements ascending order
bool descending(int, int); // implements descending order

int main()
{
	const int arraySize = 10;
	int order; // 1 = ascending, 2 = descending
	int counter; // array index
	int a[arraySize] = {2,6,4,8,10,12,89,68,45,37};

	cout << "Enter 1 to sort in ascending order,\n"
	<< "Enter 2 to sort in descending order: ";
	cin >> order;
	cout << "\nData items in original order\n";

	// output original array
	for(counter = 0; counter < arraySize; ++counter)
		cout << setw(4) << a[counter];

	// sort array in ascending order; pass function ascending
	// as an argument to specify ascending sorting order
	if (order == 1)
	{
		selectionSort(a, arraySize, ascending);
		cout << "\nData items in ascending order\n";
	} // end if

	// sort array in descending order; pass function descending
	// as an argument to specify descending sorting order
	else
	{
		selectionSort(a, arraySize, descending);
		cout << "\nData items in descending order\n";
	} // end else part of if else

	// output sorted array
	for (counter = 0; counter < arraySize; ++counter)
		cout << setw(4) << a[counter];

	cout << endl;
}

// multipurpose selection sort; the parameter compare is a pointer to
// the comparing function that determines the sorting order
// 						() around compare tell us its a pointer to a fx
void selectionSort(int work[], const int size, bool(*compare)(int, int))
{
	int smallestOrLargest; // index of smallest (or largest) element

	// loop over size - 1 elements
	for (int i = 0; i < size -1; ++i)
	{
		smallestOrLargest = i; // first index of remaining vector
		// loop to find index of smallest [or largest] element
		for (int index = i + 1; index < size; ++index)
			if ( !(*compare)(work[smallestOrLargest], work[index] ) )
				smallestOrLargest = index;

		swap (&work [smallestOrLargest], &work[i] );
	} // end if
} // end function selectionSort

void swap (int * const element1Ptr, int * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
} // end the swap

// determine whether a is less than b, for ascending order sort
bool ascending(int a, int b)
{
	return a < b; // returns true if a is less than b
} // end fuinction ascending

// determine whether element a is greater than 
// b for descending order sort
bool descending(int a, int b)
{
	return a > b;
} // end function descending
