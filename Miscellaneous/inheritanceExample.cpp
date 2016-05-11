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
};

int main()
{
	dog d;
	chihuahua c;

	cout << d.getname() << " goes " << d.bark() << endl;
	cout << c.getname() << " goes " << c.bark() << endl;
}
