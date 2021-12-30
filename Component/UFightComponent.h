#pragma once
#include"../Engine/UComponent.h"
#include "..//UWorld.h"
#include"..//engine/UVector.h"
class UFightComponent:public UComponent {
public:
	int attack() {
		UVector temp_pos;
		temp_pos=world->Player->getPos();
	}
private:

};