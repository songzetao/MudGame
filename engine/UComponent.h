#pragma once
#include "UActorObject.h"
class UActorObject;
class UComponent {
private:
	UActorObject * owner = nullptr;
public:
	virtual string getClass() {
		return "UComponent";
	};

	virtual void setOwner(UActorObject* _owner);
	virtual void init();
	virtual UActorObject* getOwner();

	virtual void update();
	virtual void destroy();
};