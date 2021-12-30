#pragma once
#include "../Csv/QuestCsv.h"
#include "../Csv/RoleCsv.h"
class UTalkManager {
private:
	map<int, Quest*>* questMap = nullptr;
	Quest* quest = nullptr;

	bool isShowAside = true;
	stringstream * stalk = nullptr;
	int lineNum = 0;
	int nextNpcid = 0;
	string line;
public:
	UTalkManager();
	void saveTalking(string _line);
	void visitNpc(int npcid);
	void unVisitNpc(int npcid);
	void showTalking(Quest * quest);
	Quest* findNpc(int npcid);
	Quest* findQuest(int id);

	void init();
	void update();
	void Talking(string key, string cmd);
	void CheckAllTalking(string key, string cmd);
	void nextTalking(Quest * _quest);
	void clear();
};