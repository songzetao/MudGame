#pragma once
#include<string>
#include<iostream>

using namespace std;

enum class  EThing
{
	Thing ,
	Weapon,
	Heal,
};

class Thing {
private:
	string name;

public:
	EThing type = EThing::Thing;
	Thing() {}
	Thing(string name);
    string getName();
    void setName(string name);
};