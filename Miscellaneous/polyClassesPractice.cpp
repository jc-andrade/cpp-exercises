/* Using http://www.learncpp.com/cpp-tutorial/121-pointers-and-references-to-the-base-class-of-derived-objects/
   as reference 
*/

#include <string>
#include <iostream>
using namespace std;

// By using virtual functions, it tells the program to go look and see if there are any more-derived versions of the function available.

class Animal
{
	protected:
		string m_strName;
		// We're making this constructor protected because
		// We don't want people creating Animal objects directly,
		// But we still want derived classes to be able to useit.
		Animal(string strName)
			: m_strName(strName) {}
	public:
		string getName() {return m_strName; }
		virtual const char * speak() { return "???"; }
};

class Cat: public Animal
{
	public:
		Cat(string strName)
			: Animal(strName) {}
		virtual const char * speak() { return "Meow";}
};

class Dog: public Animal
{
	public: Dog(string strName)
		: Animal(strName) {}
		virtual const char * speak() { return "Woof";}
};

int main()
{
	Cat cCat("Fred");
		cout << "cCat is named " << cCat.getName() << ", and it says " << cCat.speak() << endl;
	
	Dog cDog("Garbo");
	cout << "cDog is named " << cDog.getName() << ", and it says " << cDog.speak() << endl;

	Animal *pAnimal = &cCat;
	cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

	pAnimal = &cDog;
	cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << endl;

	// Make a quick break
	for (int i = 0; i < 40; i++)
		cout << "-";

	cout << endl;
	// End break
	// Practice with array and pointers and references to make sure virtual functions are working properly
	Cat cFred("Fred"), cTyson("Tyson"), cZeke("Zeke");
	Dog cGarbo("Garbo"), cPooky("Pooky"), cTruffle("Truffle");

	// Setup array of pointers to animals, and set those pointers to our cat and dog objects
	Animal *apcAnimals[] = {&cFred, &cGarbo, &cPooky, &cTruffle, &cTyson, &cZeke};
	for (int iii=0; iii < 6; iii++)
		cout << apcAnimals[iii]->getName() << " says " << apcAnimals[iii]->speak() << endl;

	return 0;
}
