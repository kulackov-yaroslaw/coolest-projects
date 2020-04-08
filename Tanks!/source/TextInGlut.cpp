#include "TextInGluth.h"
#include <GL/glut.h>

void print0(int x, int y, double s);
void print1(int x, int y, double s);
void print2(int x, int y, double s);
void print3(int x, int y, double s);
void print4(int x, int y, double s);
void print5(int x, int y, double s);
void print6(int x, int y, double s);
void print7(int x, int y, double s);
void print8(int x, int y, double s);
void print9(int x, int y, double s);
void print_a(int x, int y, double s);
void print_b(int x, int y, double s);
void print_c(int x, int y, double s);
void print_d(int x, int y, double s);
void print_e(int x, int y, double s);
void print_f(int x, int y, double s);
void print_g(int x, int y, double s);
void print_h(int x, int y, double s);
void print_i(int x, int y, double s);
void print_j(int x, int y, double s);
void print_k(int x, int y, double s);
void print_l(int x, int y, double s);
void print_m(int x, int y, double s);
void print_n(int x, int y, double s);
void print_o(int x, int y, double s);
void print_p(int x, int y, double s);
void print_q(int x, int y, double s);
void print_r(int x, int y, double s);
void print_s(int x, int y, double s);
void print_tt(int x, int y, double s);
void print_u(int x, int y, double s);
void print_v(int x, int y, double s);
void print_w(int x, int y, double s);
void print_x(int x, int y, double s);
void print_x(int x, int y, double s);
void print_y(int x, int y, double s);
void print_z(int x, int y, double s);
void print_s1(int x, int y, double s);
void print_s2(int x, int y, double s);
void print_s3 (int x, int y, double s);
void print_s4(int x, int y, double s);
void print_s5(int x, int y, double s);
void print_s6(int x, int y, double s);
void print_s7(int x, int y, double s);

void Add_text(char a[], int x, int y, int size_of, double size, char color[10]){
	glColor3f(0.0, 0.0, 0.0);
	if (color == "red")
		glColor3f(1.0, 0.0, 0.0);
	if (color == "green")
		glColor3f(0.0, 1.0, 0.0);
	if (color == "blue")
		glColor3f(0.0, 0.0, 1.0);
	if (color == "white")
		glColor3f(1.0, 1.0, 1.0);
	if (color == "yellow")
		glColor3f(1.0, 1.0, 0.0);
	int str = 0;
	for (int i = 0, j = 0; i < size_of; i++){
		if (a[i] == '0') print0(x + j * 8 * size, y - str, size);
		if (a[i] == '1') print1(x + j * 8 * size, y - str, size);
		if (a[i] == '2') print2(x + j* 8 * size, y - str, size);
		if (a[i] == '3') print3(x + j * 8 * size, y - str, size);
		if (a[i] == '4') print4(x + j * 8 * size, y - str, size);
		if (a[i] == '5') print5(x + j * 8 * size, y - str, size);
		if (a[i] == '6') print6(x + j * 8 * size, y - str, size);
		if (a[i] == '7') print7(x + j * 8 * size, y - str, size);
		if (a[i] == '8') print8(x + j * 8 * size, y - str, size);
		if (a[i] == '9') print9(x + j * 8 * size, y - str, size);
		if (a[i] == 'a') print_a(x + j * 8 * size, y - str, size);
		if (a[i] == 'b') print_b(x + j * 8 * size, y - str, size);
		if (a[i] == 'c') print_c(x + j * 8 * size, y - str, size);
		if (a[i] == 'd') print_d(x + j * 8 * size, y - str, size);
		if (a[i] == 'e') print_e(x + j * 8 * size, y - str, size);
		if (a[i] == 'f') print_f(x + j * 8 * size, y - str, size);
		if (a[i] == 'g') print_g(x + j * 8 * size, y - str, size);
		if (a[i] == 'h') print_h(x + j * 8 * size, y - str, size);
		if (a[i] == 'i') print_i(x + j * 8 * size, y - str, size);
		if (a[i] == 'j') print_j(x + j * 8 * size, y - str, size);
		if (a[i] == 'k') print_k(x + j * 8 * size, y - str, size);
		if (a[i] == 'l') print_l(x + j * 8 * size, y - str, size);
		if (a[i] == 'm') print_m(x + j * 8 * size, y - str, size);
		if (a[i] == 'n') print_n(x + j * 8 * size, y - str, size);
		if (a[i] == 'o') print_o(x + j * 8 * size, y - str, size);
		if (a[i] == 'p') print_p(x + j * 8 * size, y - str, size);
		if (a[i] == 'q') print_q(x + j * 8 * size, y - str, size);
		if (a[i] == 'r') print_r(x + j * 8 * size, y - str, size);
		if (a[i] == 's') print_s(x + j * 8 * size, y - str, size);
		if (a[i] == 't') print_tt(x + j * 8 * size, y - str, size);
		if (a[i] == 'u') print_u(x + j * 8 * size, y - str, size);
		if (a[i] == 'v') print_v(x + j * 8 * size, y - str, size);
		if (a[i] == 'w') print_w(x + j * 8 * size, y - str, size);
		if (a[i] == 'x') print_x(x + j * 8 * size, y - str, size);
		if (a[i] == 'y') print_y(x + j * 8 * size, y - str, size);
		if (a[i] == 'z') print_z(x + j * 8 * size, y - str, size);
		if (a[i] == '!') print_s1(x + j * 8 * size, y - str, size);
		if (a[i] == '?') print_s2(x + j * 8 * size, y - str, size);
		if (a[i] == '.') print_s3(x + j * 8 * size, y - str, size);
		if (a[i] == ',') print_s4(x + j * 8 * size, y - str, size);
		if (a[i] == ':') print_s5(x + j * 8 * size, y - str, size);
		if (a[i] == '+') print_s6(x + j * 8 * size, y - str, size);
		//if (a[i] == '-') print_s7(x + j * 8 * size, y - str, size);
		j++;
		if (a[i] == '\\' && a[i + 1] == 'n'){
			str += 12*size;
			i++;
			j = 0;
		}
	}
}

