#include "UComponent.h"

void UComponent::setOwner(UActorObject * _owner)
{
	owner = _owner;
}

void UComponent::init()
{
}

UActorObject * UComponent::getOwner()
{
	return owner;
}

void UComponent::update()
{

}

void UComponent::destroy()
{
}

