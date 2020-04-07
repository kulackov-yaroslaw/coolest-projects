//  Kulakov Yaroslav. 18:30/21/07/2015  //
//                                                     Ñàïåð                                                      //
#include<gl/glut.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

int bombs, flags, xx = -1, yy = -1, firststep = 0, laststep = 0, height, width, hard;
struct a{
	int c;
	bool f,flag;
}a[50][35];

void drawCircle(float x, float y, float r, int amountSegments = 30);

void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (int x = 0; x < width*20; x += 20){
		glVertex2f(x, 0);
		glVertex2f(x, height*20);
	}
	for (int y = 0; y < height*20; y += 20){
		glVertex2f(0, y);
		glVertex2f(width*20, y);
	}
	glEnd();
	for (int x = 0, k=0; x < width*20; x += 20){
		for (int y = 0; y < height*20; y += 20){
			glBegin(GL_QUADS);
			if (a[x/20][y/20].f == false)
				glColor3f(0.75, 0.75, 0.75);
			else {
				k = 4;
				if (a[x / 20][y / 20].c == -1){
					glColor3f(0.5, 0.5, 0.5);
					k = 0;
				}
				if (a[x / 20][y / 20].c == 0)
					glColor3f(0.97, 0.97, 0.97);
				if (a[x / 20][y / 20].c == 1)
					glColor3f(0.0, 0.0, 0.7);
				if (a[x / 20][y / 20].c == 2)
					glColor3f(0.0, 0.7, 0.0);
				if (a[x / 20][y / 20].c == 3)
					glColor3f(0.7, 0.0, 0.0);
				if (a[x / 20][y / 20].c == 4)
					glColor3f(0.5, 0.5, 0.0);
				if (a[x / 20][y / 20].c == 5)
					glColor3f(0.0, 0.5, 0.5);
				if (a[x / 20][y / 20].c == 6)
					glColor3f(0.5, 0.0, 0.5);
				if (a[x / 20][y / 20].c == 7)
					glColor3f(1.0, 0.5, 0.0);
				if (a[x / 20][y / 20].c == 8)
					glColor3f(0.0, 1.0, 0.5);
			}
			glVertex2f(x + 1+k, y + 1+k);
			glVertex2f(x + 19-k, y + 1+k);
			glVertex2f(x + 19-k, y + 19-k);
			glVertex2f(x + 1+k, y + 19-k);
			glEnd();
			k = 0;
			if ((a[x / 20][y / 20].f == true || laststep == 1) && a[x / 20][y / 20].c == -1 && a[x / 20][y / 20].flag == false){
				glColor3f(0.0, 0.0, 0.0);
				drawCircle(x + 10, y + 10, 5);
			}
			if (a[x / 20][y / 20].flag == true && laststep == 1 && a[x / 20][y / 20].c > 0){
				glColor3f(0.0, 0.0, 0.0);
				drawCircle(x + 10, y + 10, 5, 2);
			}
			if (a[x / 20][y / 20].flag == true){
				glColor3f(0.0, 0.0, 0.0);
				drawCircle(x + 10, y + 10, 5,3);
			}
		}
	}
	glFlush();
}

void Timer(int){
	if (laststep==0)
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			if (a[x][y].c == -1 && a[x][y].f == true)
				laststep = 1;
		}
	}
	if (firststep == 1){
		system("cls");
		cout << flags;
		for (int x = 0, x1, y1; x < bombs; x++){
			do{
				x1 = rand() % width;
				y1 = rand() % height;
			} while (a[x1][y1].c == -1 || a[x1][y1].f == true);
			a[x1][y1].c = -1;
		}
		for (int x = 0; x < width; x++){
			for (int y = 0; y < height; y++){
				if (a[x][y].c != -1){
					if (a[x - 1][y].c == -1 && x > 0)
						a[x][y].c++;
					if (a[x - 1][y + 1].c == -1 && x > 0 && y < height-1)
						a[x][y].c++;
					if (a[x][y + 1].c == -1 && y < height-1)
						a[x][y].c++;
					if (a[x + 1][y + 1].c == -1 && x < width && y < height-1)
						a[x][y].c++;
					if (a[x + 1][y].c == -1 && x < width)
						a[x][y].c++;
					if (a[x + 1][y - 1].c == -1 && x < width && y > 0)
						a[x][y].c++;
					if (a[x][y - 1].c == -1 && y > 0)
						a[x][y].c++;
					if (a[x - 1][y - 1].c == -1 && x > 0 && y > 0)
						a[x][y].c++;
				}
			}
		}
		firststep=2;
	}
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			if (a[x][y].c != -1){
				int s = 0;
				if (a[x - 1][y].f == true && a[x - 1][y].flag == false && a[x - 1][y].c == 0 && x > 0)
					s++;
				if (a[x - 1][y + 1].f == true && a[x - 1][y + 1].flag == false && a[x - 1][y + 1].c == 0 && x > 0 && y < height-1)
					s++;
				if (a[x][y + 1].f == true && a[x][y + 1].flag == false && a[x][y + 1].c == 0 && y < height-1)
					s++;
				if (a[x + 1][y + 1].f == true && a[x + 1][y + 1].flag == false && a[x + 1][y + 1].c == 0 && x < width && y < height - 1)
					s++;
				if (a[x + 1][y].f == true && a[x + 1][y].flag == false && a[x + 1][y].c == 0 && x < width)
					s++;
				if (a[x + 1][y - 1].f == true && a[x + 1][y - 1].flag == false && a[x + 1][y - 1].c == 0 && x < width && y > 0)
					s++;
				if (a[x][y - 1].f == true && a[x][y - 1].flag == false && a[x][y - 1].c == 0 && y > 0)
					s++;
				if (a[x - 1][y - 1].f == true && a[x - 1][y - 1].flag == false && a[x - 1][y - 1].c == 0 && x > 0 && y > 0)
					s++;
				if (s > 0 && a[x][y].flag == false)
					a[x][y].f = true;
			}
		}
	}
	if (laststep == 1){
		system("cls");
		cout << "you lose";
	}
	if (laststep != 2)
		Draw();
	if (laststep == 1)
		laststep = 2;
	if (flags == 0 && laststep < 2){
		int s = 0;
		for (int x = 0; x < width; x++){
			for (int y = 0; y < height; y++){
				if (a[x][y].f == false)
					s++;
			}
		}
		if (s == bombs){
			system("cls");
			cout << "you win!";
			laststep = 2;
		}
	}
	glutTimerFunc(50, Timer, 0);
}

