#include "UMeshComponent.h"
#include "../UWorld.h"
#include "UbagComponent.h"
void UMeshComponent::setMesh(Thing* thing)
{
	auto owner = getOwner();
	mesh = thing;
	if (owner == nullptr) {
		return;
	}
	owner->setName(thing->getName());
	mesh = thing;
}

void UMeshComponent::setMesh(Thing* thing, int id)
{
	auto owner = getOwner();
	mesh = thing;
	if (owner == nullptr) {
		return;
	}
	owner->setName(thing->getName());
	owner->setId(id);
}

void UMeshComponent::update()
{
	UVector player_pos =  world->Player->getPos();
	UVector owner_pos = getOwner()->getPos();

	if (abs(owner_pos.x - player_pos.x) < 2 && abs(owner_pos.y - player_pos.y) < 2) {
		auto owner = getOwner();
		world->MessageManager->Info.appendLine("恭喜你获得 物品： " + owner->getName());
		world->GameMap->removeActor(owner);
		auto bag = world->findComponent<Bag>(world->Player);
		if (bag != nullptr) {
			bag->addThing(mesh);
		}
	}

}
