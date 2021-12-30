#pragma once
#include "../Csv/QuestCsv.h"
#include "../Csv/RoleCsv.h"

class UCsvManager {

public:
	QuestCsv* questCsv = nullptr;
	map<int, Quest*>* allQuestMap = nullptr;

	RoleCsv* roleCsv = nullptr;
	map<int, CRole*>* allRoleMap = nullptr;

	UCsvManager() {
		questCsv = new QuestCsv();
		questCsv->load();
		allQuestMap = questCsv->makeAllQuestMap();

		roleCsv = new RoleCsv();
		roleCsv->load();
		allRoleMap = roleCsv->makeAllRoleMap();
	};

	CRole* findCRole(int id);
	Quest* findCQuest(int id);
	Quest* findCQuestByNpcId(int npcid);
};