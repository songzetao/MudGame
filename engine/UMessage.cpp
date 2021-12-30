#include "UMessage.h"
#include <iostream>
UMessage::UMessage()
{
}
void UMessage::append(string str)
{
	ss << color_header << str << color_tail;
}

void UMessage::appendLine(string str)
{
	ss << color_header << str << color_tail << "\n";
}

void UMessage::setColor(string _color_header, string _color_tail)
{
	color_header = _color_header;
	color_tail = _color_tail;
}

string UMessage::tostring()
{
	return ss.str();
}

void UMessage::show()
{
	cout << tostring();
}

void UMessage::clear()
{
	ss.str("");
	ss.clear();
}
