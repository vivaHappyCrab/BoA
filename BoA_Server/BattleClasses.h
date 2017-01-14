#ifndef BATTLECLASSES_H
#define BATTLECLASSES_H

#include "MainClasses.h"
#include "MapClasses.h"

class Unit: public Object
{
private:
	Object& onDamageTake(FCode id, Object& params);
	Object& onDamageDo(FCode id, Object& params);
public:
	void takesDamage(int amount, Unit& attacker, DAMAGE_TYPE DT);//получение урона юнитом
	int doesDamage();//рассчёт урона, который будет нанесён юнитом
};
class Spell: public Object   
{		
public:
	Effect& Casting(Unit& caster, Object& target);//применение спелла к объекту
private:
	Object& onBeingCasted(ID id, Object& params);
};
class Effect: public Object //Выполняет роль баффа(дебаффа) и носитель графической информации   
{
public:
	void StartActions(Object& effected);//инициализация эффекта(этим может и закончится)
	void PeriodicActions(Object& effected);//выполнеие периодических действий(мб 1)
	void EndActions(Object& effected);//конец эффекта, заканчивающийся его уничтожением(может быть запущен сразу после старта)
private:
	Object& onBeingStarted(ID id, Object& params);
	Object& onTick(ID id, Object& params);
	Object& onBeingFinished(ID id, Object& params);
};

class Obstacle: public Object //Непроходимый объекта на поле боя
{
	//Зачем? Функционал прохдимости и графического отображения можно добавить Cell
};

class Cell: public Object //Хранит в себе графические данные и ссылки на объекты в этой ячейке
							//По сути является ячейкой 2хмерного массива, записанного в классе Battle
{
	
};

class Battle: public Object //Обработчик процесса боя
{
public:
	void CreateBattleField();//создание последовательности хода боя, инициализация книги заклинаний итп
	Unit& NextTurn(); //передача хода следующему юниту, вызов тиков эффектов
	void Move(Cell& destination); //вызов процедуры, перемещающей юнита
	void Hold();//вызов процедуры, пермещающей юнита в конец очереди
	void Defence();//вызов процедуры, которая заставляет юнита защищаться
	void CastSpell(Spell& spell);//вызов процедуры, обрабатывающей каст спелла - здесь формируется стек спеллов
	void Attack(Unit& attacked);//вызов процедуры, обрабатывающей атаку юнита
private:
};

class SpellBook: public Asset //Набор заклинаний, имеет ограниченную вместимость
{
private:
public:
};
class Hero: public Asset
{
public:
	int doesDamage();
};

#endif