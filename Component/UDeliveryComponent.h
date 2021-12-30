#pragma once
#include"../engine/UComponent.h"
#include"../UWorld.h"
class UDeliveryComponent :public UComponent {
public:
	UDeliveryComponent() {

	};

	void init();
	void update();
	void setNextMap(string _nextMap);
private:
	string nextMap;
};