void print0(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x, y + s * 1);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 1);

	glVertex2f(x + s, y + s * 0);
	glVertex2f(x + s, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + 4 * s, y + s * 1);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 1);

	glVertex2f(x + 1 * s, y + s * 7);
	glVertex2f(x + 1 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glVertex2f(x + s, y + s * 3);
	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 2, y + s * 3);

	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 4);

	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 5);

	glEnd();
}
void print1(int x, int y, double s){
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + s);
	glVertex2f(x + 5 * s, y + s);
	glVertex2f(x + 5 * s, y);

	glVertex2f(x + 2 * s, y + s);
	glVertex2f(x + 2 * s, y + 8 * s);
	glVertex2f(x + 3 * s, y + 8 * s);
	glVertex2f(x + 3 * s, y + s);

	glVertex2f(x, y + 6 * s);
	glVertex2f(x, y + 7 * s);
	glVertex2f(x + 2 * s, y + 7 * s);
	glVertex2f(x + 2 * s, y + 6 * s );
	glEnd();
}
void print2(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x, y);
	glVertex2f(x, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s);
	glVertex2f(x, y + s * 2);
	glVertex2f(x + s, y + s * 2);
	glVertex2f(x + s, y + s);

	glVertex2f(x + s, y + s * 2);
	glVertex2f(x + s, y + s * 3);
	glVertex2f(x + 2 * s, y + s * 3);
	glVertex2f(x + 2 * s, y + s * 2);

	glVertex2f(x + 2 * s, y + s * 3);
	glVertex2f(x + 2 * s, y + s * 4);
	glVertex2f(x + 3 * s, y + s * 4);
	glVertex2f(x + 3 * s, y + s * 3);

	glVertex2f(x + 3 * s, y + s * 4);
	glVertex2f(x + 3 * s, y + s * 7);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 8);
	glVertex2f(x + 3 * s, y + s * 8);
	glVertex2f(x + 3 * s, y + s * 7);

	glVertex2f(x, y + s * 6);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 6);

	glEnd();
}
void print3(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x, y + s);
	glVertex2f(x, y + s * 2);
	glVertex2f(x + s, y + s * 2);
	glVertex2f(x + s, y + s);

	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s);

	glVertex2f(x + 3 * s, y + s * 4);
	glVertex2f(x + 3 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 5);

	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glVertex2f(x, y + s * 6);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 6);


	glEnd();
}
void print4(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + 3 * s, y);
	glVertex2f(x + 3 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s * 3);
	glVertex2f(x, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 3);

	glVertex2f(x, y + s * 4);
	glVertex2f(x, y + s * 5);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + s, y + s * 4);

	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + s, y + s * 6);
	glVertex2f(x + 2 * s, y + s * 6);
	glVertex2f(x + 2 * s, y + s * 5);

	glVertex2f(x + 2 * s, y + s * 6);
	glVertex2f(x + 2 * s, y + s * 7);
	glVertex2f(x + 3 * s, y + s * 7);
	glVertex2f(x + 3 * s, y + s * 6);

	glEnd();
}
void print5(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x, y);
	glVertex2f(x, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s);

	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x, y + s * 5);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 5);

	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 8);
	glVertex2f(x + 5 * s, y + s * 8);
	glVertex2f(x + 5 * s, y + s * 7);

	glEnd();
}
void print6(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s);

	glVertex2f(x + 4 * s, y + s * 6);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 6);

	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x + 4 * s, y + s * 1);
	glVertex2f(x + 4 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 1);

	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glEnd();
}
void print7(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + 3 * s, y);
	glVertex2f(x + 3 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x +  s, y + s * 3);
	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 3);

	glVertex2f(x, y + s * 7);
	glVertex2f(x, y + s * 8);
	glVertex2f(x + 3 * s, y + s * 8);
	glVertex2f(x + 3 * s, y + s * 7);


	glEnd();
}
void print8(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s * 1);
	glVertex2f(x, y + s * 4);
	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 1);

	glVertex2f(x + 4 * s, y + s * 1);
	glVertex2f(x + 4 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 1);

	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x, y + s * 5);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 5);

	glVertex2f(x + 1 * s, y + s * 7);
	glVertex2f(x + 1 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 5);


	glEnd();
}
void print9(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s * 1);
	glVertex2f(x, y + s * 2);
	glVertex2f(x + s, y + s * 2);
	glVertex2f(x + s, y + s * 1);

	glVertex2f(x + 4 * s, y + s * 1);
	glVertex2f(x + 4 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 4);
	glVertex2f(x + 5 * s, y + s * 1);

	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x, y + s * 5);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 5);

	glVertex2f(x + 1 * s, y + s * 7);
	glVertex2f(x + 1 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 5);


	glEnd();
}

