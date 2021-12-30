#include "UActorObject.h"
#include "Utility.h"

void UActorObject::update()
{
	for (auto it = componentList->begin(); it != componentList->end(); it++) {
		(*it)->update();
	}
}

void UActorObject::addComponent(UComponent * component) {
	component->setOwner(this);
	component->init();
	componentList->push_back(component);
};
void UActorObject::removeComponent(UComponent *component) {
	component->setOwner(nullptr);
	listRemove(componentList, component);
}
void UActorObject::destroy()
{
	for (auto it = componentList->begin(); it != componentList->end(); it++) {
		(*it)->destroy();
	}
}

