#pragma once
#include<string>
#include<iostream>
#include"../UWorld.h"
#include"../Engine/UEventDispatcher.h"
using namespace std;

class UI {
public:
	void  bindKey(string key) {
		//UWorld::EventDispatcher.execute(uiName, key);
	}
private:
	string uiName;
};