void print_a(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 4);
	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 5, y + s * 2);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 5, y + s * 0);
	glVertex2f(x + s * 5, y + s * 4);
	glVertex2f(x + s * 6, y + s * 4);
	glVertex2f(x + s * 6, y + s * 0);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 5, y + s * 5);
	glVertex2f(x + s * 5, y + s * 4);

	glVertex2f(x + s * 5, y + s * 5);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 6, y + s * 7);
	glVertex2f(x + s * 6, y + s * 5);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 7);


	glEnd();
}
void print_b(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 5, y + s * 4);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);


	glEnd();
}
void print_c(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 5, y + s * 2);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 6);


	glEnd();
}
void print_d(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 4);
	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 4, y + s * 1);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 0);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glEnd();
}
void print_e(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x + 4 * s, y + s);
	glVertex2f(x + 4 * s, y);

	glVertex2f(x, y + s * 1);
	glVertex2f(x, y + s * 7);
	glVertex2f(x + s, y + s * 7);
	glVertex2f(x + s, y + s * 1);

	glVertex2f(x + 4 * s, y + s * 1);
	glVertex2f(x + 4 * s, y + s * 2);
	glVertex2f(x + 5 * s, y + s * 2);
	glVertex2f(x + 5 * s, y + s * 1);

	glVertex2f(x + s, y + s * 4);
	glVertex2f(x + s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 4);

	glVertex2f(x + 1 * s, y + s * 7);
	glVertex2f(x + 1 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 8);
	glVertex2f(x + 4 * s, y + s * 7);

	glVertex2f(x + 4 * s, y + s * 5);
	glVertex2f(x + 4 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 7);
	glVertex2f(x + 5 * s, y + s * 5);


	glEnd();
}
void print_f(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 0);

	glVertex2f(x + s * 0, y + s * 3);
	glVertex2f(x + s * 0, y + s * 4);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 3);

	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);

	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 6);


	glEnd();
}
void print_g(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 2);
	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 4, y + s * 3);
	glVertex2f(x + s * 4, y + s * 2);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 5);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);


	glEnd();
}
void print_h(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 5, y + s * 4);
	glVertex2f(x + s * 5, y + s * 0);


	glEnd();
}
void print_i(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 2, y + s * 6);
	glVertex2f(x + s * 2, y + s * 1);

	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 0, y + s * 6);
	glVertex2f(x + s * 2, y + s * 6);
	glVertex2f(x + s * 2, y + s * 5);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 2, y + s * 7);


	glEnd();
}
void print_j(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 2, y + s * 0);

	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 2, y + s * 6);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 3, y + s * 1);

	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 3, y + s * 5);

	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 3, y + s * 8);
	glVertex2f(x + s * 3, y + s * 7);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 2);
	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 1);


	glEnd();
}
void print_k(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 2, y + s * 3);

	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 4);

	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 5);

	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 6);

	glVertex2f(x + s * 2, y + s * 2);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 3, y + s * 2);

	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 4, y + s * 1);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 5, y + s * 1);
	glVertex2f(x + s * 5, y + s * 0);


	glEnd();
}
void print_l(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 2, y + s * 0);

	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 7);


	glEnd();
}
void print_m(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 6);

	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 6);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 3, y + s * 3);

	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 3, y + s * 7);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 4, y + s * 6);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 0);

	glEnd();
}
void print_n(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 5, y + s * 6);
	glVertex2f(x + s * 5, y + s * 5);

	glVertex2f(x + s * 5, y + s * 0);
	glVertex2f(x + s * 5, y + s * 5);
	glVertex2f(x + s * 6, y + s * 5);
	glVertex2f(x + s * 6, y + s * 0);


	glEnd();
}
void print_o(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);


	glEnd();
}
void print_p(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 3);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);

	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 4);


	glEnd();
}
void print_q(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 4);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 4);

	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 3);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 0);


	glEnd();
}
void print_r(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);

	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 5);

	glEnd();
}
void print_s(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 2);
	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 5, y + s * 4);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 6);

	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 5);

	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 4, y + s * 7);


	glEnd();
}
void print_tt(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 2, y + s * 1);

	glVertex2f(x + s * 2, y + s * 0);
	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 5, y + s * 2);
	glVertex2f(x + s * 5, y + s * 1);

	glVertex2f(x + s * 0, y + s * 4);
	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);


	glEnd();
}
void print_u(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 4, y + s * 1);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 0);


	glEnd();
}
void print_v(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 5);

	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 2, y + s * 2);

	glVertex2f(x + s * 2, y + s * 0);
	glVertex2f(x + s * 2, y + s * 2);
	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 2);

	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 5);

	glEnd();
}
void print_w(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 2, y + s * 0);

	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 3, y + s * 8);
	glVertex2f(x + s * 3, y + s * 1);

	glVertex2f(x + s * 3, y + s * 0);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 1);


	glEnd();
}
void print_x(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 0, y + s * 6);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 1, y + s * 8);
	glVertex2f(x + s * 1, y + s * 6);

	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 1);

	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 2, y + s * 6);
	glVertex2f(x + s * 2, y + s * 5);

	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 3);

	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 4, y + s * 3);
	glVertex2f(x + s * 4, y + s * 1);

	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 5);

	glVertex2f(x + s * 4, y + s * 0);
	glVertex2f(x + s * 4, y + s * 1);
	glVertex2f(x + s * 5, y + s * 1);
	glVertex2f(x + s * 5, y + s * 0);

	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 4, y + s * 8);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 5, y + s * 6);

	glEnd();
}
void print_y(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 0);

	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 1, y + s * 5);

	glVertex2f(x + s * 1, y + s * 1);
	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 1);

	glVertex2f(x + s * 1, y + s * 4);
	glVertex2f(x + s * 1, y + s * 5);
	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 2, y + s * 4);

	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 3, y + s * 4);
	glVertex2f(x + s * 3, y + s * 3);

	glVertex2f(x + s * 3, y + s * 4);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 5);

	glEnd();
}
void print_z(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 0);
	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 6, y + s * 1);
	glVertex2f(x + s * 6, y + s * 0);

	glVertex2f(x + s * 0, y + s * 1);
	glVertex2f(x + s * 0, y + s * 2);
	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 1);

	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 4);
	glVertex2f(x + s * 3, y + s * 4);
	glVertex2f(x + s * 3, y + s * 3);

	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 1, y + s * 3);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 2, y + s * 2);

	glVertex2f(x + s * 3, y + s * 4);
	glVertex2f(x + s * 3, y + s * 5);
	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 4);

	glVertex2f(x + s * 4, y + s * 5);
	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 5, y + s * 6);
	glVertex2f(x + s * 5, y + s * 5);

	glVertex2f(x + s * 5, y + s * 6);
	glVertex2f(x + s * 5, y + s * 8);
	glVertex2f(x + s * 6, y + s * 7);
	glVertex2f(x + s * 6, y + s * 8);

	glVertex2f(x + s * 0, y + s * 7);
	glVertex2f(x + s * 0, y + s * 8);
	glVertex2f(x + s * 6, y + s * 8);
	glVertex2f(x + s * 6, y + s * 7);


	glEnd();
}

