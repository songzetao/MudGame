#include "UStoryComponent.h"
#include "../engine/Utility.h"
#include "UTalkComponent.h"
void UStoryComponent::init()
{
	world->EventDispatcher->bindEvent("i", this, &UStoryComponent::createRole);
	world->EventDispatcher->bindEvent("i", this, &UStoryComponent::delRole);
}

void UStoryComponent::update()
{
	world->MessageManager->Tip.appendLine("输入 icreate/idel + 空格 + actorid 可在当前位置创建删除actor");
	UVector player_pos = world->Player->getPos();
	UVector owner_pos = getOwner()->getPos();

	world->TalkManager->visitNpc(getOwner()->getId());
}
Role* addRole(UGameMap* Map, int x, int y, int id) {
	CRole* cr = world->CsvManager->findCRole(id);
	if (cr) {
		Role* actor = new Role();
		actor->setPos(x, y);
		actor->setId(id);
		UTalkComponent* comp = new UTalkComponent();
		actor->addComponent(comp);
		Map->addActor(actor);
		actor->setName(cr->name);
		actor->displayName = cr->showname;
		return actor;
	}
	return nullptr;
}

void rmRole(UGameMap* Map , UActorObject * owner, int x, int y) {
	UActorObject* actor = Map->searchActor(x, y);
	if (actor && actor != owner)Map->removeActor(actor);
}

void UStoryComponent::createRole(string key, string cmd)
{
	auto vs = split(cmd, ' ');
	if (vs->size() == 2 && compareCmd((*vs)[0], "create")) {
		int id = safeStoi((*vs)[1]);
		auto pos = world->Player->getPos();
		addRole(world->GameMap, pos.x, pos.y, id);
	}
}

void UStoryComponent::delRole(string key, string cmd)
{
	if (compareCmd(cmd, "del")) {
		auto pos = world->Player->getPos();
		rmRole(world->GameMap,getOwner(), pos.x, pos.y);
	}
}
