#ifndef MAINCLASSES_H
#define MAINCLASSES_H

#include "Table.h"

class Object;
class Game;
class Asset;
class Point;
class Map;
class Mine;
class Decoration;
class Town;
class Hero;
class Unit;
class Spell;
class Effect;
class Obstacle;
class Cell;
class Battle;
class SpellBook;
//------------------
class ObjectManager;
class Factory;
//------------------

class Object //�������������� ����� (��� ������� ������ � ������)
{
private:
	ID Id;
	Prop attributes;
public:
	friend ObjectManager;
	friend Factory;
	ID getId()const{return Id;}
	Value& operator [] (const string& key){return attributes[key];}
};

class ObjectManager //�����, �������� � ���� ��� ������� �������, � �������������� � ��� ������
{
private:
	map<ID,Object*> obj;
	ID nextid = ID(0);
public:
	Object& getNewObject(OBJECT_TYPE ot);
	Object& getObjectById(ID id);
	bool ObjectManager::destroyObjectById(ID id);
};

class Game:public Object{
private:
public:
};

#endif