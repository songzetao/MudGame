#pragma once
#include"role.h"

class Monster :public Role {
public:
	Monster() {
		id = 2;
	}
private:
	int id;
};
