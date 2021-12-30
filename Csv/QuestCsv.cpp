#include "QuestCsv.h"
#include "../Engine/Utility.h"


map<int, Quest*>* QuestCsv::makeAllQuestMap()
{
	map<int, Quest*>* res = new map<int, Quest*>();
	for (auto it = csv_data->begin(); it != csv_data->end(); it++) {
		Quest* quest = new Quest();
		auto vs = it->second;
		quest->id = it->first;

		quest->text = convStrCell("text", vs);
		quest->next = convIntCell("next", vs);
		quest->choice = conv(split(convStrCell("choice", vs) , ',' ) , true);
		quest->npcid = convIntCell("npcid", vs);
		quest->before = convStrCell("before", vs);
		quest->after = convStrCell("after", vs);
		quest->name = convStrCell("name", vs);
		res->insert(pair<int , Quest*>(quest->id , quest));
	}
	return res;
}

map<int, Quest*>* QuestCsv::makeQuestMap()
{
	return new map<int, Quest*>();
}
