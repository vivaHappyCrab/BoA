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
	void takesDamage(int amount, Unit& attacker, DAMAGE_TYPE DT);//��������� ����� ������
	int doesDamage();//������� �����, ������� ����� ������ ������
};
class Spell: public Object   
{		
public:
	Effect& Casting(Unit& caster, Object& target);//���������� ������ � �������
private:
	Object& onBeingCasted(ID id, Object& params);
};
class Effect: public Object //��������� ���� �����(�������) � �������� ����������� ����������   
{
public:
	void StartActions(Object& effected);//������������� �������(���� ����� � ����������)
	void PeriodicActions(Object& effected);//��������� ������������� ��������(�� 1)
	void EndActions(Object& effected);//����� �������, ��������������� ��� ������������(����� ���� ������� ����� ����� ������)
private:
	Object& onBeingStarted(ID id, Object& params);
	Object& onTick(ID id, Object& params);
	Object& onBeingFinished(ID id, Object& params);
};

class Obstacle: public Object //������������ ������� �� ���� ���
{
	//�����? ���������� ����������� � ������������ ����������� ����� �������� Cell
};

class Cell: public Object //������ � ���� ����������� ������ � ������ �� ������� � ���� ������
							//�� ���� �������� ������� 2�������� �������, ����������� � ������ Battle
{
	
};

class Battle: public Object //���������� �������� ���
{
public:
	void CreateBattleField();//�������� ������������������ ���� ���, ������������� ����� ���������� ���
	Unit& NextTurn(); //�������� ���� ���������� �����, ����� ����� ��������
	void Move(Cell& destination); //����� ���������, ������������ �����
	void Hold();//����� ���������, ����������� ����� � ����� �������
	void Defence();//����� ���������, ������� ���������� ����� ����������
	void CastSpell(Spell& spell);//����� ���������, �������������� ���� ������ - ����� ����������� ���� �������
	void Attack(Unit& attacked);//����� ���������, �������������� ����� �����
private:
};

class SpellBook: public Asset //����� ����������, ����� ������������ �����������
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