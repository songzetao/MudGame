#include "UTalkComponent.h"

void UTalkComponent::init()
{

}

void UTalkComponent::update()
{
	UVector player_pos = world->Player->getPos();
	UVector owner_pos = getOwner()->getPos();

	if (abs(owner_pos.x - player_pos.x) < 2 && abs(owner_pos.y - player_pos.y) < 2) {
		world->TalkManager->visitNpc(getOwner()->getId());
	}
	else {
		world->TalkManager->unVisitNpc(getOwner()->getId());
	}
}
