#pragma once
#include"../Engine/UActorObject.h"
class Role:public UActorObject {
public:
	/*role(int nattack_value, int ndefence_value, int nblood_value) {
		attack_value = nattack_value;
		defence_value = ndefence_value;
		blood_value = nblood_value;
	}*/
	string displayName;
private:
	int attack_value = 0;
	int defence_value = 0;
	int blood_value = 0;
};

