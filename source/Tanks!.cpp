//30.08.2015
#include<gl/glut.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<math.h>
#include "TextInGluth.h"
using namespace std;

double mainkoords[800][600][1], mousekoords[2];
const int count_of_wall = 12;
int winner = 0, main_timer = 0;
double xx = -265, yy = 209;

void circle(float x, float y, float r, bool color, double redc = 0, double greenc = 0, double bluec = 0);
void minadraw(double x, double y);
double antan(double x, double y);
bool F1_F2(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
void tank1_step();
void tank2_step();
void pula1_step(int);
void pula2_step(int);
void patronesstep(int);
void speed_new_patronstep();
void speedstep();
void healstep();
void life_kupolstep();
void atom_bombstep();
void teleportstep();
void minastep();

void draw_board();
void draw_bonus();
void draw_tanks_info();
void draw_right_panel();

class tanks {
public:
	double  speed, bonus_speed = 0, bonus_timespeed, lx = 0, ly = 0, an = 0, bonus_an = 0, verx, life, timer = 0, time_uppul = 5,bonus_timekupol;
	int motor = 1, motor_an = 1, count_pules = 2, teleport = 0, timeteleport, count_mines = 0;
	bool life_kupol = false;
	char life_text[9], timer_text[8], speed_text[13];
	struct vertex{
		double x, y, an, l;
	}koords[100];
}tank1, tank2;
class pules{
public:
	double x, y, an, speed = 0;
	int pula_is_on = 0;
	int seems = 0;
}pula1[6],pula2[6];
class mine{
public:
	double x, y;
	bool seems;
	int time;
	char time_text[2];
	struct minap{
		double x, y;
		bool seems;
		int time;
		char time_text[3];
	}mines[6];
}mina;
class passiveobject {
public:
	int verx;
	int seems = 2;
	struct vertex{
		double x, y;
	}koords[100];
}wall[10 * count_of_wall];
struct bonus{
	double x, y;
	bool seems = false;
	char time_text[2];
	int time;
}patrones[2], speed_new_patron, speed, heal, life_kupol, teleport;
struct bonus_atombomb{
	double x, y;
	bool seems = false;
	int boom = 0;
	char time_text[2];
	double power = 0;
	int time;
}atom_bomb;

void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	for (int x = 0; x < 6; x++){
		if (pula1[x].seems > 0){
			glColor3f(0.0, 0.0, 0.0);
			circle(pula1[x].x, pula1[x].y, 2.8, true);
		}
		if (pula2[x].seems > 0){
			glColor3f(0.0, 0.0, 0.0);
			circle(pula2[x].x, pula2[x].y, 2.8, true);
		}
	}
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	for (int x = 0; x < tank1.verx - 9; x++){
		glVertex2d(tank1.koords[x].x, tank1.koords[x].y);
		if (x > 8)
			glColor3f(0.0, 0.0, 0.6);
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	for (int x = 0; x < tank2.verx-9; x++){
		glVertex2d(tank2.koords[x].x, tank2.koords[x].y);
		if (x > 8)
			glColor3f(0.6, 0.0, 0.0);
	}
	glEnd();
	glBegin(GL_QUADS);
	for (int x = 0; x < 10 * count_of_wall; x++){
		if (wall[x].seems > 0){
			if (wall[x].seems == 2) glColor3f(0.0, 0.0, 0.0);
			if (wall[x].seems == 1) glColor3f(0.53, 0.53, 0.53);
			for (int y = 0; y < wall[x].verx; y++){
				glVertex2d(wall[x].koords[y].x, wall[x].koords[y].y);
			}
		}
	}
	glEnd();

	draw_bonus();

	//glBegin(GL_QUADS);
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_TRIANGLES);
	//glBegin(GL_POLYGON);
	//glVertex2f(x, y);
	//glEnd();
	//Add_text(b, -380, -260, 2);

	draw_tanks_info();

	if (winner > 0){
		glColor3f(0.6, 1.0, 0.6);
		glBegin(GL_POINTS);
		for (int x = -320; x < 340; x++){
			for (int y = -60; y < 60; y++){
				if ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
					glVertex2f(x,y);
			}
		}
		glEnd();
		if (winner == 1) Add_text("winner is player \\n      blue", -300, 0, 30, 4, "blue");
		if (winner == 2) Add_text("winner is player \\n      red", -300, 0, 30, 4, "red");
		if (winner == 3) Add_text("    winner is \\n      nobody", -300, 0, 30, 4, "yellow");
	}

	draw_right_panel();

	/*char mass[13] = "x    \\ny    ";
	mass[2] = 48 + abs(mousekoords[0] - 400) / 100;
	mass[3] = 48 + (int)abs((mousekoords[0] - 400 )/ 10) % 10;
	mass[4] = 48 + (int)abs(mousekoords[0] - 400) % 10;
	mass[9] = 48 + abs(600 - mousekoords[1] - 300) / 100;
	mass[10] = 48 + (int)abs((600 - mousekoords[1] - 300) / 10) % 10;
	mass[11] = 48 + (int)abs(600 - mousekoords[1] - 300) % 10;
	Add_text(mass, mousekoords[0]-400, (600 - mousekoords[1])-300+15, 13, 1);*/
	draw_board();

	glFlush();

}//0 0 0 1 5 1 5 0 0 3 0 4 5 4 5 3 1 1 1 3 4 3 4 1 4 1.75 4 2.25 6 2.25 6 1.75

void Timer(int){
	if (tank1.life > 0 && tank2.life > 0){
		tank1_step();
		tank2_step();

		patronesstep(0);
		patronesstep(1);
		speed_new_patronstep();
		speedstep();
		healstep();
		life_kupolstep();
		atom_bombstep();
		teleportstep();
		minastep();

		main_timer++;
	}
	if ((tank1.life <= 0 || tank2.life <= 0) && atom_bomb.boom > 0)atom_bombstep();
	for (int x = 0; x < 6; x++){
		pula1_step(x);
		pula2_step(x);
	}
	if (tank1.life <= 0 || tank2.life <= 0) {
		if (tank1.life > 0) winner = 1;
		if (tank2.life > 0) winner = 2;
		if (tank1.life <= 0 && tank2.life <= 0) winner = 3;
	}
	Draw();
	glutTimerFunc(50, Timer, 0);
}

void MousePressedOnse(int button, int state, int x, int y){
	if (state == GLUT_DOWN){
	}
}

void MousePressedAndMove(int x, int y){

}

void MouseDispressedAndMove(int x, int y){
	mousekoords[0] = x;
	mousekoords[1] = y;
}

void Keyisnotsymbol(int key, int x, int y){
	
	if (key == 100) tank2.motor_an++;
	if (key == 101) tank2.motor++;
	if (key == 102) tank2.motor_an--;
	if (key == 103) tank2.motor--;
	if (tank2.motor > 2) tank2.motor = 2;
	if (tank2.motor < 0) tank2.motor = 0;
	if (tank2.motor_an > 2) tank2.motor_an = 2;
	if (tank2.motor_an < 0) tank2.motor_an = 0;
}

