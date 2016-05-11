#include <string>
#include <iostream>
using namespace std;

class dog
{
	private:
		string name;
	public:
		void setname(string name) {this->name = name;}
		string getname() {return name;}
		dog() {setname("dog");}
		dog(string n) {setname(n);}
		string bark() {return "woof woof";}
};

class chihuahua: public dog
{
	public:
		string bark() {return "yap yap";}
		// add overloaded constructor
		chihuahua(string n) {setname(n);}
};

int main()
{
	dog d("Sparky");
	chihuahua c("Chi chi");

	cout << d.getname() << " goes " << d.bark() << endl; // dog goes bark bark
	cout << c.getname() << " goes " << c.bark() << endl; // dog goes yap yap
	
	// We fix by using overloaded constructor to provide name
	
}
