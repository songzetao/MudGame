#pragma once
#include <stack> 
#include <iostream>
using namespace std;

class UIManager {

public:
	void uiPush(string name);
	string uiPop();
	void showUI();
	//void uiShow();
private:
	stack<string> ui_manager_stack;

};
