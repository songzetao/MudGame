#pragma once
#include"../Engine/UComponent.h"
#include "../UWorld.h"

class UTalkComponent :public UComponent {
public:
	void init();

	void update();
};