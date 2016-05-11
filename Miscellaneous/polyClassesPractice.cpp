/* Using http://www.learncpp.com/cpp-tutorial/121-pointers-and-references-to-the-base-class-of-derived-objects/
   as reference 
*/

#include <string>
#include <iostream>
using namespace std;

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
		const char * speak() { return "???"; }
};

class Cat: public Animal
{
	public:
		Cat(string strName)
			: Animal(strName) {}
		const char * speak() { return "Meow";}
};

class Dog: public Animal
{
	public: Dog(string strName)
		: Animal(strName) {}
		const char * speak() { return "Woof";}
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

	return 0;
}
