#include "Factory.h"

Game& Factory::InitGame(int maxplayers, int* clan, int* race, const string* pnames,const string& mapName){
	Object& o=Manager.getNewObject(GAME);
	game = static_cast<Game&>(o);
	Object& o1 = Manager.getNewObject(MAP);
	map = static_cast<Map&>(o1);
	Object& o2 = Manager.getNewObject(BATTLE);
	battle = static_cast<Battle&>(o2);
	game["mapName"] = mapName;
	game["maxplayers"] = maxplayers;
	for (int i = 0; i < maxplayers; ++i){
		game["pname-" + i2s(i)] = pnames[i];
		game["prace-" + i2s(i)] = race[i];
		game["pclan-" + i2s(i)] = clan[i];
	}
	game["tplayer"] = int(1);
	DataTable.Load(mapName);
	return game;
}

Unit& Factory::CreateUnit(int rawcode, int owner, int amount){
	Object& o=Manager.getNewObject(UNIT);
	Unit& u=static_cast<Unit&>(o);
	int s=DataTable.sizeO(rawcode);
	for(int i=0;i<s;++i)
		u[DataTable.GetNextField(rawcode)]=DataTable.GetNextValue(rawcode);
	u["owner"]=owner;
	u["amount"]=amount;
	return u;
}

Spell& Factory::CreateSpell(int rawcode,Hero& owner){
	Object& o=Manager.getNewObject(SPELL);
	Spell& sp=static_cast<Spell&>(o);
	int s=DataTable.sizeO(rawcode);
	for(int i=0;i<s;++i)
		sp[DataTable.GetNextField(rawcode)]=DataTable.GetNextValue(rawcode);
	int& x=owner["spell-size"].getInt();
	owner["spell-"+i2s(x)].getId()=sp.getId();
	x++;
	return sp;
}

void Factory::CreateSpellinTown(int rawcode,Town& owner){
	int& x=owner["spell-size"].getInt();
	owner["spell-"+i2s(x)]=rawcode;
	x++;	
}

Hero& Factory::CreateHeroAtPoint(int rawcode,int owner,Point& point)
{
	Object& o=Manager.getNewObject(HERO);
	Hero& u=static_cast<Hero&>(o);
	int s=DataTable.sizeO(rawcode);
	for(int i=0;i<s;++i)
		u[DataTable.GetNextField(rawcode)]=DataTable.GetNextValue(rawcode);
	Object& as=Manager.getNewObject(ASSET);
	u["owner"]=owner;
	as["pos"]=point.getId();
	as["hero"]=u.getId();
	point["asset"]=u.getId();
	return u;
}

void Factory::CreateAssetOnMap(int rawcode)
{
}

Town& Factory::CreateTown(int race, int owner)
{
	Object& obj = Manager.getNewObject(TOWN);
	obj["race"] = race;
	obj["owner"] = owner;
	return  static_cast<Town&>(obj);
}

Asset& Factory::AddUnit(Asset& a, Unit& u)
{
	int& x = a["troop-size"].getInt();
	a["troop-" + i2s(x)] = u.getId();
	x++;
	return a;
}