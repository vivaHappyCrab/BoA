#include "MDT.h"

void MDO::AddProp(const string& field,Value& val){
	values[field]=val;
}

Value& MDO::GetNextVal(){
	return tf->second;
}

const string& MDO::GetNextF(){
	const string& v=(tf)->first;
	if(tf==values.end())
		tf=values.begin();
	else tf++;
	return v;
}

Value& MDO::GetValByName(const string& name){
	return values[name];
}

Value& MDT::GetNextValue(int rawcode){
	return objects[rawcode].GetNextVal();
}

const string& MDT::GetNextField(int rawcode){
	return objects[rawcode].GetNextF();
}

Value& MDT::GetValByName(int rawcode,const string& name){
	return objects[rawcode].GetValByName(name);
}

void MDT::Load(const string& filename){
	ifstream dtb;
	dtb.open(filename);
	string field;
	int type;
	while(field!="/"){
		MDO ob;
		field.clear();
		while(field!="\\"){
			dtb>>field;
			if((field=="/")||(field=="\\"))
				break;
			dtb>>type;
			switch(type){
			case 0:{int val;dtb>>val;ob.AddProp(field,Value(val));break;}
			case 1:{float val;dtb>>val;ob.AddProp(field,Value(val));break;}
			case 2:{string val;dtb>>val;ob.AddProp(field,Value(val));break;}
			case 3:{ID val;dtb>>val;ob.AddProp(field,Value(val));break;}
			}
		}
		int t=ob.GetValByName("rawcode").getInt();
		objects[t]=ob;
		objects[t].tf=objects[t].values.begin();
	}
	dtb.close();
}