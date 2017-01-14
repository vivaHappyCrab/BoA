#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

typedef unsigned ID;
typedef unsigned long FCode;
typedef long Str;
const ID nullID =ID(0);

enum TYPE
{
	TYPE_INT = 0,
	TYPE_FLOAT = 1,
	TYPE_STRING = 2,
	TYPE_ID = 3
};

enum DAMAGE_TYPE{
	CLEAR,
	PHYSICAL,
	MAGICAL,
};

enum OBJECT_TYPE{
	OBJECT,
	GAME,//undeclarable
	BATTLE,//undeclarable
	MAP, //undeclarable
	HERO,
	TOWN,
	ASSET,
	RESOURCE,
	SPELLBOOK,
	SPELL,
	EFFECT,
	UPGRADE,
	UNIT,
	CELL,
	MINE,
	SKILL,
	ARTIFACT,
	BUILDING,
	MARKET,//undeclarable
	DECORATION,
	OBSTACLE,
	POINT
};

enum ORDER{
	NULL_ORDER,
	BMOVE,
	ATTACK,
	CAST,
	HOLD,
	DEFENCE,
	MMOVE,
	INTERACT,
	HIRE,
	BUILD,
	BUY,
	SELL
};

enum ASSET_TYPE{
	AT_HERO, 
	AT_UNITS,
	AT_RESOURSE,
	AT_ARTIFACT,
	AT_EVENT
};

/*template <typename T>class Comp{
public:
	bool operator !=(const T &t){return !(*(static_cast<const T*>(this))==t);}
};*/

class Value //класс-значение(для удобной работы с собственным языком)
{
private:
	TYPE type;
	int vl1;
	double vl2;
	string vl3;
	ID vl4;
public:
	TYPE getType()const{return type;}
	Value(int value){type=TYPE_INT; vl1=value;}
	Value(double value){type=TYPE_FLOAT; vl2=value;}
	Value(const string& value){type=TYPE_STRING; vl3=value;}
	Value(const char* value) { type = TYPE_STRING; vl3 = (string)value; }
	Value(ID value){type=TYPE_ID; vl4=value;}
	Value(){type=TYPE_INT; vl1=0;}
	int& getInt(){return vl1;}
	double& getFloat(){return vl2;}
	string& getString(){return vl3;}
	ID& getId(){return vl4;}
	friend const Value operator +(const Value& v1, const Value& v2);//переопределение стандартных операций для удобной работы напрямую с Value
	friend const Value operator -(const Value& v1, const Value& v2);
	friend const Value operator *(const Value& v1, const Value& v2);
	friend const Value operator /(const Value& v1, const Value& v2);
	friend const Value operator %(const Value& v1, const Value& v2);
	friend bool operator ==(const Value& v1, const Value& v2);
	friend bool operator !=(const Value& v1, const Value& v2);
	friend bool operator >(const Value& v1, const Value& v2);
	friend bool operator <(const Value& v1, const Value& v2);
	friend bool operator >=(const Value& v1, const Value& v2);
	friend bool operator <=(const Value& v1, const Value& v2);
	Value& operator +=(const Value& v);
	Value& operator -=(const Value& v);
	friend ostream& operator <<(ostream& os,const Value& v);
};

//union Val{
//	int Int;
//	double Float;
//	Str String;
//	ID Id;
//	FCode Function;
//	Value(int val=0):Int(val){}
//	Value(double val):Float(val){}
//	Value(Str val):String(val){}
//	Value(ID val):Id(val){}
//	Value(FCode val):Function(val){}
//};



typedef map<string,Value> Prop;
typedef Prop::iterator Piter;

string i2s(int n);
string i2s(unsigned n);
int s2i(string s);

#endif