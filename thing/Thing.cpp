#include"Thing.h"
using namespace std;

Thing::Thing(string name) {
	this->name = name;
}
string Thing::getName() {
	return name;
}
void Thing::setName(string name)
{
	this->name = name;
}

