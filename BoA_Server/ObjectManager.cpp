#include "MapClasses.h"
#include "BattleClasses.h"
#include "MainClasses.h"

Object& ObjectManager::getNewObject(OBJECT_TYPE ot){
	Object* o;
	switch(ot){
	case UNIT: o=new Unit;
	case SPELL: o=new Spell;
	case EFFECT: o=new Effect;
	case OBSTACLE: o=new Obstacle;
	case ASSET: o=new Asset;
	case TOWN: o=new Town;
	case DECORATION: o=new Decoration;
	case MINE: o=new Mine;
	case BATTLE: o=new Battle;
	case MAP: o=new Map;
	case CELL: o=new Cell;
	case POINT: o=new Point;
	case GAME: o=new Game;
	default: o=new Object;
	}
	o->Id=nextid++;
	obj[o->Id] = o;
	return *o;
}

Object& ObjectManager::getObjectById(ID id){
	if(obj.find(id)==obj.end())
		throw "Invalid ID";
	return *obj[id];
}

bool ObjectManager::destroyObjectById(ID id) {
	if (obj.find(id) == obj.end())
		return false;
	delete obj[id];
	obj.erase(id);
	return true;
}