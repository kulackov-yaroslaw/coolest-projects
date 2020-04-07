//03.11.2014
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h> 
#include <stdio.h>
using namespace std;
int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
	setlocale(0, "rus");
	srand(time(0));
	string b[1000],t="p";
	int a = 1, c[1000], c1 = 2, n, k = 0,ii=0,oo=0;
	while (ii % 2 == 0 || oo % 2 == 0 || ii < 5 || oo < 5 || (ii + 2)*(oo + 2) >= 1000 || oo>70){
		cout << "Ââåäèòå íå÷åòíóþ âûñîòó,øèðåíó, ðåêîìåíäîâàíî 15 27." << endl << "Ñàìàÿ æåñòü 23 37: ";
		cin >> ii >> oo;
		if (ii < 5) cout << "Ìàëåíèêàÿ âûñîòà!!!" << endl;
		if (oo < 5) cout << "Ìàëåíèêàÿ øèðèíà!!!" << endl;
		if ((ii + 2)*(oo + 2) >= 1000) cout << "Ñëèøêîì áîëüøîé ëàáèðèíò" << endl;
		if (oo>70)cout << "Ñëèøêîì áîëüøàÿ øèðèíà" << endl;
		if (oo % 2 == 0 || ii % 2 == 0)cout << "×èñëà äîëæíû áûòü íå÷åòíûìè!!" << endl;
	}
	ii += 2;
	oo += 2;
	for (int x = 0; x < ii*oo; x++){
		b[x] = " ";
		if (x < oo)b[x] = "#";
		if (x>ii*oo-oo-1)b[x] = "#";
		if (x % oo == 0)b[x] = "#";
		if (x % oo == oo-1)b[x] = "#";
	}
	while (a%2==1)
	   a = rand() % (oo-4)+oo*ii-oo+2;
	b[a] = ".";
	b[a-oo] = ".";
	a = 1;
	while (a%2==1)
	   a = rand() % (oo-4)+2;
	b[a] = ".";
	b[a+oo] = ".";
	a += oo*2;
	cout << 1;
	while (c1>1){
		int a1 = a;
		if (k < 15){
			c[c1] = a;
			c1++;
		}
		b[a] = ".";
		k = 0;
		while (a1 == a && k<15){
			n = rand() % 4 + 1;
			if (n == 1 && b[a + 2] ==" ")a++;
			if (n == 2 && b[a + oo*2] ==" ")a += oo;
			if (n == 3 && b[a - oo*2] ==" " )a -= oo;
			if (n == 4 && b[a - 2] ==" ")a--;
			k++;
		}
		if (k == 15){
			c[c1 - 1] = 0;
			c1 -= 2;
			a = c[c1];
			c1++;
		}
		if (a>0)
			b[a] = ".";
		if (a < 0)
			c1 = 0;
		if (k < 15){
			if (n == 1)a++;
			if (n == 2)a += oo;
			if (n == 3)a -= oo;
			if (n == 4)a--;
			b[a] = ".";
		}
	}
	b[oo*2] = "#";
	for (int x = 0; x < oo*ii; x++){
		if (b[x] == "#")b[x] = "";
		if (b[x] == " ")b[x] = "#";
		if (x>oo * 2||x<oo)
		     if (b[x] == ".")b[x] = " ";
	}
	system("CLS");
	for (int x = 0; x < oo*ii; x++){
		cout << b[x];
		if (x % oo == oo-1)
			cout << endl;
	}
	//Ïðîõîæäåíèå
	int h = 0,a1,a2;
	for (int x = 0; x < oo; x++){
		for (int y = 0; y < oo*ii; y++)
			b[y] = b[y + 1];
	}
	for (int x = 0; x < oo; x++)
	if (b[x] == ".")
		a = x;
	for (int x = oo*(ii - 3) - 1; x < oo*(ii - 2); x++)
	if (b[x] == " ")
		a1 = x;
	cout << "Õîòèòå ïðîéòè ëàáèðèíò ñàìîñòîÿòåëüíî? ";
	while (h == 0){
		cin >> t;
		if (t == "yes")h = 1;
		if (t == "no")h = 2;
	}
	if (h == 2){
		h = 0;
		int m[1000], j;
		c1 = 0;
		cout << endl << "Õîòèòå ñëåäèòü çà ïðîõîæäåíèåì ëàáèðèíòà? (yes/no) ";
		while (h == 0){
			cin >> t;
			if (t == "yes"){
				h = 1;
				j = 0;
			}
			if (t == "no"){
				h = 1;
				j = 1;
			}
		}
		k = j;
		for (int x = 0; x < 1000; x++)
			c[x] = 0;
		b[a] = ".";
		while (a != a1){
			if (k == 0){
				system("CLS");
				for (int x = 0; x < oo*ii; x++){
					cout << b[x];
					if (x % oo == oo - 1)
						cout << endl;
				}
				Sleep(150);
			}
			n = 0;
			a2 = a;
			while (a2 == a){
				n++;
				k = j;
				if (n == 1 && b[a - oo] == " "&&a - oo > 0 && m[a - oo] != 666)a -= oo;
				if (n == 2 && b[a - 1] == " "&&m[a - 1] != 666)a--;
				if (n == 3 && b[a + 1] == " "&&m[a + 1] != 666)a++;
				if (n == 4 && b[a + oo] == " "&&m[a + oo] != 666)a += oo;
				if (n == 5){
					k = 1;
					n = 0;
					c1--;
					b[a] = " ";
					m[a] = 666;
					c1--;
					a = c[c1];
					c1++;
				}
			}
			b[a] = ".";
			c[c1] = a;
			c1++;

		}
	}
	if (h == 1){
		
	}
	system("CLS");
	for (int x = 0; x < oo*ii; x++){
		if (b[x] == ".")
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
		cout << b[x];
		if (x % oo == oo - 1)
			cout << endl;
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
	}
	return 0;
}
