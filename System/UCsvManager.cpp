#include "UCsvManager.h"

CRole* UCsvManager::findCRole(int id)
{
	auto it = allRoleMap->find(id);
	if (it != allRoleMap->end())
		return it->second;
	return nullptr;
}

Quest* UCsvManager::findCQuest(int id)
{
	auto it = allQuestMap->find(id);
	if (it != allQuestMap->end())
		return it->second;
	return nullptr;
}

Quest* UCsvManager::findCQuestByNpcId(int npcid)
{
	for (auto it = allQuestMap->begin(); it != allQuestMap->end(); it++) {
		if (it->second->npcid == npcid)
			return it->second;
	}
	return nullptr;
}
