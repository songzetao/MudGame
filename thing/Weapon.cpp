#include"Weapon.h"
int Weapon::getAttackValue() {
	return attack_value;
}
int Weapon::getDefenceValue() {
	return defence_value;
}
void Weapon::setAttackValue(int value) {
	attack_value = value;
}
void Weapon::setDefenceValue(int value) {
	defence_value = value;
}