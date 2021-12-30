#include "UGameMap.h"
#include "Utility.h"
#include "Const.h"
#include <sstream>
#include <iostream>

UGameMap::UGameMap(int _row, int _col)
{
	row = _row;
	col = _col;

	map = new int* [_row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		memset(map[i], 0, sizeof(int) * col);
	}
}

bool UGameMap::checkMap(int x, int y)
{
	return x >= 0 && y >= 0 && x < row && y < col;
}

void UGameMap::addActor(UActorObject *actor) {
	actorList->push_back(actor);
	UVector pos = actor->getPos();
	if (!checkMap(pos.x, pos.y))
		return;
	map[pos.x][pos.y] = actor->getId();
};
void UGameMap::removeActor(UActorObject *actor) {
	removeList->push_back(actor);
};

void UGameMap::update()
{
	for (auto it = actorList->begin(); it != actorList->end(); it++) {
		(*it)->update();
	}
	for (auto it = removeList->begin(); it != removeList->end(); it++) {
		listRemove(actorList , *it);
		(*it)->destroy();
	}
	removeList->clear();
	
	for (int i = 0; i < row; i++) {
		memset(map[i], 0, sizeof(int) * col);
	}
	for (auto it = actorList->begin(); it != actorList->end(); it++) {
		UVector tempPos = (*it)->getPos();
		map[tempPos.x][tempPos.y] = (*it)->getId();
	}
}
void UGameMap::render()
{
	/*
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
	stringstream out , axis;
	out << parseName("", c_map_left_size);
	for (int i = 0; i < col; ++i) {
		axis << "y" << i;
		out << c_map_color_head << parseName(axis.str(), c_map_cell_size) << c_map_color_tail;
		axis.str("");
	}
	for (int i = 0; i < row; ++i) {
		out << "\n";
		axis << "x" << i;
		out << c_map_color_head <<  parseName(axis.str() , c_map_left_size) << c_map_color_tail;
		axis.str("");
		int * map_col = map[i];
		UActorObject * actor = nullptr;
		for (int j = 0; j < col; ++j) {
			if (map_col[j] != 0 && (actor = searchActor(i, j) , actor != nullptr && actor->getName() != "") ) {
				out << parseName( actor->getName() , c_map_cell_size);
			}
			else {
				out << parseName(c_map_cell, c_map_cell_size);
			};
		};
	};

	cout << out.str() << endl;
}

void UGameMap::destroy()
{
	for (auto it = actorList->begin(); it != actorList->end(); it++) {
		(*it)->destroy();
	}
}

bool UGameMap::isEmpty(int x, int y)
{
	if (checkMap(x, y))
		return map[x][y] == 0;
	return false;
}

UActorObject * UGameMap::searchActor(int x, int y)
{
	for (auto it = actorList->begin(); it != actorList->end(); it++) {
		UVector pos = (*it)->getPos();
		if (pos.x == x && pos.y == y) {
			return *it;
		}
	}
	return nullptr;
}
