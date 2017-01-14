#include "MainClasses.h"

	const Value operator +(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1+v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2+v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1+v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2+v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3+v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_INT))
			return(ID(v1.vl4+unsigned(v2.vl1)));
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_ID))
			return(ID(unsigned(v1.vl1)+v2.vl4));
		throw "illegal operation";
	}
	const Value operator -(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1-v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2-v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1-v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2-v2.vl2);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(int(v1.vl4-v2.vl1));
		throw "illegal operation";
	}

	const Value operator *(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1*v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2*v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1*v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2*v2.vl2);
		throw "illegal operation";
	}
	const Value operator /(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1/v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2/v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1/v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2/v2.vl2);
		throw "illegal operation";
	}
	const Value operator %(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1%v2.vl1);
		throw "illegal operation";
	}
//=======================================================================================
	bool operator ==(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1==v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2==v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1==v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2==v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3==v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4==v2.vl4);
		return false;
	}
	bool operator !=(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1!=v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2!=v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1!=v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2!=v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3!=v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4!=v2.vl4);
		return true;
	}
	bool operator >(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1>v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2>v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1>v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2>v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3>v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4>v2.vl4);
		throw "illegal operation";
	}
	bool operator <(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1<v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2<v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1<v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2<v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3<v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4<v2.vl4);
		throw "illegal operation";
	}
	bool operator >=(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1>=v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2>=v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1>=v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2>=v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3>=v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4>=v2.vl4);
		throw "illegal operation";
	}
	bool operator <=(const Value& v1, const Value& v2)
	{
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_INT))
			return(v1.vl1<=v2.vl1);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_INT))
			return(v1.vl2<=v2.vl1);
		if((v1.getType()==TYPE_INT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl1<=v2.vl2);
		if((v1.getType()==TYPE_FLOAT)&&(v2.getType()==TYPE_FLOAT))
			return(v1.vl2<=v2.vl2);
		if((v1.getType()==TYPE_STRING)&&(v2.getType()==TYPE_STRING))
			return(v1.vl3<=v2.vl3);
		if((v1.getType()==TYPE_ID)&&(v2.getType()==TYPE_ID))
			return(v1.vl4<=v2.vl4);
		throw "illegal operation";
	}
//======================================================================
	//Value& Value::operator +=(const Value& v)
	//{
	//}
	//Value& Value::operator -=(const Value& v)
	//{
	//}
//======================================================================
	ostream& operator <<(ostream& os,const Value& v)
	{
		if(v.getType()==TYPE_INT)
			os<<v.vl1;
		if(v.getType()==TYPE_FLOAT)
			os<<v.vl2;
		if(v.getType()==TYPE_STRING)
			os<<v.vl3;
		if(v.getType()==TYPE_ID)
			os<<v.vl4;
		return os;
	}