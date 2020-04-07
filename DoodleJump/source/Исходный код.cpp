// Yaroslav 11.08.2015
#include<gl/glut.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace  std;
int xx = 0, yy = 0,h=0,v=0,m=0,xm=0,xml=1,l=450;
const int N = 12;
struct plat{
	int X;
	int Y;
} p[N];
void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	//glRotated(0, 0, 1, 0);
	glBegin(GL_QUADS);
	for (int x(0); x < N; x++){
		glVertex2f(p[x].X, p[x].Y);
		glVertex2f(p[x].X, p[x].Y+20);
		glVertex2f(p[x].X+70, p[x].Y+20);
		glVertex2f(p[x].X+70, p[x].Y);
	}
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(xx, yy);
	glVertex2f(50 + xx, yy);
	glVertex2f(50 + xx, 50 + yy);
	glVertex2f(xx, 50 + yy);
	glEnd();
	glFlush();
}
void Timer(int){
	for (int x(0),y; x < N; x++){
		y = yy;
		while (y > yy + v&&v<0){
			if (y == p[x].Y+20 && xx+50>p[x].X && xx<p[x].X+70){
				h = y;
				yy = y-25;
				x = N;
				v = 25;
			}
			y--;
		}
	}
	for (int x(0); x < N; x++){
		if (yy == p[x].Y + 20 && (xx + 50 < p[x].X || xx > p[x].X + 70) && v<0){
			h=0;
			x = N;
		}
	}
	if (yy>350 && v>0){
		h = 0;
		yy = 350;
		for (int x(0); x < N; x++){
			p[x].Y -= v;
		}
		l += v;
	}
	if (yy < 0){
		h = 0;
		yy = 0;
	}
	if (yy == 0){
		system("cls");
		cout << l;
	}
	if (yy == h)v = 25+m;
	yy += v;
	v-=2;
	if (v>25)
	m = 0;
	if (xx + 50 < 0) xx = 400;
	if (xx > 400)  xx = 0;
	for (int x(0); x < N; x++){
		if (p[x].Y+20 < 0){
			p[x].Y = 581;
			p[x].X = rand() % 331;
		}
	}
	Draw();
	glutTimerFunc(50, Timer, 0);
}

void MM(int x, int y){
	//xx = x*2-25;
}
void key(int key, int x, int y){
	if (key == 100) xx-=10;
	if (key == 102)xx+=10;
	if (key == 101) m = 10;
	//if (key == 103);
}
int main(int argc, char** argv)
{
	srand(time(0));
	for (int x = 0; x < N; x++){
		p[x].X = rand() % 331;
		p[x].Y = rand() % 581;
	}
	for (int x = 0; x < 5; x++){
		p[x].Y = 130 * x;
	}
	p[0].Y = -21;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 300);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Doodle_Jump");
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,400.0,0,600.0,0,400.0);
	glutDisplayFunc(Draw);
	glutPassiveMotionFunc(MM);
	glutSpecialFunc(key);
	glutTimerFunc(50, Timer, 0);
	glutMainLoop();
	return 0;
}
