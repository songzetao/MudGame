#include "Utility.h"

string parseName(string name, int must_size) {
	int size = int(name.length());
	if (size == must_size) {
		return name;
	}
	stringstream ss;
	if (size < must_size) {
		for (int i = size; i < must_size; i++)
			ss << " ";
		ss << name;
	}
	else {
		for (int i = 0; i < size; i++)
			ss << name[i];
	}
	string res = ss.str();
	ss.str("");
	return res;
}

bool compareCmd(string str1, string str2)
{
	int s1 = str1.size();
	int s2 = str2.size();
	if (s1 < s2) {
		return false;
	}
	int a = 0 , b = 0;
	while (a < s1 && b < s2)
	{
		if (str1[a++] != str2[b++]) {
			return false;
		}
	}
	return true;
}

vector<string>* split(string text, char separated, char domin)
{
	vector<string>* res = new vector<string>();
	int s = 0, l = text.length();
	bool isInDomin = false , hasDomin = false;
	for (int i = 0; i < l; i++) {
		if (text[i] == separated && !isInDomin) {
			if(hasDomin)
				res->push_back(text.substr(s + 1, i - s - 2));
			else
				res->push_back(text.substr(s, i - s));
			hasDomin = false;
			s = i + 1;
		}
		else if (text[i] == domin) {
			isInDomin = !isInDomin;
			if(isInDomin)
				hasDomin = true;
		}
	}
	if (s < l || text[l-1] == separated)
		res->push_back(text.substr(s, l - s));
	return res;
}

vector<string>* split(string text, char separated)
{
	vector<string>* res = new vector<string>();
	int s = 0, l = text.length();
	for (int i = 0; i < l; i++) {
		if (text[i] == separated) {
			res->push_back(text.substr(s, i - s));
			s = i + 1;
		}
	}
	if (s < l) 
		res->push_back(text.substr(s, l - s));
	return res;
}

int safeStoi(string str)
{
	try {
		return stoi(str);
	}
	catch (...) {
		return 0;
	}
}

vector<int>* conv(vector<string>* vs , bool release)
{
	vector<int>* vi = new vector<int>();
	for (auto it = vs->begin(); it != vs->end(); it++) {
		vi->push_back(safeStoi(*it));
	}
	if(release)
		delete vs;
	return vi;
}

