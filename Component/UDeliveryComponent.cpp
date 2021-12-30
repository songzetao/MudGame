#include "UDeliveryComponent.h"

void UDeliveryComponent::init()
{

}

void UDeliveryComponent::update()
{
	UVector player_pos = world->Player->getPos();
	UVector owner_pos = getOwner()->getPos();

	if (abs(owner_pos.x - player_pos.x) < 2 && abs(owner_pos.y - player_pos.y) < 2) {
		world->nextGameMap = nextMap;
		world->MessageManager->Info.appendLine("按任意键进入下一个地图!");
	}
}

void UDeliveryComponent::setNextMap(string _nextMap)
{
	nextMap = _nextMap;
}
