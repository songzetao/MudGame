#include "UObject.h"

string UObject::getName()
{
	return name;
}

UObject::UObject(string _name, int _id)
{
	name = _name;
	id = _id;
}

UObject::UObject()
{
	name = "";
	id = -1;
}

void UObject::setName(string _name)
{
	name = _name;
}

int UObject::getId()
{
	return id;
}

void UObject::setId(int _id)
{
	id = _id;
}
