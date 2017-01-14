#ifndef MDT_H
#define MDT_H
#include "Table.h"

class MDO{ //Map's data of object()
public:
	Value& GetNextVal(); //this func incs counter
	const string& GetNextF();  //this func doesn't inc counter
	Value& GetValByName(const string& name);
	void AddProp(const string& field, Value& val);
	friend class MDT;
private:
	Piter tf; //Текущее поле
	Prop values;
};

class MDT{ //Map's data table (таблица о всех игровых объектах)
public:
	void Load(const string& filename);
	Value& GetNextValue(int rawcode);
	Value& GetValByName(int rawcode,const string& name);
	const string& GetNextField(int rawcode);
	int sizeO(int rawcode){return objects[rawcode].values.size();}
	friend class MDO;
private:
	map<int,MDO> objects; 
};

#endif