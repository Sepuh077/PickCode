#pragma once
#include <string>
using namespace std;
class weapon
{
public:
	weapon()
		:name("buddy"), damage(0), hp(0), atack_speed(1.70)
	{}
	string name;
	int damage;
	int hp;
	double atack_speed;
	const double base_atack_speed = 1.7;
};