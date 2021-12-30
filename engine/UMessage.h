#pragma once
#include <string>
#include <sstream>
using namespace std;

class UMessage {
private:
	stringstream ss;
	string color_header;
	string color_tail;

public:
	UMessage();
	void append(string str);
	void appendLine(string str);
	void setColor(string _color_header, string _color_tail);
	string tostring();
	void show();
	void clear();
};