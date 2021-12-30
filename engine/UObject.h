#pragma once
#include <string>
using namespace std;

class UObject {
private:
	string name;
	int id;

public:
	UObject(string name, int id);

	UObject();

	void setName(string name);
	void setId(int id);
	string getName();
	int getId();
};