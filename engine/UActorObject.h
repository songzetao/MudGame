#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include <list>
using namespace std;
class UComponent;


class UActorObject : public UObject {

private:
	
	UVector pos;
public:
	list<UComponent*>* componentList = new list<UComponent*>();
	UActorObject() {};
	UActorObject(int x , int y) {
		pos.x = x;
		pos.y = y;
	};
	virtual void update();
	void setPos(int x, int y) {
		pos.x = x;
		pos.y = y;
	}
	virtual void addComponent(UComponent *component);
	virtual void removeComponent(UComponent *component);
	virtual void destroy();
	UVector getPos() {
		return pos;
	};
};
