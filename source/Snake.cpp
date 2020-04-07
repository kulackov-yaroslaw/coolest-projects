//12.09.2014
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h> 
#include <stdio.h>
using namespace  std;
int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
	setlocale(0, "rus");
	srand(time(0));
	string b[171], t = "d", n[4] = { "<", ">", "v", "^" };
	int p[170], z = 0, q = 0, e = -1, x[170], l = 1, o = 4, m = 3, f, j = 0, i, k1[170], k2[170], ll = 0;
	for (int a = 0; a < 170; a++)
		b[a] = ".";
	b[170] = "";
	for (int a = 0; a < 170; a++){
		p[a] = 170;
		x[a] = 1;
	}
	p[0] = 0;
	while (e < 170){
		i = 0;
		for (int a = 0; a < 170; a++)
			b[p[a]] = n[x[a]];
		if (z == 0){
			j = 0;
			while (j == 0){
				q = rand() % 170;
				j = 1;
				for (int a = 0; a < 170; a++){
					if (q == p[a])
						j = 0;
				}
			}
		}
		if (z == 0){
			z = 1;
			e++;
		}
		b[q] = "*";
		system("CLS");
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		cout << "        " << e << "/15" << endl;
		for (int a = 1; a < 170; a++){
			if (p[a] == p[0]){
				e = 171;
				b[p[0]] = "#";
			}
		}
		int s = 0;
		for (int a = 1; a < 11; a++){
			for (s; s < (a * 17); s++){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));
				if (s == p[0])
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
				for (int a = 1; a < 170; a++){
					if (s == p[a])
						SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
				}
				if (s == q)
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
				if ((s == p[0]) && (e == 171))
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));
				cout << b[s];
			}
			cout << endl;
		}
		b[p[0]] = ".";
		for (int a = 0; a < 170; a++){
			k1[a] = p[a];
			k2[a] = x[a];
		}
		o = 169;
		m = 168;
		for (f = 0; f<169; f++){
			if (e>m){
				b[p[o]] = ".";
				x[o] = x[m];
				p[o] = p[m];
			}
			o--;
			m--;
		}
		if ((e == 15) && (ll == 0)){
			system("CLS");
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
			while ((t != "o")){
				system("CLS");
				cout << "Âû ïðîøëè îñíîâíóþ ÷àñòü. Õîòèòå ïðîäîëæèòü?" << endl;
				cin >> t;
				if (t == "no"){
					t = "o";
					e = 172;
				}
				if (t == "yes"){
					t = "o";
					i = 1;
				}
			}
			ll = 1;
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		if ((e<170) && (i == 0))
			cin >> t;
		if ((t == "a") && (p[0] % 17 == 0))
			p[0] = p[0] + 17;
		if ((t == "s") && (p[0] > 152))
			p[0] = p[0] - 170;
		if ((t == "d") && ((p[0] - 16) % 17 == 0))
			p[0] = p[0] - 17;
		if ((t == "w") && (p[0]<17))
			p[0] = p[0] + 170;
		if (t == "a"){
			p[0]--;
			x[0] = 0;
		}
		if (t == "s"){
			p[0] = p[0] + 17;
			x[0] = 2;
		}
		if (t == "d"){
			p[0]++;
			x[0] = 1;
		}
		if (t == "w"){
			p[0] = p[0] - 17;
			x[0] = 3;
		}
		if (p[0] == q)
			z = 0;
		if ((t != "a") && (t != "s") && (t != "d") && (t != "w")){
			for (int a = 0; a < 170; a++){
				p[a] = k1[a];
				x[a] = k2[a];
			}
		}
	}
	if (e != 172)
		Sleep(1000);
	system("CLS");
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
	if (e == 172){
		cout << "Âû Âûèãðàëè";
		Sleep(1000);
	}
	system("CLS");
	return 0;
}