void print_s1(int x, int y, double s){
	glBegin(GL_QUADS);
	glVertex2f(x + s * 2, y);
	glVertex2f(x + s * 2, y + s);
	glVertex2f(x + 3 * s, y + s);
	glVertex2f(x + 3 * s, y);

	glVertex2f(x + s * 2, y + s * 2);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 3, y + s * 8);
	glVertex2f(x + s * 3, y + s * 2);

	glEnd();
}
void print_s2(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 2, y + s * 0);
	glVertex2f(x + s * 2, y + s * 1);
	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 0);

	glVertex2f(x + s * 2, y + s * 2);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 3, y + s * 2);

	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 3, y + s * 4);
	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 3);

	glVertex2f(x + s * 3, y + s * 6);
	glVertex2f(x + s * 3, y + s * 7);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 4, y + s * 6);

	glVertex2f(x + s * 4, y + s * 4);
	glVertex2f(x + s * 4, y + s * 6);
	glVertex2f(x + s * 5, y + s * 6);
	glVertex2f(x + s * 5, y + s * 4);

	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 8);
	glVertex2f(x + s * 3, y + s * 8);
	glVertex2f(x + s * 3, y + s * 7);

	glVertex2f(x + s * 1, y + s * 6);
	glVertex2f(x + s * 1, y + s * 7);
	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 2, y + s * 6);


	glEnd();
}
void print_s3(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 1, y + s * 0);
	glVertex2f(x + s * 1, y + s * 2);
	glVertex2f(x + s * 3, y + s * 2);
	glVertex2f(x + s * 3, y + s * 0);

	glEnd();
}
void print_s4(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 1, y - s * 2);
	glVertex2f(x + s * 1, y - s * 3);
	glVertex2f(x + s * 2, y - s * 3);
	glVertex2f(x + s * 2, y - s * 2);

	glVertex2f(x + s * 2, y - s * 2);
	glVertex2f(x + s * 2, y + s * 3);
	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 3, y - s * 2);

	glVertex2f(x + s * 3, y + s * 1);
	glVertex2f(x + s * 3, y + s * 3);
	glVertex2f(x + s * 4, y + s * 3);
	glVertex2f(x + s * 4, y + s * 1);

	glEnd();
}
void print_s5(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 2, y + s * 0);
	glVertex2f(x + s * 2, y + s * 2);
	glVertex2f(x + s * 4, y + s * 2);
	glVertex2f(x + s * 4, y + s * 0);

	glVertex2f(x + s * 2, y + s * 5);
	glVertex2f(x + s * 2, y + s * 7);
	glVertex2f(x + s * 4, y + s * 7);
	glVertex2f(x + s * 4, y + s * 5);

	glEnd();
}
void print_s6(int x, int y, double s){
	glBegin(GL_QUADS);

	glVertex2f(x + s * 0, y + s * 3);
	glVertex2f(x + s * 0, y + s * 5);
	glVertex2f(x + s * 7, y + s * 5);
	glVertex2f(x + s * 7, y + s * 3);

	glVertex2f(x + s * 3, y + s * 0);
	glVertex2f(x + s * 3, y + s * 7);
	glVertex2f(x + s * 5, y + s * 7);
	glVertex2f(x + s * 5, y + s * 0);

	glEnd();
}

