#include <iostream>
using namespace std;

class Enemy
{
	string name;
	int hp;
	int strenght;
	static const int maxHealth = 100;
public:
	Enemy() :name("no name"), hp(maxHealth), strenght(0) {}
	Enemy(string name, int hp, int strenght) :name(name), hp(hp), strenght(strenght) {}
	void Print()const
	{
		cout << "Name: " << name << endl;
		cout << "HP: " << hp << endl;
		cout << "strenght: " << strenght << endl;
	}
	void DecreaseHealth(int value)
	{
		hp -= value;
		if (hp < 0) hp = 0;
	}
	bool IsAlive()const
	{
		return hp > 0;
	}
	void IncreaseHealth(int value)
	{
		hp += value;
		if (hp > maxHealth) hp = maxHealth;
	}
	float Attack()const
	{
		return strenght * 0.5f;
	}
	void Fight(Enemy& other)
	{
		cout << "Getting damage" << "%" << endl;
		float damage = Attack();
		other.DecreaseHealth(damage);
		cout << "Health after attack: " << other.hp << endl;
	}
};

class Dragon : public Enemy
{
	float armor;
public:
	Dragon() :armor(0), Enemy() {}
	Dragon(string n, float s, float a) :armor(a), Enemy(n, s) {}
	void Fight(int damage)
	{
		Enemy::Fight(damage - armor);
	}
	void Print()const
	{
		cout << "--------------------Dragon----------------" << endl;
		Enemy::Print();
		cout << "Armor " << armor << endl;
	}

};
class Wizard : public Enemy
{
	float turbo_attack;
public:
	Wizard() :turbo_attack(0), Enemy() {}
	Wizard(string n, float s, float t) :turbo_attack(t), Enemy(n, s) {}
	float AttackWithTurboPower()
	{
		cout << "Attacking with turbo power " << turbo_attack << endl;
		return turbo_attack + strenght;
	}
	void Print()const
	{
		cout << "--------------------Wizard----------------" << endl;
		Enemy::Print();
		cout << "Turbo attack power " << turbo_attack << endl;
	}
};



int main()
{

}