void KeyIsSymbol(unsigned char key, int x, int y){
	if (key == 'a') tank1.motor_an++;
	if (key == 'w') tank1.motor++;
	if (key == 'd') tank1.motor_an--;
	if (key == 's') tank1.motor--;
	if (tank1.motor > 2) tank1.motor = 2;
	if (tank1.motor < 0) tank1.motor = 0;
	if (tank1.motor_an > 2) tank1.motor_an = 2;
	if (tank1.motor_an < 0) tank1.motor_an = 0;


	if (key == 'q' && tank1.timer == tank1.time_uppul && winner == 0){
		int number_pula1 = 0;
		while (pula1[number_pula1].pula_is_on > 0 && number_pula1 <= 6){
			number_pula1++;
		}
		if (number_pula1 < 6){
			pula1[number_pula1].pula_is_on = 1;
			tank1.timer = 0;
			tank1.count_pules--;
		}
	}
	if (key == ' ' && tank2.timer == tank2.time_uppul && winner == 0){
		int number_pula2 = 0;
		while (pula2[number_pula2].pula_is_on > 0 && number_pula2 <= 6){
			number_pula2++;
		}
		if (number_pula2 < 6){
			pula2[number_pula2].pula_is_on = 1;
			tank2.timer = 0;
			tank2.count_pules--;
		}
	}

	if (key == 't' && winner == 0){
		if (tank1.teleport == 1){
			int count = 0;
			do{
				count = 0;
				tank1.lx = rand() % 700 - 350;
				tank1.ly = rand() % 500 - 250;
				for (int x = 0; x < tank1.verx; x++){
					if (mainkoords[(int)(cos((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l)) + 400 + (int)tank1.lx][(int)(sin((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l)) + 300 + (int)tank1.ly][0] > 0){
						count = 1;
						break;
					}
				}
			} while (count != 0);
			tank1.motor = 1;
			tank1.motor_an = 1;
			tank1.speed = 0;
			tank1.teleport = 0;
		}
		if (tank2.teleport == 1){
			int count = 0;
			do{
				count = 0;
				tank2.lx = rand() % 700 - 350;
				tank2.ly = rand() % 500 - 250;
				for (int x = 0; x < tank2.verx; x++){
					if (mainkoords[(int)(cos((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l)) + 400 + (int)tank2.lx][(int)(sin((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l)) + 300 + (int)tank2.ly][0] > 0){
						count = 1;
						break;
					}
				}
			} while (count != 0);
			tank2.motor = 1;
			tank2.motor_an = 1;
			tank2.speed = 0;
			tank2.teleport = 0;
		}
	}

	if (key == 'n' && tank1.count_mines > 0 && winner == 0){
		int a = -1;
		do
			a++;
		while (mina.mines[a].seems == true);
		tank1.count_mines--;
		mina.mines[a].x = tank1.lx;
		mina.mines[a].y = tank1.ly;
		mina.mines[a].seems = true;
		mina.mines[a].time = 240 * 20;
	}
	if (key == 'm' && tank2.count_mines > 0 && winner == 0){
		int a = -1;
		do
			a++;
		while (mina.mines[a].seems == true);
		tank2.count_mines--;
		mina.mines[a].x = tank2.lx;
		mina.mines[a].y = tank2.ly;
		mina.mines[a].seems = true;
		mina.mines[a].time = 240*20;
	}
}

void tank1init(){
	tank1.speed = 0;
	tank1.an = 90;
	tank1.time_uppul *= 20;
	tank1.life = rand()%10 + 70;
	tank1.life_text[0] = 'l'; tank1.life_text[1] = 'i'; tank1.life_text[2] = 'f'; tank1.life_text[3] = 'e'; tank1.life_text[4] = ':';
	tank1.timer_text[0] = 'n'; tank1.timer_text[1] = 'e'; tank1.timer_text[2] = 'w'; tank1.timer_text[3] = ':';
	tank1.speed_text[0] = 's'; tank1.speed_text[1] = 'p'; tank1.speed_text[2] = 'e'; tank1.speed_text[3] = 'e'; tank1.speed_text[4] = 'd'; tank1.speed_text[5] = ':'; tank1.speed_text[8] = '.';
	//19 1 1 1 3 0 3 0 4 5 4 5 3 4 3 4 1 0 1 0 0 5 0 5 1 4 1 4 1.75 7 1.75 7 2.25 4 2.25 4 3 1 3 - tank1
	//0 0 0 1 5 1 5 0 0 3 0 4 5 4 5 3 1 1 1 3 4 3 4 1 4 1.75 4 2.25 6.5 2.25 6.5 1.75
	double centerkoordx, centerkoordy, xkoord = 0, ykoord = 0;
	double tankkoords[50] = { 0, 0, 0, 1, 5, 1, 5, 0, 0, 3, 0, 4, 5, 4, 5, 3, 1, 1, 1, 3, 4, 3, 4, 1, 4, 1.75, 4, 2.25, 6.5, 2.25, 6.5, 1.75, 1, 0, 2, 0, 3, 0, 4, 0, 1, 2, 1, 4, 2, 4, 3, 4, 4, 4 };
	tank1.verx = 25;
	xkoord = -340;
	ykoord = -238;
	centerkoordx = 30;
	centerkoordy = 20;
	for (int x = 0; x < tank1.verx; x++){
		tank1.koords[x].x = tankkoords[x * 2];
		tank1.koords[x].y = tankkoords[1 + x * 2];
		tank1.koords[x].x = tank1.koords[x].x * 10 + xkoord - centerkoordx;
		tank1.koords[x].y = tank1.koords[x].y * 10 + ykoord - centerkoordy;
	}
	tank1.lx = xkoord;
	tank1.ly = ykoord;
	for (int x = 0; x < tank1.verx; x++){
		tank1.koords[x].x = tank1.koords[x].x - tank1.lx;
		tank1.koords[x].y = tank1.koords[x].y - tank1.ly;
		tank1.koords[x].an = antan(tank1.koords[x].x, tank1.koords[x].y);
		tank1.koords[x].l = sqrt(tank1.koords[x].x*tank1.koords[x].x + tank1.koords[x].y*tank1.koords[x].y);
		tank1.koords[x].x = tank1.koords[x].x + tank1.lx;
		tank1.koords[x].y = tank1.koords[x].y + tank1.ly;
	}
}
void tank2init(){
	tank2.speed = 0;
	tank2.an = 270;
	tank2.time_uppul *= 20;
	tank2.life = rand() % 10 + 70;
	tank2.life_text[0] = 'l'; tank2.life_text[1] = 'i'; tank2.life_text[2] = 'f'; tank2.life_text[3] = 'e'; tank2.life_text[4] = ':';
	tank2.timer_text[0] = 'n'; tank2.timer_text[1] = 'e'; tank2.timer_text[2] = 'w'; tank2.timer_text[3] = ':';
	tank2.speed_text[0] = 's'; tank2.speed_text[1] = 'p'; tank2.speed_text[2] = 'e'; tank2.speed_text[3] = 'e'; tank2.speed_text[4] = 'd'; tank2.speed_text[5] = ':'; tank2.speed_text[8] = '.';
	//19 1 1 1 3 0 3 0 4 5 4 5 3 4 3 4 1 0 1 0 0 5 0 5 1 4 1 4 1.75 7 1.75 7 2.25 4 2.25 4 3 1 3 - tank2
	//0 0 0 1 5 1 5 0 0 3 0 4 5 4 5 3 1 1 1 3 4 3 4 1 4 1.75 4 2.25 6.5 2.25 6.5 1.75
	double centerkoordx, centerkoordy, xkoord = 0, ykoord = 0;
	double tankkoords[50] = { 0, 0, 0, 1, 5, 1, 5, 0, 0, 3, 0, 4, 5, 4, 5, 3, 1, 1, 1, 3, 4, 3, 4, 1, 4, 1.75, 4, 2.25, 6.5, 2.25, 6.5, 1.75, 1, 0, 2, 0, 3, 0, 4, 0, 1, 2, 1, 4, 2, 4, 3, 4, 4, 4 };
	tank2.verx = 25;
	xkoord = 320;
	ykoord = 220;
	centerkoordx = 30;
	centerkoordy = 20;
	for (int x = 0; x < tank2.verx; x++){
		tank2.koords[x].x = tankkoords[x * 2];
		tank2.koords[x].y = tankkoords[1 + x * 2];
		tank2.koords[x].x = tank2.koords[x].x * 10 + xkoord - centerkoordx;
		tank2.koords[x].y = tank2.koords[x].y * 10 + ykoord - centerkoordy;
	}
	tank2.lx = xkoord;
	tank2.ly = ykoord;
	for (int x = 0; x < tank2.verx; x++){
		tank2.koords[x].x = tank2.koords[x].x - tank2.lx;
		tank2.koords[x].y = tank2.koords[x].y - tank2.ly;
		tank2.koords[x].an = antan(tank2.koords[x].x, tank2.koords[x].y);
		tank2.koords[x].l = sqrt(tank2.koords[x].x*tank2.koords[x].x + tank2.koords[x].y*tank2.koords[x].y);
	}
}
void wallinit(){
	patrones[0].time = (rand() % 60 + 30) * 20;
	patrones[1].time = (rand() % 60 + 30) * 20;
	speed_new_patron.time = (rand() % 80 + 80) * 20;
	speed.time = (rand() % 80 + 60) * 20;
	heal.time = (rand() % 80 + 40) * 20;
	life_kupol.time = (rand() % 80 + 60) * 20;
	teleport.time = (rand() % 80 + 40) * 20;
	atom_bomb.time = (rand() % 30 + 115) * 20;
	mina.time = (rand() % 100 + 70) * 20;
	double wallkoords[count_of_wall][2] = { { 30, -100 }, { 240, 40 } , {286,-250}, {-60,-100}, {-140,-221}, {-224,-142},     {-270,180}, {-60,180}, {-270,68}, {-350,-158}, {-266,-237}, {160, -40} };
	//double wallkoords[count_of_wall][2] = { { 30, -100 }, { 240, 40 }, { 286, -250 }, { -60, -100 }, { -140, -221 }, { -224, -142 }, { -270, 180 }, { -60, 180 }, { -270, 68 }, { -350, -158 }, { -266, -237 }, { 160, -40 } };
	int count_of_vertical = 6; 
	for (int i = 0; i < count_of_vertical; i++){
		for (int y = 0; y < 10; y++){
			wall[i*10 + y].verx = 4;
			wall[i*10 + y].koords[0].x = wallkoords[i][0];
			wall[i*10 + y].koords[0].y = wallkoords[i][1] + 21 * y;
			wall[i*10 + y].koords[1].x = wallkoords[i][0];
			wall[i*10 + y].koords[1].y = wallkoords[i][1] + 20 + 21 * y;
			wall[i*10 + y].koords[2].x = wallkoords[i][0] + 15;
			wall[i*10 + y].koords[2].y = wallkoords[i][1] + 20 + 21 * y;
			wall[i*10 + y].koords[3].x = wallkoords[i][0] + 15;
			wall[i*10 + y].koords[3].y = wallkoords[i][1] + 21 * y;
			for (int x = 0; x < 20; x++){
				for (int z = 0; z < 15; z++){
					mainkoords[(int)wall[i * 10 + y].koords[0].x + z + 400][(int)wall[i * 10 + y].koords[0].y + x+300][0] = 2;
				}
			}
		}
	}
	for (int i = count_of_vertical; i < count_of_wall; i++){
		for (int y = 0; y < 10; y++){
			wall[i * 10 + y].verx = 4;
			wall[i * 10 + y].koords[0].x = wallkoords[i][0] + 21 * y;
			wall[i * 10 + y].koords[0].y = wallkoords[i][1];
			wall[i * 10 + y].koords[1].x = wallkoords[i][0] + 21 * y;
			wall[i * 10 + y].koords[1].y = wallkoords[i][1] + 15;
			wall[i * 10 + y].koords[2].x = wallkoords[i][0] + 20 + 21 * y;
			wall[i * 10 + y].koords[2].y = wallkoords[i][1] + 15;
			wall[i * 10 + y].koords[3].x = wallkoords[i][0] + 20 + 21 * y;
			wall[i * 10 + y].koords[3].y = wallkoords[i][1];
			for (int x = 0; x < 15; x++){
				for (int z = 0; z < 20; z++){
					mainkoords[(int)wall[i * 10 + y].koords[0].x + z + 400][(int)wall[i * 10 + y].koords[0].y + x + 300][0] = 2;
				}
			}
		}
	}
	for (int x = 0; x < 800; x++){
		for (int y = 0; y < 5; y++){
			mainkoords[x][y][0] = 2;
		}
	}
	for (int x = 0; x < 800; x++){
		for (int y = 595; y < 600; y++){
			mainkoords[x][y][0] = 2;
		}
	}
	for (int x = 0; x < 5; x++){
		for (int y = 0; y < 600; y++){
			mainkoords[x][y][0] = 2;
		}
	}
	for (int x = 795; x < 800; x++){
		for (int y = 0; y < 600; y++){
			mainkoords[x][y][0] = 2;
		}
	}
}

int main(int argc, char ** argv) {
	srand(time(NULL));

	tank1init();
	tank2init();
	wallinit();
	//pointsinit();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(999, 700);
	glutInitWindowPosition(200, 40);
	glutCreateWindow("");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400, 600.0, -400, 300.0, 0, 400.0);
	glutDisplayFunc(Draw);
	glutMouseFunc(MousePressedOnse);
	glutMotionFunc(MousePressedAndMove);
	glutPassiveMotionFunc(MouseDispressedAndMove);
	glutKeyboardFunc(KeyIsSymbol);
	glutSpecialFunc(Keyisnotsymbol);
	glutTimerFunc(50, Timer, 0);
	glutMainLoop();
	return 0;
}

void tank1_step(){
	if (tank1.motor == 2 && tank1.speed < 3 + tank1.bonus_speed) tank1.speed += 0.1;
	if (tank1.motor == 1 && tank1.speed > 0.0)tank1.speed-= 0.1;
	if (tank1.motor == 1 && tank1.speed < 0.0)tank1.speed += 0.1;
	if (tank1.motor == 0 && tank1.speed > -1.5 - tank1.bonus_speed/2) tank1.speed -= 0.1;
	if (tank1.motor == 1 && tank1.speed > 0.0)tank1.speed -= 0.1;

	if (tank1.motor_an == 2) tank1.an+=(1.4 + tank1.bonus_an);
	if (tank1.motor_an == 1) tank1.an -= (1.4 + tank1.bonus_an);
	if (tank1.motor_an == 1) tank1.an += (1.4 + tank1.bonus_an);
	if (tank1.motor_an == 0) tank1.an -= (1.4 + tank1.bonus_an);

	double lxv, lyv, xv, yv;
	lxv = tank1.lx + cos((tank1.an)*3.14 / 180)*(tank1.speed*1.0);
	lyv = tank1.ly + sin((tank1.an)*3.14 / 180)*(tank1.speed*1.0);
	for (int x = 0; x < tank1.verx; x++){
		xv = cos((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l) + lxv;
		yv = sin((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l) + lyv;
		if (mainkoords[(int)xv + 400][(int)yv + 300][0] > 0){
			if (mainkoords[(int)xv + 400][(int)yv + 300][0] == 2){
				tank1.speed = 0;
				tank1.motor = 1;
				tank1.an -= (1.4 + tank1.bonus_an)*(tank1.motor_an - 1);
				tank1.motor_an = 1;
			}
			if (mainkoords[(int)xv + 400][(int)yv + 300][0] == 1){
				tank1.speed = 0;
				tank1.an -= (1.4 + tank1.bonus_an)*(tank1.motor_an - 1);
				tank1.motor_an = 1;
				for (int y = 0; y < 10 * count_of_wall; y++){
					if (wall[y].koords[0].x <= (int)xv && wall[y].koords[0].y <= (int)yv && wall[y].koords[2].x >= (int)xv && wall[y].koords[2].y >= (int)yv){
						wall[y].seems = 0;
						for (int i = wall[y].koords[0].x; i < wall[y].koords[2].x; i++){
							for (int j = wall[y].koords[0].y; j < wall[y].koords[2].y; j++){
								mainkoords[i + 400][j + 300][0] = 0;
							}
						}
						break;
					}
				}
			}
			tank1.lx = tank1.lx + cos((tank1.an)*3.14 / 180)*tank1.speed*-0.8;
			tank1.ly = tank1.ly + sin((tank1.an)*3.14 / 180)*tank1.speed*-0.8;
			break;
		}
	}
	tank1.lx = tank1.lx + cos((tank1.an)*3.14 / 180)*tank1.speed;
	tank1.ly = tank1.ly + sin((tank1.an)*3.14 / 180)*tank1.speed;
	for (int x = 0; x < tank1.verx; x++){
		tank1.koords[x].x = cos((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l) + tank1.lx;
		tank1.koords[x].y = sin((tank1.an + tank1.koords[x].an)*3.14 / 180) * (tank1.koords[x].l) + tank1.ly;
	}

	if (tank1.an> 360) tank1.an = 1;
	if (tank1.an < 0) tank1.an = 359;

	if (tank1.timer < tank1.time_uppul && tank1.count_pules > 0) tank1.timer++;
	if (main_timer % 800 == 0 && tank1.life <= 55) tank1.life += 8;
}
void tank2_step(){
	if (tank2.motor == 2 && tank2.speed < 3 + tank2.bonus_speed) tank2.speed += 0.1;
	if (tank2.motor == 1 && tank2.speed > 0.0)tank2.speed -= 0.1;
	if (tank2.motor == 1 && tank2.speed < 0.0)tank2.speed += 0.1;
	if (tank2.motor == 0 && tank2.speed > -1.5 - tank2.bonus_speed/2) tank2.speed -= 0.1;
	if (tank2.motor == 1 && tank2.speed > 0.0)tank2.speed -= 0.1;

	if (tank2.motor_an == 2) tank2.an += (1.4 + tank2.bonus_an);
	if (tank2.motor_an == 1) tank2.an -= (1.4 + tank2.bonus_an);
	if (tank2.motor_an == 1) tank2.an += (1.4 + tank2.bonus_an);
	if (tank2.motor_an == 0) tank2.an -= (1.4 + tank2.bonus_an);

	double lxv, lyv, xv, yv;
	lxv = tank2.lx + cos((tank2.an)*3.14 / 180)*(tank2.speed*1.0);
	lyv = tank2.ly + sin((tank2.an)*3.14 / 180)*(tank2.speed*1.0);
	for (int x = 0; x < tank2.verx; x++){
		xv = cos((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l) + lxv;
		yv = sin((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l) + lyv;
		if (mainkoords[(int)xv + 400][(int)yv + 300][0] > 0){
			if (mainkoords[(int)xv + 400][(int)yv + 300][0] == 2){
				tank2.speed = 0;
				tank2.motor = 1;
				tank2.an -= (1.4 + tank2.bonus_an)*(tank2.motor_an - 1);
				tank2.motor_an = 1;
			}
			if (mainkoords[(int)xv + 400][(int)yv + 300][0] == 1){
				tank2.speed = 0;
				tank2.an -= (1.4 + tank2.bonus_an)*(tank2.motor_an - 1);
				tank2.motor_an = 1;
				for (int y = 0; y < 10 * count_of_wall; y++){
					if (wall[y].koords[0].x <= (int)xv && wall[y].koords[0].y <= (int)yv && wall[y].koords[2].x >= (int)xv && wall[y].koords[2].y >= (int)yv){
						wall[y].seems = 0;
						for (int i = wall[y].koords[0].x; i < wall[y].koords[2].x; i++){
							for (int j = wall[y].koords[0].y; j < wall[y].koords[2].y; j++){
								mainkoords[i + 400][j + 300][0] = 0;
							}
						}
						break;
					}
				}
			}
			tank2.lx = tank2.lx + cos((tank2.an)*3.14 / 180)*tank2.speed*-0.8;
			tank2.ly = tank2.ly + sin((tank2.an)*3.14 / 180)*tank2.speed*-0.8;
			break;
		}
	}

	tank2.lx = tank2.lx + cos((tank2.an)*3.14 / 180)*tank2.speed;
	tank2.ly = tank2.ly + sin((tank2.an)*3.14 / 180)*tank2.speed;
	for (int x = 0; x < tank2.verx; x++){
		tank2.koords[x].x = cos((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l) + tank2.lx;
		tank2.koords[x].y = sin((tank2.an + tank2.koords[x].an)*3.14 / 180) * (tank2.koords[x].l) + tank2.ly;
	}

	if (tank2.an> 360) tank2.an = 1;
	if (tank2.an < 0) tank2.an = 359;

	if (tank2.timer < tank2.time_uppul && tank2.count_pules > 0) tank2.timer++;
	if ((main_timer) % 800 == 0 && tank2.life <= 55) tank2.life += 8;
}
void pula1_step(int num){
	if (pula1[num].seems == 1 && mainkoords[(int)pula1[num].x + 400][(int)pula1[num].y + 300][0] > 0){
		pula1[num].seems = 0;
		pula1[num].pula_is_on = 0;
		for (int y = 0; y < 10 * count_of_wall; y++){
			if (wall[y].koords[0].x <= (int)pula1[num].x && wall[y].koords[0].y <= (int)pula1[num].y && wall[y].koords[2].x >= (int)pula1[num].x && wall[y].koords[2].y >= (int)pula1[num].y){
				wall[y].seems--;
				for (int i = wall[y].koords[0].x; i < wall[y].koords[2].x; i++){
					for (int j = wall[y].koords[0].y; j < wall[y].koords[2].y; j++){
						mainkoords[i + 400][j + 300][0] = wall[y].seems;
					}
				}
				break;
			}
		}
	}
	if (pula1[num].pula_is_on == 0) pula1[num].seems = 0;
	if (pula1[num].pula_is_on == 1){
		pula1[num].x = tank1.lx + cos((tank1.koords[14].an + tank1.an - 4.6)*3.14 / 180)*(tank1.koords[14].l - 10);
		pula1[num].y = tank1.ly + sin((tank1.koords[14].an + tank1.an - 4.6)*3.14 / 180)*(tank1.koords[14].l - 10);
		pula1[num].an = tank1.an;
		pula1[num].speed = 8;
		pula1[num].pula_is_on++;
		pula1[num].seems = 1;
	}
	if (pula1[num].pula_is_on > 1){
		pula1[num].x = pula1[num].x + cos((pula1[num].an)*3.14 / 180)*pula1[num].speed;
		pula1[num].y = pula1[num].y + sin((pula1[num].an)*3.14 / 180)*pula1[num].speed;
	}
	if (pula1[num].seems == 1 && pula1[num].x + 20 > tank2.lx && pula1[num].x - 20 < tank2.lx && pula1[num].y + 20 > tank2.ly && pula1[num].y - 20 < tank2.ly){
		if (tank2.life_kupol == false){
			tank2.life = tank2.life - rand() % 10 - 12;
			if (tank2.life < 0) tank2.life = 0;
		}
		pula1[num].x = -1000;
	}
	if (pula1[num].x < -395 || pula1[num].x > 395 || pula1[num].y < -295 || pula1[num].y > 295){
		pula1[num].pula_is_on = 0;
		pula1[num].seems = 0;
	}
}
void pula2_step(int num){
	if (pula2[num].seems == 1 && mainkoords[(int)pula2[num].x + 400][(int)pula2[num].y + 300][0] > 0){
		pula2[num].seems = 0;
		pula2[num].pula_is_on = 0;
		for (int y = 0; y < 10 * count_of_wall; y++){
			if (wall[y].koords[0].x <= (int)pula2[num].x && wall[y].koords[0].y <= (int)pula2[num].y && wall[y].koords[2].x >= (int)pula2[num].x && wall[y].koords[2].y >= (int)pula2[num].y){
				wall[y].seems--;
				for (int i = wall[y].koords[0].x; i < wall[y].koords[2].x; i++){
					for (int j = wall[y].koords[0].y; j < wall[y].koords[2].y; j++){
						mainkoords[i + 400][j + 300][0] = wall[y].seems;
					}
				}
				break;
			}
		}
	}
	if (pula2[num].pula_is_on == 0) pula2[num].seems = 0;
	if (pula2[num].pula_is_on == 1){
		pula2[num].x = tank2.lx + cos((tank2.koords[14].an + tank2.an - 4.6)*3.14 / 180)*(tank2.koords[14].l - 10);
		pula2[num].y = tank2.ly + sin((tank2.koords[14].an + tank2.an - 4.6)*3.14 / 180)*(tank2.koords[14].l - 10);
		pula2[num].an = tank2.an;
		pula2[num].speed = 8;
		pula2[num].pula_is_on++;
		pula2[num].seems = 1;
	}
	if (pula2[num].pula_is_on > 1){
		pula2[num].x = pula2[num].x + cos((pula2[num].an)*3.14 / 180)*pula2[num].speed;
		pula2[num].y = pula2[num].y + sin((pula2[num].an)*3.14 / 180)*pula2[num].speed;
	}
	if (pula2[num].seems == 1 && pula2[num].x + 20 > tank1.lx && pula2[num].x - 20 < tank1.lx && pula2[num].y + 20 > tank1.ly && pula2[num].y - 20 < tank1.ly){
		if (tank1.life_kupol == false){
			tank1.life = tank1.life - rand() % 10 - 12;
			if (tank1.life < 0) tank1.life = 0;
		}
		pula2[num].x = -1000;
	}
	if (pula2[num].x < -395 || pula2[num].x > 395 || pula2[num].y < -295 || pula2[num].y > 295){
		pula2[num].pula_is_on = 0;
		pula2[num].seems = 0;
	}
}

void patronesstep(int num){
	if (patrones[num].seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < patrones[num].x + 15 && tank1.koords[x].x > patrones[num].x - 15 && tank1.koords[x].y < patrones[num].y + 15 && tank1.koords[x].y > patrones[num].y - 15){
				tank1.count_pules += 3;
				if (tank1.count_pules > 6) tank1.count_pules = 6;
				patrones[num].seems = false;
				patrones[num].time = (rand() % 40 + 25) * 20;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < patrones[num].x + 15 && tank2.koords[x].x > patrones[num].x - 15 && tank2.koords[x].y < patrones[num].y + 15 && tank2.koords[x].y > patrones[num].y - 15){
				tank2.count_pules += 3;
				if (tank2.count_pules > 6) tank2.count_pules = 6;
				patrones[num].seems = false;
				patrones[num].time = (rand() % 40 + 25) * 20;
				break;
			}
		}
	}

	if (patrones[num].time == 0){
		if (patrones[num].seems == false) {
			patrones[num].seems = true;
			patrones[num].x = rand() % 375;
			if (num == 0)
				patrones[num].x -= 375;
			patrones[num].y = rand() % 550 - 275;
			patrones[num].time = (rand() % 10 + 15) * 20;
		}else {
			patrones[num].seems = false;
			patrones[num].time = (rand() % 40 + 20)*20;
		}
	}

	if (patrones[num].time > 0) patrones[num].time--;
	patrones[num].time_text[0] = 48 + (int)(patrones[num].time / 20) / 10;
	patrones[num].time_text[1] = 48 + (int)(patrones[num].time / 20) % 10;

}
void speed_new_patronstep(){
	if (speed_new_patron.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < speed_new_patron.x + 15 && tank1.koords[x].x > speed_new_patron.x - 15 && tank1.koords[x].y < speed_new_patron.y + 15 && tank1.koords[x].y > speed_new_patron.y - 15){
				if (tank1.count_pules < 6) tank1.count_pules += 1;
				if (tank1.time_uppul > 20) {
					tank1.time_uppul -= 20;
					if (tank1.timer >= tank1.time_uppul)
						tank1.timer -= 20;
				}
				else{
					tank1.time_uppul = 1;
					tank1.timer = 1;
				}
				speed_new_patron.seems = false;
				speed_new_patron.time = (rand() % 90 + 70) * 20;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < speed_new_patron.x + 15 && tank2.koords[x].x > speed_new_patron.x - 15 && tank2.koords[x].y < speed_new_patron.y + 15 && tank2.koords[x].y > speed_new_patron.y - 15){
				if (tank2.count_pules < 6) tank2.count_pules += 1;
				if (tank2.time_uppul > 20){
					tank2.time_uppul -= 20;
					if (tank2.timer >= tank2.time_uppul)
						tank2.timer -= 20;
				}
				else{
					tank2.time_uppul = 1;
					tank2.timer = 1;
				}
				speed_new_patron.seems = false;
				speed_new_patron.time = (rand() % 90 + 70) * 20;
				break;
			}
		}
	}

	if (speed_new_patron.time == 0){
		if (speed_new_patron.seems == false) {
			speed_new_patron.seems = true;
			speed_new_patron.x = rand() % 750 - 375;
			speed_new_patron.y = rand() % 550 - 275;
			speed_new_patron.time = (rand() % 15 + 25) * 20;
		}
		else {
			speed_new_patron.seems = false;
			speed_new_patron.time = (rand() % 90 + 70) * 20;
		}
	}

	if (speed_new_patron.time > 0) speed_new_patron.time--;
	speed_new_patron.time_text[0] = 48 + (int)(speed_new_patron.time / 20) / 10;
	speed_new_patron.time_text[1] = 48 + (int)(speed_new_patron.time / 20) % 10;
}
void speedstep(){
	if (speed.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < speed.x + 15 && tank1.koords[x].x > speed.x - 15 && tank1.koords[x].y < speed.y + 15 && tank1.koords[x].y > speed.y - 15){
				tank1.bonus_speed = 2.5;
				tank1.bonus_an = 1.7;
				speed.seems = false;
				speed.time = (rand() % 80 + 150) * 20;
				tank1.bonus_timespeed = speed.time;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < speed.x + 15 && tank2.koords[x].x > speed.x - 15 && tank2.koords[x].y < speed.y + 15 && tank2.koords[x].y > speed.y - 15){
				tank2.bonus_speed = 2.5;
				tank2.bonus_an = 1.7;
				speed.seems = false;
				speed.time = (rand() % 80 + 150) * 20;
				tank2.bonus_timespeed = speed.time;
				break;
			}
		}
	}

	if (tank1.bonus_timespeed - speed.time >= 800){
		tank1.bonus_timespeed = 0;
		tank1.bonus_speed = 0;
		tank1.bonus_an = 0;
		if (tank1.speed < -1) tank1.speed = -1;
		if (tank1.speed > 2) tank1.speed = 2;
	}
	if (tank2.bonus_timespeed - speed.time >= 800){
		tank2.bonus_timespeed = 0;
		tank2.bonus_speed = 0;
		tank2.bonus_an = 0;
		if (tank2.speed < -1) tank2.speed = -1;
		if (tank2.speed > 2) tank2.speed = 2;
	}

	if (speed.time == 0){
		if (speed.seems == false) {
			speed.seems = true;
			speed.x = rand() % 750 - 375;
			speed.y = rand() % 550 - 275;
			speed.time = (rand() % 15 + 20) * 20;
		}
		else {
			speed.seems = false;
			speed.time = (rand() % 80 + 160) * 20;
		}
	}

	

	if (speed.time > 0) speed.time--;
	speed.time_text[0] = 48 + (int)(speed.time / 20) / 10;
	speed.time_text[1] = 48 + (int)(speed.time / 20) % 10;
}
void healstep(){
	if (heal.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < heal.x + 15 && tank1.koords[x].x > heal.x - 15 && tank1.koords[x].y < heal.y + 15 && tank1.koords[x].y > heal.y - 15){
				tank1.life += 15;
				if (tank1.life > 100)
					tank1.life = 100;
				heal.seems = false;
				heal.time = (rand() % 100) * 20;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < heal.x + 15 && tank2.koords[x].x > heal.x - 15 && tank2.koords[x].y < heal.y + 15 && tank2.koords[x].y > heal.y - 15){
				tank2.life += 15;
				if (tank2.life > 100)
					tank2.life = 100;
				heal.seems = false;
				heal.time = (rand() % 100) * 20;
				break;
			}
		}
	}

	if (heal.time == 0){
		if (heal.seems == false) {
			heal.seems = true;
			heal.x = rand() % 750 - 375;
			heal.y = rand() % 550 - 275;
			heal.time = (rand() % 10 + 20) * 20;
		}
		else {
			heal.seems = false;
			heal.time = (rand() % 100) * 20;
		}
	}

	if (heal.time > 0) heal.time--;
	heal.time_text[0] = 48 + (int)(heal.time / 20) / 10;
	heal.time_text[1] = 48 + (int)(heal.time / 20) % 10;
}
void life_kupolstep(){
	if (life_kupol.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < life_kupol.x + 15 && tank1.koords[x].x > life_kupol.x - 15 && tank1.koords[x].y < life_kupol.y + 15 && tank1.koords[x].y > life_kupol.y - 15){
				tank1.life_kupol = true;
				life_kupol.seems = false;
				life_kupol.time = (rand() % 100 + 150) * 20;
				tank1.bonus_timekupol = life_kupol.time;
				break;
			}
		}

		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < life_kupol.x + 15 && tank2.koords[x].x > life_kupol.x - 15 && tank2.koords[x].y < life_kupol.y + 15 && tank2.koords[x].y > life_kupol.y - 15){
				tank2.life_kupol = true;
				life_kupol.seems = false;
				life_kupol.time = (rand() % 100 + 150) * 20;
				tank2.bonus_timekupol = life_kupol.time;
				break;
			}
		}
	}

	if (tank1.bonus_timekupol - life_kupol.time >= 30 * 20){
		tank1.bonus_timekupol = 0;
		tank1.life_kupol = false;
	}
	if (tank2.bonus_timekupol - life_kupol.time >= 30 * 20){
		tank2.bonus_timekupol = 0;
		tank2.life_kupol = false;
	}

	if (life_kupol.time == 0){
		if (life_kupol.seems == false) {
			life_kupol.seems = true;
			life_kupol.x = rand() % 750 - 375;
			life_kupol.y = rand() % 550 - 275;
			life_kupol.time = (rand() % 10 + 30) * 20;
		}
		else {
			life_kupol.seems = false;
			life_kupol.time = (rand() % 100 + 150) * 20;
		}
	}

	if (life_kupol.time > 0) life_kupol.time--;
	life_kupol.time_text[0] = 48 + (int)(life_kupol.time / 20) / 10;
	life_kupol.time_text[1] = 48 + (int)(life_kupol.time / 20) % 10;
}
void atom_bombstep(){
	int count = 0;
	if (atom_bomb.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < atom_bomb.x + 15 && tank1.koords[x].x > atom_bomb.x - 15 && tank1.koords[x].y < atom_bomb.y + 15 && tank1.koords[x].y > atom_bomb.y - 15){
				count++;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < atom_bomb.x + 15 && tank2.koords[x].x > atom_bomb.x - 15 && tank2.koords[x].y < atom_bomb.y + 15 && tank2.koords[x].y > atom_bomb.y - 15){
				count++;
				break;
			}
		}
	}

	if (count > 0){
		atom_bomb.seems = false;
		atom_bomb.time = (rand() % 90 + 100) * 20;
		atom_bomb.x = rand() % 640 - 320;
		atom_bomb.y = rand() % 440 - 220;
		atom_bomb.boom = 1;
		atom_bomb.power = 1;
	}
	if (atom_bomb.boom == 1){
		atom_bomb.power -= 0.007;
	}
	if (atom_bomb.boom == 2){
		atom_bomb.power += 0.05;
	}
	if (atom_bomb.power <= 0.35 && atom_bomb.boom == 1){
		atom_bomb.boom = 2;
		atom_bomb.power = 0;
		for (int x = 0; x < count_of_wall * 10; x++){
			if (wall[x].seems > 0){
				if (pow(wall[x].koords[0].x - atom_bomb.x, 2) + pow(wall[x].koords[0].y - atom_bomb.y, 2) <= 22500 || pow(wall[x].koords[2].x - atom_bomb.x, 2) + pow(wall[x].koords[2].y - atom_bomb.y, 2) <= 22500){
					if (wall[x].seems == 1)wall[x].seems = 0;
					int a = rand() % 100;
					if (a < 50 || wall[x].seems == 0){
						if (wall[x].seems > 0)
							wall[x].seems--;
						for (int i = wall[x].koords[0].x; i < wall[x].koords[2].x; i++){
							for (int j = wall[x].koords[0].y; j < wall[x].koords[2].y; j++){
								mainkoords[i + 400][j + 300][0] = wall[x].seems;
							}
						}
					}
				}
			}
		}
		for (int x = 0; x < tank1.verx; x++){
			if (pow(tank1.koords[x].x - atom_bomb.x, 2) + pow(tank1.koords[x].y - atom_bomb.y, 2) <= 22500){
				if (tank1.life_kupol == true){
					tank1.life_kupol = false;
					tank1.bonus_timekupol = 10000;
					tank1.life -= 10;
				}
				else{
					tank1.life -= rand() % 20 + 50;
					if (tank1.life < 0) tank1.life = 0;
				}
				break;
			}
		}
		for (int x = 0; x < tank2.verx; x++){
			if (pow(tank2.koords[x].x - atom_bomb.x, 2) + pow(tank2.koords[x].y - atom_bomb.y, 2) <= 22500){
				if (tank2.life_kupol == true){
					tank2.life_kupol = false;
					tank2.bonus_timekupol = 10000;
					tank2.life -= 10;
				}
				else{
					tank2.life -= rand() % 20 + 50;
					if (tank2.life < 0) tank2.life = 0;
				}
				break;
			}
		}
		for (int x = 0; x < 6; x++){
			if (mina.mines[x].seems == true && pow(mina.mines[x].x - atom_bomb.x, 2) + pow(mina.mines[x].y - atom_bomb.y, 2) <= 22500){
				mina.mines[x].seems = false;
				mina.mines[x].time = 0;
			}
		}
	}
	if (atom_bomb.power >= 1 && atom_bomb.boom == 2){
		atom_bomb.boom = 0;
	}
	if (atom_bomb.time == 0){
		if (atom_bomb.seems == false) {
			atom_bomb.seems = true;
			atom_bomb.x = rand() % 750 - 375;
			atom_bomb.y = rand() % 550 - 275;
			atom_bomb.time = (rand() % 15 + 25) * 20;
		}
		else {
			atom_bomb.seems = false;
			atom_bomb.time = (rand() % 90 + 100) * 20;
		}
	}

	if (atom_bomb.time > 0) atom_bomb.time--;
	atom_bomb.time_text[0] = 48 + (int)(atom_bomb.time / 20) / 10;
	atom_bomb.time_text[1] = 48 + (int)(atom_bomb.time / 20) % 10;
}
void teleportstep(){
	if (teleport.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < teleport.x + 15 && tank1.koords[x].x > teleport.x - 15 && tank1.koords[x].y < teleport.y + 15 && tank1.koords[x].y > teleport.y - 15){
				tank1.teleport = 1;
				teleport.seems = false;
				teleport.time = (rand() % 70 + 100) * 20;
				tank1.timeteleport = teleport.time;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < teleport.x + 15 && tank2.koords[x].x > teleport.x - 15 && tank2.koords[x].y < teleport.y + 15 && tank2.koords[x].y > teleport.y - 15){
				tank2.teleport = 1;
				teleport.seems = false;
				teleport.time = (rand() % 70 + 100) * 20;
				tank2.timeteleport = teleport.time;
				break;
			}
		}
	}

	if (tank1.timeteleport - teleport.time >= 40 * 20){
		tank1.timeteleport = 0;
		tank1.teleport = 0;
	}
	if (tank2.timeteleport - teleport.time >= 40 * 20){
		tank2.timeteleport = 0;
		tank2.teleport = 0;
	}

	if (teleport.time == 0){
		if (teleport.seems == false) {
			teleport.seems = true;
			teleport.x = rand() % 750 - 375;
			teleport.y = rand() % 550 - 275;
			teleport.time = (rand() % 10 + 20) * 20;
		}
		else {
			teleport.seems = false;
			teleport.time = (rand() % 70 + 100) * 20;
		}
	}

	if (teleport.time > 0) teleport.time--;
	teleport.time_text[0] = 48 + (int)(teleport.time / 20) / 10;
	teleport.time_text[1] = 48 + (int)(teleport.time / 20) % 10;
}
void minastep(){
	if (mina.seems == true){
		for (int x = 0; x < tank1.verx - 8; x++){
			if (tank1.koords[x].x < mina.x + 15 && tank1.koords[x].x > mina.x - 15 && tank1.koords[x].y < mina.y + 15 && tank1.koords[x].y > mina.y - 15){
				tank1.count_mines += 3;
				if (tank1.count_mines > 3)
					tank1.count_mines = 3;
				mina.seems = false;
				mina.time = (rand() % 40 + 180) * 20;
				break;
			}
		}
		for (int x = 0; x < tank2.verx - 8; x++){
			if (tank2.koords[x].x < mina.x + 15 && tank2.koords[x].x > mina.x - 15 && tank2.koords[x].y < mina.y + 15 && tank2.koords[x].y > mina.y - 15){
				tank2.count_mines += 3;
				if (tank2.count_mines > 3)
					tank2.count_mines = 3;
				mina.seems = false;
				mina.time = (rand() % 40 + 180) * 20;
				break;
			}
		}
	}


	for (int x = 0; x < 6; x++){
		if (mina.mines[x].seems == true){
			mina.mines[x].time_text[0] = 48 + (int)(mina.mines[x].time / 20) / 100;
			if (mina.mines[x].time_text[0] == '0') 
				mina.mines[x].time_text[0] = ' ';
			mina.mines[x].time_text[1] = 48 + (int)((mina.mines[x].time / 20) / 10)%10;
			mina.mines[x].time_text[2] = 48 + (int)(mina.mines[x].time / 20) % 10;
			mina.mines[x].time--;
		}
		if (mina.mines[x].time == 0)
			mina.mines[x].seems = false;
		if (mina.mines[x].seems == true && mina.mines[x].time < 236 * 20 && mina.mines[x].x > tank1.lx - 30 && mina.mines[x].x < tank1.lx + 20 && mina.mines[x].y > tank1.ly - 20 && mina.mines[x].y < tank1.ly + 20){
			mina.mines[x].seems = false;
			mina.mines[x].time = 0;
			if (tank1.life_kupol == true){
				tank1.life_kupol = false;
				tank1.bonus_timekupol = 10000;
				tank1.life -= (rand() % 10);
			}
			else
				tank1.life -= (rand() % 20 + 10);
			if (tank1.life < 0) tank1.life = 0;
		}
		if (mina.mines[x].seems == true && mina.mines[x].time < 236 * 20 && mina.mines[x].x > tank2.lx - 30 && mina.mines[x].x < tank2.lx + 20 && mina.mines[x].y > tank2.ly - 20 && mina.mines[x].y < tank2.ly + 20){
			mina.mines[x].seems = false;
			mina.mines[x].time = 0;
			if (tank2.life_kupol == true){
				tank2.life_kupol = false;
				tank2.bonus_timekupol = 10000;
				tank2.life -= (rand() % 10);
			}
			else
				tank2.life -= (rand() % 20 + 10);
			if (tank2.life < 0) tank2.life = 0;
		}
	}

	if (mina.time == 0){
		if (mina.seems == false) {
			if (tank1.count_mines + tank2.count_mines + mina.mines[0].seems + mina.mines[1].seems + mina.mines[2].seems + mina.mines[3].seems + mina.mines[4].seems + mina.mines[5].seems <= 3){
				mina.seems = true;
				mina.x = rand() % 750 - 375;
				mina.y = rand() % 550 - 275;
				mina.time = (rand() % 15 + 40) * 20;
			}
			else
				mina.time = (rand() % 60 + 40) * 20;
		}
		else {
				mina.seems = false;
				mina.time = (rand() % 40 + 180) * 20;
		}
	}

	if (mina.time > 0) mina.time--;
	mina.time_text[0] = 48 + (int)(mina.time / 20) / 10;
	mina.time_text[1] = 48 + (int)(mina.time / 20) % 10;
}

