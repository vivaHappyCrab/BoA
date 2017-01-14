#include "MainClasses.h"
#include "MDT.h"
#include "Factory.h"
using namespace std;

int main(){
	ObjectManager c;
	Object t=c.getNewObject(OBJECT);
	cout<<t.getId()<<endl;
	c.getNewObject(OBJECT);
	c.getNewObject(OBJECT);
	c.getNewObject(OBJECT);
	c.getNewObject(UNIT);
	c.getNewObject(SPELL);
	t=c.getObjectById(3);
	cout<<t.getId()<<endl;
	try{t=c.getObjectById(22);
		cout<<t.getId()<<endl;}
	catch(const char* e){cout<<e<<endl;}
	Value v1(12);
	Value v2(7.5);
	Value v3(14);
	Value v4;
	Value v5;
	Value v6(nullID);
	v4=v1+v2;
	v5=v1+v3;
	cout<<v4<<' '<<v5<<endl;
	v6=v6+2;
	t=c.getObjectById(v6.getId());
	cout<<t.getId()<<endl;
	MDT Table;
	//Table.Load("odata.txt");
	Factory f(Table, c);
	int clan[] = { 1, 2 };
	string names[] = { "QQ", "WW" };
	f.InitGame(2, clan, clan, names,"odata.txt");
	Unit un=f.CreateUnit(1,0,2);
	cout<<c.getObjectById(6)["name"]<<endl;
	cout<<un["rawcode"]<<endl;
	Hero h;
	f.CreateSpell(3,h);
	cout<<h["spell-size"]<<endl;
	cout << sizeof(string) << endl;
	f.AddUnit(h, un);
	//ID start=0;
	//for (int x = 0;x < 10000;++x) {
	//	auto ob=c.getNewObject(OBJECT);
	//	if (!x)start = ob.getId();
	//	ob["1"] = 1;
	//	ob["2"] = 2.2;
	//	ob["3"] = "3";
	//	//c.destroyObjectById(ob.getId());
	//	this_thread::sleep_for(1ms);
	//}
	//bool q = true;
	//while (q) {
	//	q=c.destroyObjectById(start++);
	//}
	system("pause");
	return 0;
}