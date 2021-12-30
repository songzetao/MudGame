#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
using namespace std;

typedef vector<string>* CellVector_p;
class Csv {

public:
	map<int, CellVector_p>* csv_data = new map<int, CellVector_p>();
	map<string, int>* csv_header = new map<string, int>();
	string path = "";
public:
	
	void load();
	int getIndex(string str);
	string getCell(int id, int index);
	string getCell(int id, string str);

	int convIntCell(string name , CellVector_p cells);
	string convStrCell(string name ,CellVector_p cells);
};