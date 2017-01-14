 #ifndef FACTORY_H
#define FACTORY_H
#include "BattleClasses.h"
#include "MapClasses.h"
#include "MDT.h"


class Factory{
public:
	Factory(MDT& DT,ObjectManager& om):DataTable(DT),Manager(om){}
	Game & InitGame(int maxplayers, int* clan, int* race, const string* pnames, const string& mapName);
	Unit& CreateUnit(int rawcode, int owner, int amount);
	Spell& CreateSpell(int rawcode, Hero& owner);
	void CreateSpellinTown(int rawcode,Town& owner);
	Hero& CreateHeroAtPoint(int rawcode,int owner,Point& point);
	//Battle& StartBattle(Asset& attacker, Asset& defender);
	void AddDataTable(const MDT& DT){DataTable=DT;}
	void AddManager(const ObjectManager& om){Manager=om;}
	void CreateAssetOnMap(int rawcode);
	Town& CreateTown(int race, int owner);
	int Building(int rawcode, Town& town);
	Asset& AddUnit(Asset& as, Unit& u);
private:
	MDT& DataTable;
	ObjectManager& Manager;
	//temp
	Game game;
	Map map;
	Battle battle;
};

#endif