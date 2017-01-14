#ifndef MAPCLASSES_H
#define MAPCLASSES_H

#include "MainClasses.h"

class Asset: public Object
{
public:
	void Interaction(Asset& Interactor);
private:
};

class Decoration: public Object //Грaфический класс статических объектов
{
public:
	Object& GetPath(); //Получить текстуру пути
	Object& Interaction(Asset& Interactor);
};

class Mine: public Decoration //Класс-шахта, наследник декорации
{
public:
	void Capture(Asset& capturer);
};

class Town: public Decoration //Класс-город, наследник декорации, тк статический объект карты
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