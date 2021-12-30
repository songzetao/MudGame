#pragma once
#include "Csv.h"

class CRole {
public:
	int id = 0;
	string name = "";
	string showname = "";
};
class RoleCsv : public Csv {
public:
	RoleCsv() {
		path = "./Csv/role.csv";
	};

	map<int, CRole*>* makeAllRoleMap();
	map<int, CRole*>* makeRoleMap();
};