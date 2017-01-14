#ifndef MAPCLASSES_H
#define MAPCLASSES_H

#include "MainClasses.h"

class Asset: public Object
{
public:
	void Interaction(Asset& Interactor);
private:
};

class Decoration: public Object //��a�������� ����� ����������� ��������
{
public:
	Object& GetPath(); //�������� �������� ����
	Object& Interaction(Asset& Interactor);
};

class Mine: public Decoration //�����-�����, ��������� ���������
{
public:
	void Capture(Asset& capturer);
};

class Town: public Decoration //�����-�����, ��������� ���������, �� ����������� ������ �����
{
public:
private:
};

class Point: public Object//==Map cell
{
};

class Map: public Object
{
};

#endif