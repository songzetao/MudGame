#pragma once
#include "UVector.h"
#include "UObject.h"
#include "UComponent.h"
#include <list>
#include <string>

using namespace std;

class UGameMap {
private:
	int** map;
	int row;
	int col;
	list<UActorObject *>* actorList = new list<UActorObject*>();
	list<UActorObject*>* removeList = new list<UActorObject*>();
public:
	UGameMap(int _row, int _col);
	virtual bool checkMap(int x, int y);
	virtual void update();
	virtual void addActor(UActorObject* actor);
	virtual UActorObject * searchActor(int x, int y);
	virtual void removeActor(UActorObject* actor);
	virtual bool isEmpty(int x, int y);
	virtual void render();

	virtual void destroy();

};