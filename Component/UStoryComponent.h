#pragma once

#include"../engine/UComponent.h"
#include"../UWorld.h"

class UStoryComponent :public UComponent {
public:
	void init();

	void update();

	void createRole(string key, string cmd);
	void delRole(string key, string cmd);
};