void circle(float x, float y, float r, bool color, double redc, double greenc, double bluec){
	glColor3f(redc, greenc, bluec);
	if (color)
		glBegin(GL_POLYGON);
	else
		glBegin(GL_LINE_LOOP);
	for (int i = -r; i <= r; i++)
		glVertex2f(x + i, y + sqrt(r*r-i*i));
	for (int i = r; i >=  -r; i--)
		glVertex2f(x + i, y - sqrt(r*r - i*i));

	glEnd();
}
void minadraw(double x, double y){
	circle(x, y, 4, true, 1);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);

	glVertex2f(x - 7, y - 5);
	glVertex2f(x - 7, y);
	glVertex2f(x+7, y);
	glVertex2f(x+7, y - 5);

	glEnd();
}
void draw_board(){
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-400, -300);
	glVertex2f(-400, -295);
	glVertex2f(400, -295);
	glVertex2f(400, -300);

	glVertex2f(-400, -300);
	glVertex2f(-400, 300);
	glVertex2f(-395, 300);
	glVertex2f(-395, -300);

	glVertex2f(-400, 295);
	glVertex2f(-400, 300);
	glVertex2f(400, 300);
	glVertex2f(400, 295);

	glVertex2f(395, -300);
	glVertex2f(395, 300);
	glVertex2f(400, 300);
	glVertex2f(400, -300);

	glEnd();
}
void draw_bonus(){
	if (patrones[0].seems == true){
		circle(patrones[0].x, patrones[0].y, 20, true, 0, 1);
		Add_text("p", patrones[0].x - 8, patrones[0].y - 10, 1, 3);
		Add_text(patrones[0].time_text, patrones[0].x + 12, patrones[0].y + 12, 2, 1.3, "red");
	}
	if (patrones[1].seems == true){
		circle(patrones[1].x, patrones[1].y, 20, true, 0, 1);
		Add_text("p", patrones[1].x - 8, patrones[1].y - 10, 1,3);
		Add_text(patrones[1].time_text, patrones[1].x + 12, patrones[1].y + 12, 2, 1.3, "red");
	}
	if (speed_new_patron.seems == true){
		circle(speed_new_patron.x, speed_new_patron.y, 20, true, 0, 1);
		Add_text("sp", speed_new_patron.x - 16, speed_new_patron.y - 10, 2);
		Add_text(speed_new_patron.time_text, speed_new_patron.x + 12, speed_new_patron.y + 12, 2, 1.3, "red");
	}
	if (speed.seems == true){
		circle(speed.x, speed.y, 20, true, 0, 1);
		Add_text("s", speed.x - 8, speed.y - 10, 1, 3);
		Add_text(speed.time_text, speed.x + 12, speed.y + 12, 2, 1.3, "red");
	}
	if (heal.seems == true){
		circle(heal.x, heal.y, 20, true, 0, 1);
		Add_text("h", heal.x - 8, heal.y - 10, 1, 3);
		Add_text(heal.time_text, heal.x + 12, heal.y + 12, 2, 1.3, "red");
	}
	if (life_kupol.seems == true){
		circle(life_kupol.x, life_kupol.y, 20, true, 0, 1);
		Add_text("k", life_kupol.x - 8, life_kupol.y - 10, 1, 3);
		Add_text(life_kupol.time_text, life_kupol.x + 12, life_kupol.y + 12, 2, 1.3, "red");
	}
	if (atom_bomb.seems == true){
		circle(atom_bomb.x, atom_bomb.y, 20, true, 0, 1);
		Add_text("b", atom_bomb.x - 8, atom_bomb.y - 10, 1, 3, "red");
		Add_text(atom_bomb.time_text, atom_bomb.x + 12, atom_bomb.y + 12, 2, 1.3, "red");
	}
	if (teleport.seems == true){
		circle(teleport.x, teleport.y, 20, true, 0, 1);
		Add_text("t", teleport.x - 8, teleport.y - 10, 1, 3);
		Add_text(teleport.time_text, teleport.x + 12, teleport.y + 12, 2, 1.3, "red");
	}
	if (mina.seems == true){
		circle(mina.x, mina.y, 20, true, 0, 1);
		Add_text("m", mina.x - 8, mina.y - 10, 1, 3);
		Add_text(mina.time_text, mina.x + 12, mina.y + 12, 2, 1.3, "red");
	}
	for (int x = 0; x < 6; x++){
		if (mina.mines[x].seems == true){
			minadraw(mina.mines[x].x, mina.mines[x].y);
			if(mina.mines[x].time < 237*20 )
				Add_text(mina.mines[x].time_text, mina.mines[x].x + 8, mina.mines[x].y + 4, 3, 1.3, "red");
		}
	}
	if (tank1.life_kupol == true)  circle(tank1.lx, tank1.ly, 40, false, 0, 0, 0.5);
	if (tank2.life_kupol == true)  circle(tank2.lx, tank2.ly, 40, false, 0, 0, 0.5);
	if (atom_bomb.boom == 1){
		circle(atom_bomb.x, atom_bomb.y, 150, false, atom_bomb.power, atom_bomb.power, atom_bomb.power);
	}
	if (atom_bomb.boom == 2){
		circle(atom_bomb.x, atom_bomb.y, 150, true, atom_bomb.power, atom_bomb.power, atom_bomb.power);
	}
}
void draw_tanks_info(){
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.3, 1.0);
	glVertex2f(-400, -400);
	glVertex2f(0, -400);
	glColor3f(0.8, 0.8, 1.0);
	glVertex2f(0, -300);
	glVertex2f(-400, -300);

	glColor3f(1.0, 0.3, 0.3);
	glVertex2f(0, -400);
	glVertex2f(400, -400);
	glColor3f(1.0, 0.8, 0.8);
	glVertex2f(400, -300);
	glVertex2f(0, -300);

	glEnd();

	tank1.life_text[6] = 48 + (tank1.life / 100);
	tank1.life_text[7] = 48 + (int)(tank1.life / 10) % 10;
	tank1.life_text[8] = 48 + (int)tank1.life % 10;

	tank2.life_text[6] = 48 + (tank2.life / 100);
	tank2.life_text[7] = 48 + (int)(tank2.life / 10) % 10;
	tank2.life_text[8] = 48 + (int)tank2.life % 10;

	tank1.timer_text[5] = 48 + (int)(tank1.timer / tank1.time_uppul)%10;
	tank1.timer_text[6] = 48 + (int)(tank1.timer / tank1.time_uppul *10)%10;
	tank1.timer_text[7] = 48 + (int)(tank1.timer / tank1.time_uppul * 100) % 10;
	tank2.timer_text[5] = 48 + (int)(tank2.timer / tank2.time_uppul) % 10;
	tank2.timer_text[6] = 48 + (int)(tank2.timer / tank2.time_uppul * 10) % 10;
	tank2.timer_text[7] = 48 + (int)(tank2.timer / tank2.time_uppul * 100) % 10;

	tank1.speed_text[7] = 48 + abs((int)tank1.speed);
	tank1.speed_text[9] = 48 + abs((int)(tank1.speed * 10)) % 10;
	tank1.speed_text[11] = ' ';
	tank1.speed_text[12] = ' ';
	if (tank1.bonus_timespeed != 0){
		tank1.speed_text[11] = 48 + (int)(( 800 - tank1.bonus_timespeed + speed.time) / 10 / 20);
		tank1.speed_text[12] = 48 + (int)((800 - tank1.bonus_timespeed + speed.time) / 20) % 10;
	}
	tank2.speed_text[7] = 48 + abs((int)tank2.speed);
	tank2.speed_text[9] = 48 + abs((int)(tank2.speed * 10)) % 10;
	tank2.speed_text[11] = ' ';
	tank2.speed_text[12] = ' ';
	if (tank2.bonus_timespeed != 0){
		tank2.speed_text[11] = 48 + (int)((800 - tank2.bonus_timespeed + speed.time) / 10 / 20);
		tank2.speed_text[12] = 48 + (int)((800 - tank2.bonus_timespeed + speed.time)/20) % 10;
	}

	if (tank1.life_kupol == true){
		char mass[9] = "kupol:";
		mass[7] = 48 + (int)((600 - tank1.bonus_timekupol + life_kupol.time) / 10 / 20);
		mass[8] = 48 + (int)((600 - tank1.bonus_timekupol + life_kupol.time) / 20) % 10;
		Add_text(mass, -200, -320, 9,1.5);
	}
	if (tank2.life_kupol == true){
		char mass[9] = "kupol:";
		mass[7] = 48 + (int)((600 - tank2.bonus_timekupol + life_kupol.time) / 10 / 20);
		mass[8] = 48 + (int)((600 - tank2.bonus_timekupol + life_kupol.time) / 20) % 10;
		Add_text(mass, 210, -320, 9, 1.5);
	}
	if (tank1.teleport == 1){
		char mass[13] = "teleport:";
		mass[10] = 48 + (int)((800 - tank1.timeteleport + teleport.time) / 10 / 20);
		mass[11] = 48 + (int)((800 - tank1.timeteleport + teleport.time) / 20) % 10;
		Add_text(mass, -247, -384, 13, 1.7);
	}
	if (tank2.teleport == 1){
		char mass[13] = "teleport:";
		mass[10] = 48 + (int)((800 - tank2.timeteleport + teleport.time) / 10 / 20);
		mass[11] = 48 + (int)((800 - tank2.timeteleport + teleport.time) / 20) % 10;
		Add_text(mass, 155, -384, 13, 1.7);
	}

	Add_text(tank1.life_text, -390, -320, 9);
	Add_text(tank2.life_text, 10, -320, 9);
	Add_text(tank1.timer_text, -390, -340, 8);
	Add_text(tank2.timer_text, 10, -340, 8);
	Add_text(tank1.speed_text, -390, -360, 13);
	Add_text(tank2.speed_text, 10, -360, 13);
	for (int x = 0; x < 6; x++){
		circle(-339 + x * 15, -377, 7, (tank1.count_pules > x) ? true : false);
		circle(59 + x * 15, -377, 7, (tank2.count_pules > x) ? true : false);
	}

	for (int x = 0; x < tank1.count_mines; x++){
		minadraw(-391 + x * 17, -374);
	}
	for (int x = 0; x < tank2.count_mines; x++){
		minadraw(8 + x * 17, -374);
	}
}
void draw_right_panel(){
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 0.7);
	glVertex2f(400, 300);
	glVertex2f(600, 300);
	glVertex2f(600, -500);
	glVertex2f(400, -400);

	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(490, -400);
	glVertex2f(600, -400);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(600, -370);
	glVertex2f(490, -370);

	glEnd();

	char mass[6] = "  :  ";
	mass[0] = 48 + (int)(main_timer / 20 / 60 / 10);
	mass[1] = 48 + (int)(main_timer / 20 / 60) % 10;
	mass[3] = 48 + (int)((main_timer / 20) % 60) / 10;
	mass[4] = 48 + (int)((main_timer / 20) % 60) % 10;
	Add_text(mass, 500, -395, 5, 2);

	circle(430, 270, 20, true, 0, 1);
	Add_text("p", 424, 261, 1, 3);
	Add_text(" get 3 pules", 450, 255, 14, 1);
	circle(430, 220, 20, true, 0, 1);
	Add_text("sp", 416, 211, 2);
	Add_text(" get 1 pules,\\n + time to new\\n pule", 450, 211, 39, 1);
	circle(430, 170, 20, true, 0, 1);
	Add_text("s", 424, 161, 1, 3);
	Add_text(" get more speed\\n 40sek", 450, 161, 29, 1);
	circle(430, 120, 20, true, 0, 1);
	Add_text("h", 424, 111, 1, 3);
	Add_text(" get random xp\\n 10..20", 450, 111, 23, 1);
	circle(430, 70, 20, true, 0, 1);
	Add_text("k", 424, 61, 1, 3);
	Add_text(" get life kupol\\n 30sek", 450, 61, 25, 1);
	circle(430, 20, 20, true, 0, 1);
	Add_text("b", 424, 11, 1, 3, "red");
	Add_text(" big atom boom!", 450, 11, 20, 1, "red");
	circle(430, -30, 20, true, 0, 1);
	Add_text("t", 424, -41, 1, 3);
	Add_text(" teleport", 450, -41, 10, 1);
	circle(430, -80, 20, true, 0, 1);
	Add_text("m", 424, -91, 1, 3);
	Add_text(" have 3 mines", 450, -91, 15, 1);
}

double antan(double x, double y){
	double z = 0, a = 0;
	if (x < 0 && y > 0){
		z = 90;
		swap(x, y);
	}
	else
	if (x < 0 && y < 0){
		z = 180;
	}
	else
	if (x > 0 && y < 0){
		z = 270;
		swap(x, y);
	}
	for (double i = 0; i < 360; i += 0.001){
		if (tan(i*3.14 / 180) >= abs(y / x)){
			a = i - 0.5;
			break;
		}
	}
	a += z;
	if (x == 0 && y > 0) a = 90;
	if (x == 0 && y < 0) a = 270;
	if (y == 0 && x > 0) a = 0;
	if (y == 0 && x < 0) a = 180;

	return a;
}
