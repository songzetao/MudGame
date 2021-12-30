#include"UMovementComponent.h"
#include<iostream>
#include<functional>
#include "../Engine/Delegate.h"
#include "../Engine/Utility.h"
using namespace std;

void UMovementComponent::init()
{
	world->EventDispatcher->bindEvent("w" ,this, &UMovementComponent::MoveForward);
	world->EventDispatcher->bindEvent("s", this, &UMovementComponent::MoveBack);
	world->EventDispatcher->bindEvent("a", this, &UMovementComponent::MoveLeft);
	world->EventDispatcher->bindEvent("d", this, &UMovementComponent::MoveRight);

}
void UMovementComponent::MoveForward(string key , string cmd) {
	UVector tempPos = this->getOwner()->getPos();
	int step = 1;
	if (cmd != "")
		step = safeStoi(cmd);
	tempPos.x-= step;
	tempPos.y;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围,无法移动");
}

void UMovementComponent::MoveBack(string key, string cmd) {
	UVector tempPos = this->getOwner()->getPos();
	int step = 1;
	if (cmd != "")
		step = safeStoi(cmd);
	tempPos.x += step;
	tempPos.y;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围,无法移动");
}

void UMovementComponent::MoveLeft(string key, string cmd) {
	UVector tempPos = this->getOwner()->getPos();
	int step = 1;
	if (cmd != "")
		step = safeStoi(cmd);
	tempPos.y-=step;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围,无法移动");
}

void UMovementComponent::MoveRight(string key, string cmd) {
	UVector tempPos = this->getOwner()->getPos();
	int step = 1;
	if (cmd != "")
		step = safeStoi(cmd);
	tempPos.y+=step;
	if (world->GameMap->checkMap(tempPos.x, tempPos.y))
		this->getOwner()->setPos(tempPos.x, tempPos.y);
	else
		world->MessageManager->Error.appendLine("超出地图范围,无法移动");
}

void UMovementComponent::update()
{
	world->MessageManager->Tip.appendLine("请输入w a s d 移动 后加数字移动");
}

void UMovementComponent::destroy()
{
	world->EventDispatcher->unBindEvent("w", this, &UMovementComponent::MoveForward);
	world->EventDispatcher->unBindEvent("s", this, &UMovementComponent::MoveBack);
	world->EventDispatcher->unBindEvent("a", this, &UMovementComponent::MoveLeft);
	world->EventDispatcher->unBindEvent("d", this, &UMovementComponent::MoveRight);
}
