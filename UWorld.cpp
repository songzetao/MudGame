#include "UWorld.h"
#include <iostream>   
#include "engine/Utility.h"
using namespace std;
void UWorld::render()
{
	if (GameMap != nullptr) {
		GameMap->render();
	}
}

void UWorld::update()
{
	
	if (nextGameMap != "") {
		GameMap->destroy();
		TalkManager->clear();
		makeScene(nextGameMap);
		nextGameMap = "";
	}
	MessageManager->Tip.appendLine("输入 h + 指令名字 可获取帮助");
	MessageManager->Tip.appendLine("输入 iexit 退出游戏");
	MessageManager->Tip.appendLine("输入 itrans + 空格 + 地图英文名 切换地图");
	MessageManager->Title.appendLine(gameTitle);
	MessageManager->Title.appendLine(gameMapName);
	if (GameMap != nullptr) {
		GameMap->update();
	}
	if (TalkManager != nullptr) {
		TalkManager->update();
	}
}

void UWorld::run()
{
	Running = true;
	while (Running) {
		system("cls");
		if (preEnd)Running = false;
		MessageManager->show();
		render();
		string cmd;getline(cin , cmd);
		EventDispatcher->executeInput(uiName , cmd);
		update();
	}
}

void UWorld::init()
{
	EventDispatcher->bindEvent("i", this, &UWorld::iexit);
	EventDispatcher->bindEvent("i", this, &UWorld::ijump);
	EventDispatcher->bindEvent("h", this, &UWorld::htrans);
}

void UWorld::htrans(string key, string cmd)
{
	if (compareCmd(cmd, "trans")) {
		MessageManager->Info.appendLine(levels);
	}
}

void UWorld::iexit(string key ,string cmd)
{
	if ( compareCmd(cmd , "exit")) 
		preEnd = true;
}

void UWorld::ijump(string key, string cmd)
{
	auto vs = split(cmd, ' ');
	if (vs->size() == 2 && compareCmd((*vs)[0] , "trans") ) {
		makeScene((*vs)[1]);
	}
}

UWorld * world =new UWorld();