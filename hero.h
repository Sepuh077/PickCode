#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include "weapon.h"
#include <iomanip>
using namespace std;
class hero
{
private:
	int hp;
	string name;
	weapon My_weapon;
	string Mage_weapon_1 = "Enigma", Mage_weapon_2 = "Spark", Mage_weapon_3 = "Thorn";
	string Cardigan_weapon_1="Grimfrost", Cardigan_weapon_2="Bane";
	string Archer_weapon_1 = "Heartbreaker", Archer_weapon_2 = "Stark";
public:
	int t=50;
	hero()
		:hp(1000)
	{}
	string input(char s) {
		if(s=='1')
			name = "Archer";
		if (s == '2')
			name = "Cardigan";
		if (s == '3')
			name = "Mage";
		return name;
	}
	int weapon_count(string name) {
		if (name == "Mage") {
			return 3;
		}
		else if (name == "Cardigan") {
			return 2;
		}
		else if (name == "Archer") {
			return 2;
		}
		else {
			return 0;
		}
	}
	void print_weapons(string name) {
		if (name == "Mage") {
			print_time("1. ");
			print_time(Mage_weapon_1);
			cout << endl;
			print_time("2. ");
			print_time(Mage_weapon_2);
			cout << endl;
			print_time("3. ");
			print_time(Mage_weapon_3);
			cout << endl;
		}
		if (name == "Cardigan") {
			print_time("1. ");
			print_time(Cardigan_weapon_1);
			cout << endl;
			print_time("2. ");
			print_time(Cardigan_weapon_2);
			cout << endl;
		}
		if (name == "Archer") {
			print_time("1. ");
			print_time(Archer_weapon_1);
			cout << endl;
			print_time("2. ");
			print_time(Archer_weapon_2);
			cout << endl;
		}
	}
	void weapon_print(char s,string name) {
		if (name == "Mage") {
			if (s == '1') {
				print_time(Mage_weapon_1);
				My_weapon.name = Mage_weapon_1;
				My_weapon.damage = 200;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.1;
				My_weapon.hp = 500;
				hp += 500;
			}
			if (s == '2') {
				print_time(Mage_weapon_2);
				My_weapon.name = Mage_weapon_2;
				My_weapon.damage = 190;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.2;
				My_weapon.hp = 600;
				hp += 600;
			}
			if (s == '3') {
				print_time(Mage_weapon_3);
				My_weapon.name = Mage_weapon_3;
				My_weapon.damage = 400;
				My_weapon.atack_speed = My_weapon.base_atack_speed + 0.3;
				My_weapon.hp = 350;
				hp += 350;
			}
		}
		if (name == "Cardigan") {
			if (s == '1') {
				print_time(Cardigan_weapon_1);
				My_weapon.name = Cardigan_weapon_1;
				My_weapon.damage = 100;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.55;
				My_weapon.hp = 950;
				hp += 950;
			}
			if (s == '2') {
				print_time(Cardigan_weapon_2);
				My_weapon.name = Cardigan_weapon_2;
				My_weapon.damage = 50;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.35;
				My_weapon.hp = 1500;
				hp += 1500;
			}
		}
		if (name == "Archer") {
			if (s == '1') {
				print_time(Archer_weapon_1);
				My_weapon.name = Archer_weapon_1;
				My_weapon.damage = 300;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.85;
				My_weapon.hp -= 400;
				hp -= 400;
			}
			if (s == '2') {
				print_time(Archer_weapon_2);
				My_weapon.name = Archer_weapon_1;
				My_weapon.damage = 350;
				My_weapon.atack_speed = My_weapon.base_atack_speed - 0.15;
				My_weapon.hp = 0;
				hp += 0;
			}
		}
	}
	void print_hp() {
		print_time(int_to_string(hp));
		cout << endl;
	}
	void print_name() {
		print_time(name);
	}
	void print_weaponname() {
		print_time(My_weapon.name);
	}
	void print_weapondamage() {
		print_time(int_to_string(My_weapon.damage));
		cout << endl;
	}
	void print_atack_speed() {
		cout << setprecision(2) << My_weapon.atack_speed;
		cout << " s" << endl;
	}
	void info() {
		print_time("My HP is ");
		print_hp();
		print_time("My hero name is ");
		print_name();
		cout << endl;
		print_time("My weapon is ");
		print_weaponname();
		cout << endl;
		print_time("Damage: ");
		print_weapondamage();
		print_time("Atack Speed: ");
		print_atack_speed();
	}
	string int_to_string(int a) {
		string s = "", b = "";
		while (a) {
			s.push_back(a % 10 + '0');
			a /= 10;
		}
		int k = s.length();
		for (int i = k - 1; i >= 0; i--) {
			b.push_back(s[i]);
		}
		return b;
	}
	void print_time(string a) {
		for (int i = 0; i < a.length(); ++i) {
			cout << a[i];
			Sleep(t);
		}
	}
};