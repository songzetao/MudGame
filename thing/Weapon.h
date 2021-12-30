#pragma once
#include"Thing.h"

class Weapon : public Thing{
private:
	int attack_value;
	int defence_value;
	//int dodge_value;
public:
	Weapon(string name, int attackValue,int defenceValue) :Thing(name) {
		type = EThing::Weapon;
		this->attack_value = attackValue;
		this->defence_value = defenceValue;
	}
	Weapon():Thing(),attack_value(0),defence_value(0){
		type = EThing::Weapon;
	}
	int getAttackValue();
	int getDefenceValue();
	void setAttackValue(int value);
	void setDefenceValue(int value);
	//int getDodgeValue();
	//void setDodgeValue();
	

};