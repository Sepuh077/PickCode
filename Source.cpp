#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include "weapon.h"
#include <time.h>
#include <Windows.h>
#include "hero.h"
using namespace std;
int main() {
	hero player;
	srand(time(NULL));
x:
	player.print_time("Choose your hero:");
	cout << endl;
	player.print_time("1. Archer:");
	cout << endl;
	player.print_time("2. Cardigan:");
	cout << endl;
	player.print_time("3. Mage:");
	cout << endl;
	player.print_time("For random hero click 'R'");
	cout << endl;
	char s;
	cin>>s;
	if (s < '1' || s>'3') {
		int x = rand();
		s = x % 3 + '1';
		for (int i = 1; i <= 3; i++) {
			cout << "." << " ";
			Sleep(500);
		}
		cout << endl;
	}
	player.input(s);
	string My_Hero = player.input(s);
	player.print_time("Your hero will be ");
	player.print_name();
	cout << endl;
	int weapons = player.weapon_count(My_Hero);
	player.print_time("Choose your weapon:");
	cout << endl;
	player.print_weapons(My_Hero);
	player.print_time("For random weapon click 'R'");
	cout << endl;
	cin >> s;
	if (s > weapons + '0' || s < '1') {
		int x = rand();
		s = x % weapons + '1';
		for (int i = 1; i <= 3; i++) {
			cout << "." << " ";
			Sleep(500);
		}
		cout << endl;
	}
	player.print_time("Your weapon will be: ");
	player.weapon_print(s, My_Hero);
	cout << endl;
	player.print_time("Press 'I' to see information about your hero");
	cout << endl;
	player.print_time("Press 'P' to see parametrs");
	cout << endl;
	player.print_time("Press 'R' to change hero");
	cout << endl;
	player.print_time("Press 'Q' to quit");
	cout << endl;
	bool tr = 0;
	while (1) {
		char k;
		cin>>k;
		if (k == 'i' || k=='I') {
			player.info();
		}
		if (k == 'q' || k=='Q')
			break;
		if (k == 'p' || k == 'P') {
			player.print_time("Letter Speed: ");
			cout << player.t << endl;
			player.print_time("If you want to change Letter Speed press 'C'");
			cout << endl;
			tr = 1;
		}
		if (tr == 1 && (k == 'C' || k == 'c')) {
			player.print_time("Input your time in MS");
			cout << endl;
			int h;
			cin >> h;
			player.t = h;
		}
		if (k == 'r' || k == 'R')
			goto x;
	}
	return 0;
}