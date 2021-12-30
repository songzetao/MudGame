#pragma once
#include "System/UMessageManager.h"
#include "System/UIManager.h"
#include "System/UCsvManager.h"
#include "System/UTalkManager.h"
#include "Engine/UGameMap.h"
#include "Engine/UEventDispatcher.h"
#include "Role/role.h"

class UWorld {
public:
	UMessageManager* MessageManager = nullptr;
	UIManager* UIManager = nullptr;
	UTalkManager* TalkManager = nullptr;
	UCsvManager* CsvManager = nullptr;
	UEventDispatcher* EventDispatcher = nullptr;

	UGameMap* GameMap = nullptr;
	Role* Player = nullptr;

	string nextGameMap = "";
	string gameMapName = "";
	string gameTitle = "";
	string uiName = "";

	string levels = "levels : ";

	bool Running = false;
	bool preEnd = false;
	void render();
	void update();

	void run();
	void init();
	void iexit(string key ,string cmd);
	void ijump(string key, string cmd);
	void htrans(string key, string cmd);
	map<string, IDelegate*> SceneMap;
	template<class T>
	T* findComponent(UActorObject* actor)
	{
		auto cls = T::StaticClass();
		auto componentList = actor->componentList;
		for (auto it = componentList->begin(); it != componentList->end(); it++) {
			auto name = (*it)->getClass();
			if (name == cls)
				return dynamic_cast<T*>(*it);
		}
		return nullptr;
	}

	template<class T>
	void addScene(string key, T* _object, void (T::* _method)(string, string)) {
		auto it = SceneMap.find(key);
		if (it == SceneMap.end()) {
			IDelegate* handle = newDelegate(_object, _method);
			SceneMap.insert(pair<string, IDelegate*>(key, handle));
			levels += key + " , ";
		}
	}
	void addScene(string key, void (*_func)(string, string)) {
		auto it = SceneMap.find(key);
		if (it == SceneMap.end()) {
			IDelegate* handle = newDelegate(_func);
			SceneMap.insert(pair<string, IDelegate*>(key, handle));
			levels += key + " , ";
		}
	}
	void makeScene(string key) {
		auto it = SceneMap.find(key);
		if (it != SceneMap.end()) {
			(*it).second->invoke("", "");
		}
		else if(key != "main"){
			makeScene("main");
		}
	}

};

extern UWorld* world;