#pragma once
#include<iostream>
#include"../thing/Thing.h"
#include"../thing/Heal.h"
#include"../thing/Weapon.h"
#include"../engine/UComponent.h"
#include"../UWorld.h"
using namespace std;

class Bag :public UComponent {
private:
	Heal* heal[10];
	Weapon* weapon[10];
	int heal_number;
	int weapon_number;
	int all_number;
public:
	Bag() {
		heal_number = 0;
		weapon_number = 0;
		all_number = 0;

	}
	static string StaticClass() {
		return "Bag";
	};
	string getClass() {
		return "Bag";
	};
	void destroy() {
		world->EventDispatcher->unBindEvent("2", this, &Bag::diplay);
	}
	void init() {
		world->EventDispatcher->bindEvent("2", this, &Bag::diplay);
	}
	void update() {
		world->MessageManager->Tip.appendLine("输入2 进入背包");
	}
	void addThing(Thing *thing) {
		if((thing->type == EThing::Heal))
			addHeal((Heal*)thing);
		if ((thing->type == EThing::Weapon))
			addWeapon((Weapon*)thing);
	}
	void addHeal(Heal *thing) {
		if (heal_number > 10)
			world->MessageManager->Error.appendLine("药品已装满，不可再拾取！");
		else {
			heal[heal_number++] = thing;
			all_number++;
			world->MessageManager->Info.appendLine("已拾取药品 " + heal[heal_number - 1]->getName());
		}
	}

	void addWeapon(Weapon* thing) {
		if (weapon_number > 10)
			world->MessageManager->Error.appendLine("武器已装满，不可再拾取！");
		else {
			weapon[weapon_number++] = thing;
			all_number++;
			world->MessageManager->Info.appendLine("已拾取武器 " + weapon[weapon_number - 1]->getName());
		}
	}
	void diplay(string key , string cmd) {
		cout << endl << endl;
		if (heal_number == 0)
			world->MessageManager->Info.appendLine("背包中药品为空! ");
		else {
			world->MessageManager->Info.appendLine("背包中药品有: ");
			for (int i = 0; i < heal_number; i++) {
				cout << "药品名字为：" << heal[i]->getName() << "		其回血值为: " << heal[i]->getBloodValue() << endl;
				world->MessageManager->Info.appendLine("药品名字为: " + heal[i]->getName() + "		其回血值为: " + to_string(heal[i]->getBloodValue()));
			}
		}

		if (weapon_number == 0)
			world->MessageManager->Info.appendLine("背包中武器为空! ");
		else {
			world->MessageManager->Info.appendLine("背包中武器有: ");
			for (int i = 0; i < weapon_number; i++) {
				world->MessageManager->Info.appendLine("武器名字为: " + weapon[i]->getName() + "		其攻击值为: " + to_string(weapon[i]->getAttackValue()) + "		其防御值为：" + to_string(weapon[i]->getDefenceValue()));
			}

			cout << endl << endl;
		}

	}
};
