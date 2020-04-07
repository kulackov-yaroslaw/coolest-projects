//14.02.2015
#include<gl/glut.h>
#include<iostream>
using namespace std;

int xx,yy;
bool temp=false;
struct a{
	int f;
}a[40][30],b[40][30];
void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	for (int x = 0; x < 800; x += 20){
		for (int y = 0; y < 600; y += 20){
			if (a[x/20][y/20].f == 1){
				glColor3f(0.3, 0.3, 0.3);
			}
			glVertex2f(x, y);
			glVertex2f(x + 19, y);
			glVertex2f(x + 19, y + 19);
			glVertex2f(x, y + 19);
			glColor3f(0.7, 0.7, 0.7);
		}
	}
	glEnd();
	glFlush();

}

void MM(int button, int state, int x, int y){
	if (state == GLUT_DOWN){
		xx = x / 20 * 20;
		yy = (600 - y) / 20 * 20;
		if (a[xx / 20][yy / 20].f == 1){
			a[xx / 20][yy / 20].f = 0;
			b[xx / 20][yy / 20].f = 0;
		}
		else{
			a[xx / 20][yy / 20].f = 1;
			b[xx / 20][yy / 20].f = 1;
		}
	}
}

void key(unsigned char key, int x, int y){
	if (key == ' ') temp=true;
}
void Timer(int){
	int s = 0;
	if (temp == true){
		for (int x = 1; x < 39; x++){
			for (int y = 1; y < 29; y++){
				if (a[x - 1][y].f == 1)
					s++;
				if (a[x - 1][y+1].f == 1)
					s++;
				if (a[x][y+1].f == 1)
					s++;
				if (a[x + 1][y+1].f == 1)
					s++;
				if (a[x + 1][y].f == 1)
					s++;
				if (a[x + 1][y-1].f == 1)
					s++;
				if (a[x][y-1].f == 1)
					s++;
				if (a[x - 1][y-1].f == 1)
					s++;
				if (a[x][y].f == 1 && (s < 2 || s > 3))
					b[x][y].f = 0;
				if (a[x][y].f == 0 && s == 3)
					b[x][y].f = 1;
				s = 0;
			}
		}
		for (int x = 1; x < 39; x++){
			for (int y = 1; y < 29; y++){
				a[x][y].f = b[x][y].f;
			}
		}
		temp = false;
	}
    Draw();
    glutTimerFunc(50, Timer, 0);
}

int main(int argc, char ** argv) {
	for (int x = 0; x < 40; x++){
		for (int y = 0; y < 30; y++){
			a[x][y].f = 0;
			b[x][y].f = 0;
		}
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GameLife");
	glClearColor(0.0, 0.0, 0.4, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800.0, 0, 600.0, 0, 400.0);
	glutDisplayFunc(Draw);
	glutMouseFunc(MM);
	glutKeyboardFunc(key);
	glutTimerFunc(50, Timer, 0);
	glutMainLoop();
	return 0;
}