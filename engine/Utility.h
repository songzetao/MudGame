#pragma once
#include <string>
#include <sstream>
#include <list>   
#include <vector>   
using namespace std;

string parseName(string name, int must_size);
bool compareCmd(string s1, string s2);
vector<string>* split(string text, char separated , char domin);
vector<string>* split(string text, char separated);
int safeStoi(string str);

vector<int>* conv(vector<string>* vs , bool release);
template <class T>
inline bool listRemove(list<T>* tList, T _t) {
	for (auto it = tList->begin(); it != tList->end();it++) {
		if (*it == _t) {
			tList->erase(it);
			return true;
		}
	};

	return false;
}
