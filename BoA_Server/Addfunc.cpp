#include "Table.h"

string i2s(int n){
	string s;
	int x=0;
	if (n<0){s+='-';x=1;}
	n=abs(n);
	do{
	char c=n%10+'0';
	s.insert(x,string(1,c));
	n/=10;
	}while(n>0);
	return s;
}

string i2s(unsigned n){
	string s;
	do{
	char c=n%10+'0';
	s.insert(0,string(1,c));
	n/=10;
	}while(n>0);
return s;
}

int s2i(string s){
	int n=0;
	unsigned i=0;
	bool q;
	if(s[0]=='-'){q=true;i=1;}
	for(;i<s.length();++i)
		if(q)n=10*n-(s[i]-'0');
		else n=10*n+(s[i]-'0');
	return n;
}

ID s2id(string s){
	ID n=0;
	for(unsigned i=0;i<s.length();++i)
		 n=10*n+(s[i]-'0');
	return n;
}