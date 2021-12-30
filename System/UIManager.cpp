#include"UiManager.h"
#include"../UWorld.h"

string UIManager::uiPop() {
	string ui = ui_manager_stack.top();
	ui_manager_stack.pop();
	showUI();
	return ui;
}
void UIManager::uiPush(string name) {
	ui_manager_stack.push(name);
	showUI();
}
void UIManager::showUI() {
	string ui = ui_manager_stack.top();
	world->uiName = ui;
}