#pragma once
#include "../Engine/UComponent.h"
#include "../thing/Thing.h"
class UMeshComponent : public UComponent {
private:
	Thing* mesh = nullptr;

public:
	void setMesh(Thing* thing);
	void setMesh(Thing* thing, int id);

	void update();
};