void MousePressedOnse(int button, int state, int x, int y){
	if (state == GLUT_DOWN && laststep < 2){
		xx = x / 20;
		yy = (height * 20 - y) / 20;
		if (button == GLUT_LEFT_BUTTON){
			if (a[xx][yy].flag == true){
				a[xx][yy].flag = false;
				flags++;
				system("cls");
				cout << flags;
			}
			if (a[xx][yy].c > 0 && a[xx][yy].f == true){
				if (a[xx - 1][yy].flag !=true && xx > 0)
					a[xx - 1][yy].f = true;
				if (a[xx - 1][yy + 1].flag != true && xx > 0 && yy < height * 20-1)
					a[xx - 1][yy + 1].f = true;
				if (a[xx][yy + 1].flag != true && yy < height * 20-1)
					a[xx][yy + 1].f = true;
				if (a[xx + 1][yy + 1].flag != true && xx <width*20 && yy < height * 20-1)
					a[xx + 1][yy + 1].f = true;
				if (a[xx + 1][yy].flag != true && xx < width * 20)
					a[xx + 1][yy].f = true;
				if (a[xx + 1][yy - 1].flag != true && xx < width * 20 && yy > 0)
					a[xx + 1][yy - 1].f = true;
				if (a[xx][yy - 1].flag != true && yy > 0)
					a[xx][yy - 1].f = true;
				if (a[xx - 1][yy - 1].flag != true && xx > 0 && yy > 0)
					a[xx - 1][yy - 1].f = true;
			}
			a[xx][yy].f = true;
			firststep++;
		}
		if (button == GLUT_RIGHT_BUTTON && a[xx][yy].f == false){
			if (a[xx][yy].flag == false){
				if (flags > 0){
					a[xx][yy].flag = true;
					flags--;
					system("cls");
					cout << flags;
				}
			}
			else{
				a[xx][yy].flag = false;
				flags++;
				system("cls");
				cout << flags;
			}
		}
	}
}

int main(int argc, char ** argv) {
	srand(time(NULL));
	cout << "width(1..50), height(1..35), hard(0..100)% ";
	cin >> width >> height >> hard;
	if (width > 50)
		width = 50;
	if (width < 1)
		width = 1;
	if (height > 35)
		height = 35;
	if (height < 1)
		height = 1;
	if (hard > 99)
		hard = 99;
	if (hard < 0)
		hard = 0;
	hard /= 6;
	bombs = width*height*hard/100;
	flags = bombs;
	system("cls");
	cout << flags<< " bombs / " << width*height;
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			a[x][y].f = false;
			a[x][y].flag = false;
			a[x][y].c = 0;
		}
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width * 20, height * 20);
	glutInitWindowPosition((1100-width*20)/2+60, (750-height*20)/2);
	glutCreateWindow("Càïåð");
	glClearColor(0.97, 0.97, 0.97, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width*20, 0,height*20, 0, 400.0);
	glutDisplayFunc(Draw);
	glutMouseFunc(MousePressedOnse);
	glutTimerFunc(50, Timer, 0);
	glutMainLoop();
	return 0;
}

void drawCircle(float x, float y, float r, int amountSegments)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}
