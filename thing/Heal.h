#pragma once
#include"Thing.h"
class Heal : public Thing {
private:
	int blood_add;
public:
	int getBloodValue();
	Heal(string name1, int blood):Thing(name1) {
		type = EThing::Heal;
		this->blood_add = blood;
	}
	Heal() :Thing(),blood_add(0){
		type = EThing::Heal;
	}
};