#pragma once
#include "role.h"
#include <string>
class NPC :public Role {
public:
	void speaking();
	NPC() {
		id = 3;
	}
private:
	int id;
};