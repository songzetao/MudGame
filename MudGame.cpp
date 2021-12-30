// MudGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Engine/UActorObject.h"
#include "Engine/UGameMap.h"
#include "Engine/Const.h"
#include "Role/player.h"
#include "Role/NPC.h"
#include "Role/monster.h"
#include "Component/UTalkComponent.h"
#include "Component/UMovementComponent.h"
#include "Component/UbagComponent.h"
#include "Component/UMeshComponent.h"
#include "Component/UDeliveryComponent.h"
#include "Component/UStoryComponent.h"

void readSet(Role* role, int id) {
	CRole* cr = world->CsvManager->findCRole(id);
	if (cr) {
		role->setName(cr->name);
		role->displayName = cr->showname;
	}
}
Weapon * addWeap(UGameMap* Map , int x , int y , string name , int id) {
	UActorObject* weap = new UActorObject();
	weap->setPos(x, y);
	UMeshComponent* meshComp = new UMeshComponent();
	weap->addComponent(meshComp);
	Weapon* thing = new Weapon();
	thing->setName(name);
	meshComp->setMesh(thing, id);
	Map->addActor(weap);
	return thing;
}
Heal* addHeal(UGameMap* Map, int x, int y, string name, int id) {
	UActorObject* heal = new UActorObject();
	heal->setPos(x, y);
	UMeshComponent* meshComp = new UMeshComponent();
	heal->addComponent(meshComp);
	Heal* thing = new Heal();
	thing->setName(name);
	meshComp->setMesh(thing, id);
	Map->addActor(heal);
	return thing;
}

Hero* addPlayer(UGameMap * Map ,int x , int y , string name , int id) {
	
	Hero* player = new Hero();
	player->setName(name);
	player->setPos(x, y);
	player->setId(id);
	UMovementComponent* playerMCom = new UMovementComponent();
	Bag* bag = new Bag();
	player->addComponent(playerMCom);
	player->addComponent(bag);
	Map->addActor(player);
	readSet(player, id);
	return player;
}
NPC* addNpc(UGameMap* Map, int x, int y, string name, int id) {
	NPC* npc = new NPC();
	npc->setName(name);
	npc->setPos(x, y);
	npc->setId(id);
	UTalkComponent* comp = new UTalkComponent();
	npc->addComponent(comp);
	Map->addActor(npc);
	readSet(npc, id);
	return npc;
}

UDeliveryComponent* addDelivery(UGameMap* Map, int x, int y, string name, int id , string nextMap) {
	UActorObject* actor = new UActorObject();
	actor->setPos(x, y);
	UDeliveryComponent* delivery = new UDeliveryComponent();
	delivery->setNextMap(nextMap);
	actor->addComponent(delivery);
	actor->setName(name);
	Map->addActor(actor);
	return delivery;
}

Monster* addMonest(UGameMap* Map, int x, int y, string name, int id) {
	Monster* monster = new Monster();
	monster->setName(name);
	monster->setPos(x, y);
	monster->setId(id);
	UTalkComponent* comp = new UTalkComponent();
	monster->addComponent(comp);
	Map->addActor(monster);
	readSet(monster, id);
	return monster;
}
UStoryComponent* addStory(UGameMap* Map) {
	UActorObject* actor = new UActorObject();
	actor->setPos( 0, 0);
	actor->setId(c_aside_id);
	UStoryComponent* comp = new UStoryComponent();
	actor->addComponent(comp);
	Map->addActor(actor);
	return comp;
}
void makeMainScene(string key, string cmd) {
	UGameMap * Map = new UGameMap(10, 10);
	world->gameMapName = "上海 main";
	Hero* player = addPlayer(Map, 4, 4, "xiaotu", c_player_id);
	addWeap(Map, 4, 4, "weap", 1);
	addHeal(Map, 2, 1, "heal", 1);
	addMonest(Map, 4, 7, "monest", 101);
	addNpc(Map, 7, 7, "fangmin", 1);
	addDelivery(Map, 8, 8, "transport", 1 , "level1");

	world->GameMap = Map;
	world->Player = player;
}

void makeLevel1(string key, string cmd) {
	UGameMap* Map = new UGameMap(10, 15);
	world->gameMapName = "图书馆 level1";
	Hero* player = addPlayer(Map, 4, 4, "you", c_player_id);
	addWeap(Map, 5, 5, "weap2", 2);
	addHeal(Map, 2, 1, "heal2", 2);
	addMonest(Map, 4, 1, "monest2", 102);
	addNpc(Map, 4, 7, "npc2", 2);
	addDelivery(Map, 8, 2, "transport2", 1, "level2");

	world->GameMap = Map;
	world->Player = player;
}

void makeLevel2(string key, string cmd) {
	UGameMap* Map = new UGameMap(15, 10);
	world->gameMapName = "  学院 level2 ";
	Hero* player = addPlayer(Map, 4, 4, "you", c_player_id);
	addWeap(Map, 1, 1, "weap3", 3);
	addHeal(Map, 4, 6, "heal3", 3);
	addMonest(Map, 4, 2, "monest3", 103);
	addNpc(Map, 1, 7, "npc3", 3);
	addDelivery(Map, 2, 2, "transport3", 1, "copy");
	world->GameMap = Map;
	world->Player = player;
}

void makeRandLevel(string key, string cmd) {
	int row = rand() % 10 + 5;
	int col = rand() % 10 + 5;
	UGameMap* Map = new UGameMap(row, col);
	world->gameMapName = "副本 copy";
	Hero* player = addPlayer(Map, rand() % (row -1), rand() % (col - 1), "you", c_player_id);
	int weapid = rand() % 100;
	addWeap(Map, rand() % (row - 1), rand() % (col - 1), "weap", weapid);
	int healid = rand() % 100;
	addHeal(Map, rand() % (row - 1), rand() % (col - 1), "heal" , healid);
	int monestid = rand() % 100 + 100;
	addMonest(Map, rand() % (row - 1), rand() % (col - 1), "monest" , monestid);
	int npcid = rand() % 10;
	addNpc(Map, rand() % (row - 1), rand() % (col - 1), "npc"+to_string(npcid), npcid);
	int delid = rand() % 100;
	addDelivery(Map, rand() % (row - 1), rand() % (col - 1), "transport", delid, "copy");
	world->GameMap = Map;
	world->Player = player;
}

void makeStory(string key, string cmd) {
	int row = 10;
	int col = 10;
	UGameMap* Map = new UGameMap(row, col);
	world->gameMapName = "副本 copy";
	Hero* player = addPlayer(Map, rand() % (row - 1), rand() % (col - 1), "you", c_player_id);
	addStory(Map);
	world->GameMap = Map;
	world->Player = player;
}

int main()
{
	
	world->EventDispatcher = new UEventDispatcher();
	world->MessageManager = new UMessageManager();

	world->CsvManager = new UCsvManager();
	world->TalkManager = new UTalkManager();
	world->TalkManager->init();
	world->gameTitle = "---------隐形守护者---------";
	world->MessageManager->Tip.appendLine("欢迎进入游戏！！！");

	world->addScene("main", makeMainScene);
	world->addScene("level1", makeLevel1);
	world->addScene("level2", makeLevel2);
	world->addScene("copy", makeRandLevel);
	world->addScene("story", makeStory);

	world->makeScene("main");
	world->init();
	world->update();
	world->run();
}
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
//
// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
