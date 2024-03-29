#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include <GL/freeglut.h>
using namespace std;
#define d 20.0	// 공간 20x20
#define PI 3.141592
enum {
	GLUT_WHEEL_UP = 3,
	GLUT_WHEEL_DOWN = 4
};
float xx = 0;
float yy = 0;
float zz = 0;
int t = 0;

float camX = 0.0;
float camY = 0.0;
float camZ = 0.0;

float radius;
float phi;
float theta;

int ww = 650, wh = 550;
float last_x, last_y;
float hv;
float fovy = 60;

int click = 0; // 시점 변화
int move_count = 0;

GLfloat vertices_point[][3] = {
	{ 3, -1, -1 },
	{ 3, -1, -0.9 },
	{ 5, -1, -0.9 },
	{ 5, -1, -1 },
	{ 3, -3, -1 },
	{ 3, -3, -0.9 },
	{ 5, -3, -0.9 },
	{ 5, -3, -1 }
};

GLfloat vertices1[][3] = {
	{ -1, 11, -1 },
	{ -1, 11, 1 },
	{ 1, 11, 1 },
	{ 1, 11, -1 },
	{ -1, 9, -1 },
	{ -1, 9, 1 },
	{ 1, 9, 1 },
	{ 1, 9, -1 }
};

GLfloat vertices2[][3] = {
	{ -9, 9, -1 },
	{ -9, 9, 1 },
	{ -7, 9, 1 },
	{ -7, 9, -1 },
	{ -9, 7, -1 },
	{ -9, 7, 1 },
	{ -7, 7, 1 },
	{ -7, 7, -1 }
};

GLfloat vertices3[][3] = {
	{ 9, 9, -1 },
	{ 9, 9, 1 },
	{ 11, 9, 1 },
	{ 11, 9, -1 },
	{ 9, 7, -1 },
	{ 9, 7, 1 },
	{ 11, 7, 1 },
	{ 11, 7, -1 }
};

GLfloat vertices4[][3] = {
	{ -5, 7, -1 },
	{ -5, 7, 1 },
	{ -3, 7, 1 },
	{ -3, 7, -1 },
	{ -5, 5, -1 },
	{ -5, 5, 1 },
	{ -3, 5, 1 },
	{ -3, 5, -1 }
};

GLfloat vertices5[][3] = {
	{ 5, 7, -1 },
	{ 5, 7, 1 },
	{ 7, 7, 1 },
	{ 7, 7, -1 },
	{ 5, 5, -1 },
	{ 5, 5, 1 },
	{ 7, 5, 1 },
	{ 7, 5, -1 }
};

GLfloat vertices6[][3] = {
	{ -11, 5, -1 },
	{ -11, 5, 1 },
	{ -9, 5, 1 },
	{ -9, 5, -1 },
	{ -11, 3, -1 },
	{ -11, 3, 1 },
	{ -9, 3, 1 },
	{ -9, 3, -1 }
};

GLfloat vertices7[][3] = {
	{ 7, 5, -1 },
	{ 7, 5, 1 },
	{ 9, 5, 1 },
	{ 9, 5, -1 },
	{ 7, 3, -1 },
	{ 7, 3, 1 },
	{ 9, 3, 1 },
	{ 9, 3, -1 }
};

GLfloat vertices8[][3] = {
	{ -3, 3, -1 },
	{ -3, 3, 1 },
	{ -1, 3, 1 },
	{ -1, 3, -1 },
	{ -3, 1, -1 },
	{ -3, 1, 1 },
	{ -1, 1, 1 },
	{ -1, 1, -1 }
};

GLfloat vertices9[][3] = {
	{ 11, 3, -1 },
	{ 11, 3, 1 },
	{ 13, 3, 1 },
	{ 13, 3, -1 },
	{ 11, 1, -1 },
	{ 11, 1, 1 },
	{ 13, 1, 1 },
	{ 13, 1, -1 }
};

GLfloat vertices10[][3] = {
	{ -13, 1, -1 },
	{ -13, 1, 1 },
	{ -11, 1, 1 },
	{ -11, 1, -1 },
	{ -13, -1, -1 },
	{ -13, -1, 1 },
	{ -11, -1, 1 },
	{ -11, -1, -1 }
};

GLfloat vertices11[][3] = {
	{ 3, 1, -1 },
	{ 3, 1, 1 },
	{ 5, 1, 1 },
	{ 5, 1, -1 },
	{ 3, -1, -1 },
	{ 3, -1, 1 },
	{ 5, -1, 1 },
	{ 5, -1, -1 }
};

GLfloat vertices12[][3] = {
	{ -9, -1, -1 },
	{ -9, -1, 1 },
	{ -7, -1, 1 },
	{ -7, -1, -1 },
	{ -9, -3, -1 },
	{ -9, -3, 1 },
	{ -7, -3, 1 },
	{ -7, -3, -1 }
};

GLfloat vertices13[][3] = {
	{ 9, -1, -1 },
	{ 9, -1, 1 },
	{ 11, -1, 1 },
	{ 11, -1, -1 },
	{ 9, -3, -1 },
	{ 9, -3, 1 },
	{ 11, -3, 1 },
	{ 11, -3, -1 }
};

GLfloat vertices14[][3] = {
	{ -5, -3, -1 },
	{ -5, -3, 1 },
	{ -3, -3, 1 },
	{ -3, -3, -1 },
	{ -5, -5, -1 },
	{ -5, -5, 1 },
	{ -3, -5, 1 },
	{ -3, -5, -1 }
};

GLfloat vertices15[][3] = {
	{ 5, -5, -1 },
	{ 5, -5, 1 },
	{ 7, -5, 1 },
	{ 7, -5, -1 },
	{ 5, -7, -1 },
	{ 5, -7, 1 },
	{ 7, -7, 1 },
	{ 7, -7, -1 }
};

GLfloat vertices16[][3] = {
	{ 11, -5, -1 },
	{ 11, -5, 1 },
	{ 13, -5, 1 },
	{ 13, -5, -1 },
	{ 11, -7, -1 },
	{ 11, -7, 1 },
	{ 13, -7, 1 },
	{ 13, -7, -1 }
};

GLfloat vertices17[][3] = {
	{ -11, -7, -1 },
	{ -11, -7, 1 },
	{ -9, -7, 1 },
	{ -9, -7, -1 },
	{ -11, -9, -1 },
	{ -11, -9, 1 },
	{ -9, -9, 1 },
	{ -9, -9, -1 }
};

GLfloat vertices18[][3] = {
	{ 7, -7, -1 },
	{ 7, -7, 1 },
	{ 9, -7, 1 },
	{ 9, -7, -1 },
	{ 7, -9, -1 },
	{ 7, -9, 1 },
	{ 9, -9, 1 },
	{ 9, -9, -1 }
};

GLfloat vertices19[][3] = {
	{ -7, -9, -1 },
	{ -7, -9, 1 },
	{ -5, -9, 1 },
	{ -5, -9, -1 },
	{ -7, -11, -1 },
	{ -7, -11, 1 },
	{ -5, -11, 1 },
	{ -5, -11, -1 }
};

GLfloat vertices20[][3] = {
	{ 1, -9, -1 },
	{ 1, -9, 1 },
	{ 3, -9, 1 },
	{ 3, -9, -1 },
	{ 1, -11, -1 },
	{ 1, -11, 1 },
	{ 3, -11, 1 },
	{ 3, -11, -1 }
};

typedef struct {
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shininess;
} materialStruct;

materialStruct ball
= { 1.0, 0.2, 0.2, 1.0,
1.0, 0.2, 0.2, 1.0,
1.0, 0.2, 0.2, 1.0, 50.0 };

void materials(materialStruct *material) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material->specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);
}

void timerp();

void setLighting() {
	float light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	float light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	float light_specular[] = { 1.0, 1.0, 1.0, 0.0 };
	float light_pos[] = { -1.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void drawObj()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBegin(GL_QUADS);
	glColor4f(0.0, 0.0, 1, 0.9);
	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[2]);
	glVertex3fv(vertices1[1]);

	glVertex3fv(vertices1[1]);
	glVertex3fv(vertices1[2]);
	glVertex3fv(vertices1[6]);
	glVertex3fv(vertices1[5]);

	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[6]);
	glVertex3fv(vertices1[2]);

	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[4]);

	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[4]);
	glVertex3fv(vertices1[5]);
	glVertex3fv(vertices1[6]);

	glVertex3fv(vertices1[4]);
	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[1]);
	glVertex3fv(vertices1[5]);
	//1번

	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[2]);
	glVertex3fv(vertices2[1]);

	glVertex3fv(vertices2[1]);
	glVertex3fv(vertices2[2]);
	glVertex3fv(vertices2[6]);
	glVertex3fv(vertices2[5]);

	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[6]);
	glVertex3fv(vertices2[2]);

	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[4]);

	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[4]);
	glVertex3fv(vertices2[5]);
	glVertex3fv(vertices2[6]);

	glVertex3fv(vertices2[4]);
	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[1]);
	glVertex3fv(vertices2[5]);

	//2번

	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[2]);
	glVertex3fv(vertices3[1]);

	glVertex3fv(vertices3[1]);
	glVertex3fv(vertices3[2]);
	glVertex3fv(vertices3[6]);
	glVertex3fv(vertices3[5]);

	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[6]);
	glVertex3fv(vertices3[2]);

	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[4]);

	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[4]);
	glVertex3fv(vertices3[5]);
	glVertex3fv(vertices3[6]);

	glVertex3fv(vertices3[4]);
	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[1]);
	glVertex3fv(vertices3[5]);

	// 3번


	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[2]);
	glVertex3fv(vertices4[1]);

	glVertex3fv(vertices4[1]);
	glVertex3fv(vertices4[2]);
	glVertex3fv(vertices4[6]);
	glVertex3fv(vertices4[5]);

	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[6]);
	glVertex3fv(vertices4[2]);

	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[4]);

	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[4]);
	glVertex3fv(vertices4[5]);
	glVertex3fv(vertices4[6]);

	glVertex3fv(vertices4[4]);
	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[1]);
	glVertex3fv(vertices4[5]);

	// 4

	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[2]);
	glVertex3fv(vertices5[1]);

	glVertex3fv(vertices5[1]);
	glVertex3fv(vertices5[2]);
	glVertex3fv(vertices5[6]);
	glVertex3fv(vertices5[5]);

	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[6]);
	glVertex3fv(vertices5[2]);

	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[4]);

	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[4]);
	glVertex3fv(vertices5[5]);
	glVertex3fv(vertices5[6]);

	glVertex3fv(vertices5[4]);
	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[1]);
	glVertex3fv(vertices5[5]);

	// 5


	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[2]);
	glVertex3fv(vertices6[1]);

	glVertex3fv(vertices6[1]);
	glVertex3fv(vertices6[2]);
	glVertex3fv(vertices6[6]);
	glVertex3fv(vertices6[5]);

	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[6]);
	glVertex3fv(vertices6[2]);

	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[4]);

	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[4]);
	glVertex3fv(vertices6[5]);
	glVertex3fv(vertices6[6]);

	glVertex3fv(vertices6[4]);
	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[1]);
	glVertex3fv(vertices6[5]);

	// 6

	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[2]);
	glVertex3fv(vertices7[1]);

	glVertex3fv(vertices7[1]);
	glVertex3fv(vertices7[2]);
	glVertex3fv(vertices7[6]);
	glVertex3fv(vertices7[5]);

	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[6]);
	glVertex3fv(vertices7[2]);

	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[4]);

	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[4]);
	glVertex3fv(vertices7[5]);
	glVertex3fv(vertices7[6]);

	glVertex3fv(vertices7[4]);
	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[1]);
	glVertex3fv(vertices7[5]);

	// 7

	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[2]);
	glVertex3fv(vertices8[1]);

	glVertex3fv(vertices8[1]);
	glVertex3fv(vertices8[2]);
	glVertex3fv(vertices8[6]);
	glVertex3fv(vertices8[5]);

	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[6]);
	glVertex3fv(vertices8[2]);

	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[4]);

	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[4]);
	glVertex3fv(vertices8[5]);
	glVertex3fv(vertices8[6]);

	glVertex3fv(vertices8[4]);
	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[1]);
	glVertex3fv(vertices8[5]);

	// 8

	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[2]);
	glVertex3fv(vertices9[1]);

	glVertex3fv(vertices9[1]);
	glVertex3fv(vertices9[2]);
	glVertex3fv(vertices9[6]);
	glVertex3fv(vertices9[5]);

	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[6]);
	glVertex3fv(vertices9[2]);

	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[4]);

	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[4]);
	glVertex3fv(vertices9[5]);
	glVertex3fv(vertices9[6]);

	glVertex3fv(vertices9[4]);
	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[1]);
	glVertex3fv(vertices9[5]);

	// 9

	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[2]);
	glVertex3fv(vertices10[1]);

	glVertex3fv(vertices10[1]);
	glVertex3fv(vertices10[2]);
	glVertex3fv(vertices10[6]);
	glVertex3fv(vertices10[5]);

	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[6]);
	glVertex3fv(vertices10[2]);

	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[4]);

	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[4]);
	glVertex3fv(vertices10[5]);
	glVertex3fv(vertices10[6]);

	glVertex3fv(vertices10[4]);
	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[1]);
	glVertex3fv(vertices10[5]);

	// 10

	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[2]);
	glVertex3fv(vertices11[1]);

	glVertex3fv(vertices11[1]);
	glVertex3fv(vertices11[2]);
	glVertex3fv(vertices11[6]);
	glVertex3fv(vertices11[5]);

	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[6]);
	glVertex3fv(vertices11[2]);

	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[4]);

	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[4]);
	glVertex3fv(vertices11[5]);
	glVertex3fv(vertices11[6]);

	glVertex3fv(vertices11[4]);
	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[1]);
	glVertex3fv(vertices11[5]);

	// 11

	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[2]);
	glVertex3fv(vertices12[1]);

	glVertex3fv(vertices12[1]);
	glVertex3fv(vertices12[2]);
	glVertex3fv(vertices12[6]);
	glVertex3fv(vertices12[5]);

	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[6]);
	glVertex3fv(vertices12[2]);

	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[4]);

	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[4]);
	glVertex3fv(vertices12[5]);
	glVertex3fv(vertices12[6]);

	glVertex3fv(vertices12[4]);
	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[1]);
	glVertex3fv(vertices12[5]);

	// 12

	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[2]);
	glVertex3fv(vertices13[1]);

	glVertex3fv(vertices13[1]);
	glVertex3fv(vertices13[2]);
	glVertex3fv(vertices13[6]);
	glVertex3fv(vertices13[5]);

	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[6]);
	glVertex3fv(vertices13[2]);

	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[4]);

	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[4]);
	glVertex3fv(vertices13[5]);
	glVertex3fv(vertices13[6]);

	glVertex3fv(vertices13[4]);
	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[1]);
	glVertex3fv(vertices13[5]);

	// 13

	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[2]);
	glVertex3fv(vertices14[1]);

	glVertex3fv(vertices14[1]);
	glVertex3fv(vertices14[2]);
	glVertex3fv(vertices14[6]);
	glVertex3fv(vertices14[5]);

	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[6]);
	glVertex3fv(vertices14[2]);

	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[4]);

	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[4]);
	glVertex3fv(vertices14[5]);
	glVertex3fv(vertices14[6]);

	glVertex3fv(vertices14[4]);
	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[1]);
	glVertex3fv(vertices14[5]);

	// 14

	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[2]);
	glVertex3fv(vertices15[1]);

	glVertex3fv(vertices15[1]);
	glVertex3fv(vertices15[2]);
	glVertex3fv(vertices15[6]);
	glVertex3fv(vertices15[5]);

	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[6]);
	glVertex3fv(vertices15[2]);

	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[4]);

	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[4]);
	glVertex3fv(vertices15[5]);
	glVertex3fv(vertices15[6]);

	glVertex3fv(vertices15[4]);
	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[1]);
	glVertex3fv(vertices15[5]);

	// 15

	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[2]);
	glVertex3fv(vertices16[1]);

	glVertex3fv(vertices16[1]);
	glVertex3fv(vertices16[2]);
	glVertex3fv(vertices16[6]);
	glVertex3fv(vertices16[5]);

	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[6]);
	glVertex3fv(vertices16[2]);

	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[4]);

	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[4]);
	glVertex3fv(vertices16[5]);
	glVertex3fv(vertices16[6]);

	glVertex3fv(vertices16[4]);
	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[1]);
	glVertex3fv(vertices16[5]);

	// 16

	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[2]);
	glVertex3fv(vertices17[1]);

	glVertex3fv(vertices17[1]);
	glVertex3fv(vertices17[2]);
	glVertex3fv(vertices17[6]);
	glVertex3fv(vertices17[5]);

	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[6]);
	glVertex3fv(vertices17[2]);

	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[4]);

	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[4]);
	glVertex3fv(vertices17[5]);
	glVertex3fv(vertices17[6]);

	glVertex3fv(vertices17[4]);
	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[1]);
	glVertex3fv(vertices17[5]);

	// 17

	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[2]);
	glVertex3fv(vertices18[1]);

	glVertex3fv(vertices18[1]);
	glVertex3fv(vertices18[2]);
	glVertex3fv(vertices18[6]);
	glVertex3fv(vertices18[5]);

	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[6]);
	glVertex3fv(vertices18[2]);

	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[4]);

	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[4]);
	glVertex3fv(vertices18[5]);
	glVertex3fv(vertices18[6]);

	glVertex3fv(vertices18[4]);
	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[1]);
	glVertex3fv(vertices18[5]);

	// 18

	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[2]);
	glVertex3fv(vertices19[1]);

	glVertex3fv(vertices19[1]);
	glVertex3fv(vertices19[2]);
	glVertex3fv(vertices19[6]);
	glVertex3fv(vertices19[5]);

	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[6]);
	glVertex3fv(vertices19[2]);

	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[4]);

	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[4]);
	glVertex3fv(vertices19[5]);
	glVertex3fv(vertices19[6]);

	glVertex3fv(vertices19[4]);
	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[1]);
	glVertex3fv(vertices19[5]);

	// 19

	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[2]);
	glVertex3fv(vertices20[1]);

	glVertex3fv(vertices20[1]);
	glVertex3fv(vertices20[2]);
	glVertex3fv(vertices20[6]);
	glVertex3fv(vertices20[5]);

	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[6]);
	glVertex3fv(vertices20[2]);

	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[4]);

	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[4]);
	glVertex3fv(vertices20[5]);
	glVertex3fv(vertices20[6]);

	glVertex3fv(vertices20[4]);
	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[1]);
	glVertex3fv(vertices20[5]);
	glEnd();
	// 20

	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(-13, 11, -1);
	glEnd();	// 바닥

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -11, 1);
	glVertex3f(-13, -11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(-13, -12, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -11, 1);
	glVertex3f(13, -11, 1);
	glVertex3f(13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -11, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-13, -11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(13, -11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -11, 1);
	glVertex3f(-13, -11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(-13, -12, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, -11, 1);
	glVertex3f(13, -11, 1);
	glVertex3f(13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, -11, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-13, -11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(13, -11, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(13, -11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, -12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	// 아래





	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, -12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, -12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, 12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(14, -12, -1);
	glVertex3f(14, 12, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, 12, 1);
	glVertex3f(13, -12, 1);
	glVertex3f(14, -12, 1);
	glVertex3f(14, 12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(14, -12, -1);
	glVertex3f(14, 12, -1);
	glVertex3f(14, 12, 1);
	glVertex3f(14, -12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, 12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(13, -12, 1);
	glEnd();



	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(13, -12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, -12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(13, 12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(14, -12, -1);
	glVertex3f(14, 12, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(13, 12, 1);
	glVertex3f(13, -12, 1);
	glVertex3f(14, -12, 1);
	glVertex3f(14, 12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(14, -12, -1);
	glVertex3f(14, 12, -1);
	glVertex3f(14, 12, 1);
	glVertex3f(14, -12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, 12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, -1);
	glVertex3f(13, -12, 1);
	glVertex3f(13, -12, 1);
	glEnd();
	// 오른




	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 11, 1);
	glVertex3f(-13, 11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(-13, 12, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 11, 1);
	glVertex3f(13, 11, 1);
	glVertex3f(13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 11, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, 11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, 11, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, 11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 11, 1);
	glVertex3f(-13, 11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, 11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(-13, 12, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, 11, 1);
	glVertex3f(13, 11, 1);
	glVertex3f(13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, 11, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, 11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(13, 11, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(13, 11, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(-13, 12, -1);
	glVertex3f(13, 12, -1);
	glVertex3f(13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();





	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-14, -12, -1);
	glVertex3f(-14, 12, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-14, -12, 1);
	glVertex3f(-14, 12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-14, -12, -1);
	glVertex3f(-14, 12, -1);
	glVertex3f(-14, 12, 1);
	glVertex3f(-14, -12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();



	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-14, -12, -1);
	glVertex3f(-14, 12, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-14, -12, 1);
	glVertex3f(-14, 12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-14, -12, -1);
	glVertex3f(-14, 12, -1);
	glVertex3f(-14, 12, 1);
	glVertex3f(-14, -12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, -1);
	glVertex3f(-13, 12, 1);
	glVertex3f(-13, 12, 1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, -1);
	glVertex3f(-13, -12, 1);
	glVertex3f(-13, -12, 1);
	glEnd();
	//왼


	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-13, -11, -1);
	glVertex3f(13, -11, -1);
	glVertex3f(13, 11, -1);
	glVertex3f(-13, 11, -1);
	glEnd();



	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[2]);
	glVertex3fv(vertices1[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[1]);
	glVertex3fv(vertices1[2]);
	glVertex3fv(vertices1[6]);
	glVertex3fv(vertices1[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[6]);
	glVertex3fv(vertices1[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[3]);
	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[7]);
	glVertex3fv(vertices1[4]);
	glVertex3fv(vertices1[5]);
	glVertex3fv(vertices1[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices1[4]);
	glVertex3fv(vertices1[0]);
	glVertex3fv(vertices1[1]);
	glVertex3fv(vertices1[5]);
	glEnd();
	//1번
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[2]);
	glVertex3fv(vertices2[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[1]);
	glVertex3fv(vertices2[2]);
	glVertex3fv(vertices2[6]);
	glVertex3fv(vertices2[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[6]);
	glVertex3fv(vertices2[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[3]);
	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[7]);
	glVertex3fv(vertices2[4]);
	glVertex3fv(vertices2[5]);
	glVertex3fv(vertices2[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices2[4]);
	glVertex3fv(vertices2[0]);
	glVertex3fv(vertices2[1]);
	glVertex3fv(vertices2[5]);

	//2번
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[2]);
	glVertex3fv(vertices3[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[1]);
	glVertex3fv(vertices3[2]);
	glVertex3fv(vertices3[6]);
	glVertex3fv(vertices3[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[6]);
	glVertex3fv(vertices3[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[3]);
	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[7]);
	glVertex3fv(vertices3[4]);
	glVertex3fv(vertices3[5]);
	glVertex3fv(vertices3[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices3[4]);
	glVertex3fv(vertices3[0]);
	glVertex3fv(vertices3[1]);
	glVertex3fv(vertices3[5]);

	// 3번

	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[2]);
	glVertex3fv(vertices4[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[1]);
	glVertex3fv(vertices4[2]);
	glVertex3fv(vertices4[6]);
	glVertex3fv(vertices4[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[6]);
	glVertex3fv(vertices4[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[3]);
	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[7]);
	glVertex3fv(vertices4[4]);
	glVertex3fv(vertices4[5]);
	glVertex3fv(vertices4[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices4[4]);
	glVertex3fv(vertices4[0]);
	glVertex3fv(vertices4[1]);
	glVertex3fv(vertices4[5]);

	// 4
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[2]);
	glVertex3fv(vertices5[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[1]);
	glVertex3fv(vertices5[2]);
	glVertex3fv(vertices5[6]);
	glVertex3fv(vertices5[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[6]);
	glVertex3fv(vertices5[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[3]);
	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[7]);
	glVertex3fv(vertices5[4]);
	glVertex3fv(vertices5[5]);
	glVertex3fv(vertices5[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices5[4]);
	glVertex3fv(vertices5[0]);
	glVertex3fv(vertices5[1]);
	glVertex3fv(vertices5[5]);

	// 5

	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[2]);
	glVertex3fv(vertices6[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[1]);
	glVertex3fv(vertices6[2]);
	glVertex3fv(vertices6[6]);
	glVertex3fv(vertices6[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[6]);
	glVertex3fv(vertices6[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[3]);
	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[7]);
	glVertex3fv(vertices6[4]);
	glVertex3fv(vertices6[5]);
	glVertex3fv(vertices6[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices6[4]);
	glVertex3fv(vertices6[0]);
	glVertex3fv(vertices6[1]);
	glVertex3fv(vertices6[5]);

	// 6
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[2]);
	glVertex3fv(vertices7[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[1]);
	glVertex3fv(vertices7[2]);
	glVertex3fv(vertices7[6]);
	glVertex3fv(vertices7[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[6]);
	glVertex3fv(vertices7[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[3]);
	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[7]);
	glVertex3fv(vertices7[4]);
	glVertex3fv(vertices7[5]);
	glVertex3fv(vertices7[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices7[4]);
	glVertex3fv(vertices7[0]);
	glVertex3fv(vertices7[1]);
	glVertex3fv(vertices7[5]);

	// 7
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[2]);
	glVertex3fv(vertices8[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[1]);
	glVertex3fv(vertices8[2]);
	glVertex3fv(vertices8[6]);
	glVertex3fv(vertices8[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[6]);
	glVertex3fv(vertices8[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[3]);
	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[7]);
	glVertex3fv(vertices8[4]);
	glVertex3fv(vertices8[5]);
	glVertex3fv(vertices8[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices8[4]);
	glVertex3fv(vertices8[0]);
	glVertex3fv(vertices8[1]);
	glVertex3fv(vertices8[5]);

	// 8
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[2]);
	glVertex3fv(vertices9[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[1]);
	glVertex3fv(vertices9[2]);
	glVertex3fv(vertices9[6]);
	glVertex3fv(vertices9[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[6]);
	glVertex3fv(vertices9[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[3]);
	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[7]);
	glVertex3fv(vertices9[4]);
	glVertex3fv(vertices9[5]);
	glVertex3fv(vertices9[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices9[4]);
	glVertex3fv(vertices9[0]);
	glVertex3fv(vertices9[1]);
	glVertex3fv(vertices9[5]);

	// 9
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[2]);
	glVertex3fv(vertices10[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[1]);
	glVertex3fv(vertices10[2]);
	glVertex3fv(vertices10[6]);
	glVertex3fv(vertices10[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[6]);
	glVertex3fv(vertices10[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[3]);
	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[7]);
	glVertex3fv(vertices10[4]);
	glVertex3fv(vertices10[5]);
	glVertex3fv(vertices10[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices10[4]);
	glVertex3fv(vertices10[0]);
	glVertex3fv(vertices10[1]);
	glVertex3fv(vertices10[5]);

	// 10
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[2]);
	glVertex3fv(vertices11[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[1]);
	glVertex3fv(vertices11[2]);
	glVertex3fv(vertices11[6]);
	glVertex3fv(vertices11[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[6]);
	glVertex3fv(vertices11[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[3]);
	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[7]);
	glVertex3fv(vertices11[4]);
	glVertex3fv(vertices11[5]);
	glVertex3fv(vertices11[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices11[4]);
	glVertex3fv(vertices11[0]);
	glVertex3fv(vertices11[1]);
	glVertex3fv(vertices11[5]);

	// 11
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[2]);
	glVertex3fv(vertices12[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[1]);
	glVertex3fv(vertices12[2]);
	glVertex3fv(vertices12[6]);
	glVertex3fv(vertices12[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[6]);
	glVertex3fv(vertices12[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[3]);
	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[7]);
	glVertex3fv(vertices12[4]);
	glVertex3fv(vertices12[5]);
	glVertex3fv(vertices12[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices12[4]);
	glVertex3fv(vertices12[0]);
	glVertex3fv(vertices12[1]);
	glVertex3fv(vertices12[5]);

	// 12
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[2]);
	glVertex3fv(vertices13[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[1]);
	glVertex3fv(vertices13[2]);
	glVertex3fv(vertices13[6]);
	glVertex3fv(vertices13[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[6]);
	glVertex3fv(vertices13[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[3]);
	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[7]);
	glVertex3fv(vertices13[4]);
	glVertex3fv(vertices13[5]);
	glVertex3fv(vertices13[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices13[4]);
	glVertex3fv(vertices13[0]);
	glVertex3fv(vertices13[1]);
	glVertex3fv(vertices13[5]);

	// 13
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[2]);
	glVertex3fv(vertices14[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[1]);
	glVertex3fv(vertices14[2]);
	glVertex3fv(vertices14[6]);
	glVertex3fv(vertices14[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[6]);
	glVertex3fv(vertices14[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[3]);
	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[7]);
	glVertex3fv(vertices14[4]);
	glVertex3fv(vertices14[5]);
	glVertex3fv(vertices14[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices14[4]);
	glVertex3fv(vertices14[0]);
	glVertex3fv(vertices14[1]);
	glVertex3fv(vertices14[5]);

	// 14
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[2]);
	glVertex3fv(vertices15[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[1]);
	glVertex3fv(vertices15[2]);
	glVertex3fv(vertices15[6]);
	glVertex3fv(vertices15[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[6]);
	glVertex3fv(vertices15[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[3]);
	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[7]);
	glVertex3fv(vertices15[4]);
	glVertex3fv(vertices15[5]);
	glVertex3fv(vertices15[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices15[4]);
	glVertex3fv(vertices15[0]);
	glVertex3fv(vertices15[1]);
	glVertex3fv(vertices15[5]);

	// 15
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[2]);
	glVertex3fv(vertices16[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[1]);
	glVertex3fv(vertices16[2]);
	glVertex3fv(vertices16[6]);
	glVertex3fv(vertices16[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[6]);
	glVertex3fv(vertices16[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[3]);
	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[7]);
	glVertex3fv(vertices16[4]);
	glVertex3fv(vertices16[5]);
	glVertex3fv(vertices16[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices16[4]);
	glVertex3fv(vertices16[0]);
	glVertex3fv(vertices16[1]);
	glVertex3fv(vertices16[5]);

	// 16
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[2]);
	glVertex3fv(vertices17[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[1]);
	glVertex3fv(vertices17[2]);
	glVertex3fv(vertices17[6]);
	glVertex3fv(vertices17[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[6]);
	glVertex3fv(vertices17[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[3]);
	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[7]);
	glVertex3fv(vertices17[4]);
	glVertex3fv(vertices17[5]);
	glVertex3fv(vertices17[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices17[4]);
	glVertex3fv(vertices17[0]);
	glVertex3fv(vertices17[1]);
	glVertex3fv(vertices17[5]);

	// 17
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[2]);
	glVertex3fv(vertices18[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[1]);
	glVertex3fv(vertices18[2]);
	glVertex3fv(vertices18[6]);
	glVertex3fv(vertices18[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[6]);
	glVertex3fv(vertices18[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[3]);
	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[7]);
	glVertex3fv(vertices18[4]);
	glVertex3fv(vertices18[5]);
	glVertex3fv(vertices18[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices18[4]);
	glVertex3fv(vertices18[0]);
	glVertex3fv(vertices18[1]);
	glVertex3fv(vertices18[5]);

	// 18
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[2]);
	glVertex3fv(vertices19[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[1]);
	glVertex3fv(vertices19[2]);
	glVertex3fv(vertices19[6]);
	glVertex3fv(vertices19[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[6]);
	glVertex3fv(vertices19[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[3]);
	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[7]);
	glVertex3fv(vertices19[4]);
	glVertex3fv(vertices19[5]);
	glVertex3fv(vertices19[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices19[4]);
	glVertex3fv(vertices19[0]);
	glVertex3fv(vertices19[1]);
	glVertex3fv(vertices19[5]);

	// 19
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[2]);
	glVertex3fv(vertices20[1]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[1]);
	glVertex3fv(vertices20[2]);
	glVertex3fv(vertices20[6]);
	glVertex3fv(vertices20[5]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[6]);
	glVertex3fv(vertices20[2]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[3]);
	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[4]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[7]);
	glVertex3fv(vertices20[4]);
	glVertex3fv(vertices20[5]);
	glVertex3fv(vertices20[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(vertices20[4]);
	glVertex3fv(vertices20[0]);
	glVertex3fv(vertices20[1]);
	glVertex3fv(vertices20[5]);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3fv(vertices_point[0]);
	glVertex3fv(vertices_point[3]);
	glVertex3fv(vertices_point[2]);
	glVertex3fv(vertices_point[1]);

	glVertex3fv(vertices_point[1]);
	glVertex3fv(vertices_point[2]);
	glVertex3fv(vertices_point[6]);
	glVertex3fv(vertices_point[5]);

	glVertex3fv(vertices_point[3]);
	glVertex3fv(vertices_point[7]);
	glVertex3fv(vertices_point[6]);
	glVertex3fv(vertices_point[2]);

	glVertex3fv(vertices_point[0]);
	glVertex3fv(vertices_point[3]);
	glVertex3fv(vertices_point[7]);
	glVertex3fv(vertices_point[4]);

	glVertex3fv(vertices_point[7]);
	glVertex3fv(vertices_point[4]);
	glVertex3fv(vertices_point[5]);
	glVertex3fv(vertices_point[6]);

	glVertex3fv(vertices_point[4]);
	glVertex3fv(vertices_point[0]);
	glVertex3fv(vertices_point[1]);
	glVertex3fv(vertices_point[5]);
	glEnd();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	ww = w; wh = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-hv, hv, -hv * (GLfloat)h / (GLfloat)w,
			hv * (GLfloat)h / (GLfloat)w, -10.0*hv, 10.0*hv);
	else
		glOrtho(-hv * (GLfloat)w / (GLfloat)h,
			hv * (GLfloat)w / (GLfloat)h, -hv, hv, -10.0*hv, 10.0*hv);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int btn, int state, int x, int y) {
	if (state == GLUT_UP) {
		if (btn == GLUT_WHEEL_UP) hv *= 0.95;
		else if (btn == GLUT_WHEEL_DOWN) hv *= 1.0 / 0.95;
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		last_x = x; last_y = (wh - y);
	glutPostRedisplay();
	reshape(ww, wh);
}

void move(int x, int y) {
	GLfloat delx, dely;
	GLfloat ang_res = 2 * PI / 800;
	bool shift = false;

	y = wh - y;

	delx = (GLfloat)x - last_x;
	dely = (GLfloat)y - last_y;
	last_x = (GLfloat)x;
	last_y = (GLfloat)y;

	phi += -dely*ang_res;
	if (phi >= PI / 2) phi = PI / 2;
	else if (phi <= -PI / 2) phi = -PI / 2;

	theta += -delx*ang_res;
	if (theta >= 2 * PI) theta -= 2 * PI;
	else if (theta <= 2 * PI) theta += 2 * PI;

	glutPostRedisplay();
}

char timerBuffer[8 + 1]; // 06:17:20 등의 경과 시간 문자열이 저장될 버퍼 정의


void secToHHMMSS(int secs, char* s, size_t size) { // 정수로 된 초(sec)를 입력 받아, "06:17:20" 등의 형식의 문자열로 시분초를 배열에 저장
	int hour, min, sec;

	sec = secs % 60;
	min = secs / 60 % 60;
	hour = secs / 3600;

	sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}

void stopwatch(int onOff) {
	static int oldTime; // stopwatch 함수가 종료되어도 값을 기억하는 "정적 지역 변수"

	if (onOff == 1) { // 타이머 켜기
		oldTime = (int)time(NULL);
	}

	if (onOff == 0) { // 타이머 끄고, 시분초를 timerBuffer 에 저장
		secToHHMMSS(
			(int)time(NULL) - oldTime,
			timerBuffer,
			sizeof(timerBuffer)
		);
	}
}

void drawfloor()
{
	glBegin(GL_LINES);

	glColor3f(1, 1, 1);
	glVertex3f(20, 20, -1);

	//glVertex3f(-20, 20, -1);
	glVertex3f(-20, -20, -1);

	//glVertex3f(20, -20, -1);
	glEnd();
}

void display(void) {

	if (t == 0)
	{
		t = t + 1;
		stopwatch(1);
	}

	radius = 4.0;
	camX = radius*cos(phi)*sin(theta);
	camY = radius*sin(phi);
	camZ = radius*cos(phi)*cos(theta);

	//materialStruct *matp;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//if (click % 2 == 1) gluLookAt(10, 0, 10, 0, 0, 0, 0, 1, 0);
	//else gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

	//drawfloor();
	drawObj();

	//setLighting();

	glPushMatrix();
	glTranslatef(xx - 12, yy + 10, zz);
	//matp = &ball;
	//materials(matp);
	glColor3f(0, 1, 0);
	glutSolidSphere(1.0, 32, 32);
	glPopMatrix();


	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0); /* 검은배경*/
	hv = 2.0;
	glOrtho(-hv, hv, -hv, hv, -hv, hv);
	glEnable(GL_DEPTH_TEST);
}

void timerw()
{
	
	yy = yy + 0.5;

	if (yy > -0.5 || (xx == 12 && yy == -2) || (xx == 4 && yy == -4) || (xx == 22 && yy == -4) ||
		(xx == 8 && yy == -6) || (xx == 18 && yy == -6) || (xx == 2 && yy == -8) || (xx == 20 && yy == -8) ||
		(xx == 10 && yy == -10) || (xx == 24 && yy == -10) || (xx == 0 && yy == -12) || (xx == 16 && yy == -12) ||
		(xx == 4 && yy == -14) || (xx == 22 && yy == -14) || (xx == 8 && yy == -16) || (xx == 18 && yy == -18) ||
		(xx == 24 && yy == -18) || (xx == 2 && yy == -20) || (xx == 20 && yy == -20))
	{

		move_count += 1;
		glutIdleFunc(timerp);

	}
		

	system("cls");
	printf("x : %f, y : %f, z : %f\n", xx, yy, zz);
	printf("경과 시간 : [%s]\n", timerBuffer);
	stopwatch(0);
	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 1);
}

void timers()
{
	yy = yy - 0.5;
	if (yy < -19.5 || (xx == 4 && yy == 0) || (xx == 22 && yy == 0) || (xx == 8 && yy == -2) ||
		(xx == 18 && yy == -2) || (xx == 2 && yy == -4) || (xx == 20 && yy == -4) || (xx == 10 && yy == -6) ||
		(xx == 24 && yy == -6) || (xx == 0 && yy == -8) || (xx == 16 && yy == -8) || (xx == 4 && yy == -10) ||
		(xx == 22 && yy == -10) || (xx == 8 && yy == -12) || (xx == 18 && yy == -14) || (xx == 24 && yy == -14) ||
		(xx == 2 && yy == -16) || (xx == 20 && yy == -16) || (xx == 6 && yy == -18) || (xx == 14 && yy == -18))
	{

		move_count += 1;
		glutIdleFunc(timerp);

	}

	system("cls");
	printf("x : %f, y : %f, z : %f\n", xx, yy, zz);
	printf("경과 시간 : [%s]\n", timerBuffer);
	stopwatch(0);
	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 1);
}

void timera()
{
	xx = xx - 0.5;

	if (xx < 0.5 || (xx == 14 && yy == 0) || (xx == 6 && yy == -2) || (xx == 24 && yy == -2) ||
		(xx == 10 && yy == -4) || (xx == 20 && yy == -4) || (xx == 4 && yy == -6) || (xx == 22 && yy == -6) ||
		(xx == 12 && yy == -8) || (xx == 2 && yy == -10) || (xx == 18 && yy == -10) || (xx == 6 && yy == -12) ||
		(xx == 24 && yy == -12) || (xx == 10 && yy == -14) || (xx == 20 && yy == -16) || (xx == 4 && yy == -18) || (xx == 22 && yy == -18) ||
		(xx == 8 && yy == -20) || (xx == 16 && yy == -20))
	{

		move_count += 1;
		glutIdleFunc(timerp);

	}

	system("cls");
	printf("x : %f, y : %f, z : %f\n", xx, yy, zz);
	printf("경과 시간 : [%s]\n", timerBuffer);
	stopwatch(0);
	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 1);
}

void timerd()
{
	xx = xx + 0.5;

	if (xx > 23.5 || (xx == 10 && yy == 0) || (xx == 2 && yy == -2) || (xx == 20 && yy == -2) || 
		(xx == 6 && yy == -4) || (xx == 16 && yy == -4) || /*(xx = 0 && yy == -6) || */(xx == 18 && yy == -6) ||
		(xx == 8 && yy == -8) || (xx == 22 && yy == -8) || (xx == 14 && yy == -10) ||
		(xx == 2 && yy == -12) || (xx == 20 && yy == -12) || (xx == 6 && yy == -14) ||
		(xx == 16 && yy == -16) || (xx == 22 && yy == -16) || (xx == 0 && yy == -18) || (xx == 18 && yy == -18) ||
		(xx == 4 && yy == -20) || (xx == 12 && yy == -20))
	{

		move_count += 1;
		glutIdleFunc(timerp);

	}

	system("cls");
	printf("x : %f, y : %f, z : %f\n", xx, yy, zz);
	printf("경과 시간 : [%s]\n", timerBuffer);
	
	stopwatch(0);
	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 1);
}

void timerp()	// 공 멈추기 함수
{
	if (xx == 16 && yy == -12)
	{
		zz = zz - 0.2;
		if (zz < -20)
		{
			TCHAR szUniCode2[256] = { 0, };

			char text[100];
			//MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, timerBuffer, strlen(timerBuffer), szUniCode, 256);
			sprintf_s(text, sizeof(text), "시간 : %s\n움직인 횟수 : %d", timerBuffer, move_count);

			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, text, strlen(text), szUniCode2, 256);
			MessageBox(NULL, szUniCode2, TEXT("게임 클리어"), MB_OK);
			exit(0);
		}
		//TCHAR szUniCode[256] = { 0, };
	}
	
	system("cls");
	printf("x : %f, y : %f, z : %f\n", xx, yy, zz);
	printf("경과 시간 : [%s]\n", timerBuffer);
	printf("움직인 횟수 : %d\n", move_count);
	stopwatch(0);

	
	glutPostRedisplay();
}

void mykey(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		//yy = yy + 1;
		glutIdleFunc(timerw);
		//glutTimerFunc(1000, timer, 1);
		//glutDisplayFunc(displayw);
	}
	else if (key == 'a')
	{
		//xx = xx - 1;
		glutIdleFunc(timera);
		//glutDisplayFunc(displaya);
	}
	else if (key == 's')
	{
		//yy = yy - 1;
		glutIdleFunc(timers);
		//glutDisplayFunc(displays);
	}
	else if (key == 'd')
	{
		//xx = xx + 1;
		glutIdleFunc(timerd);
		//glutDisplayFunc(displayd);
	}
	else if (key == 'p')
	{
		glutIdleFunc(timerp);
	}

	glutPostRedisplay();
}

/*
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click = click + 1;
	}
}
*/

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(650, 550);
	glutCreateWindow("빙판 퍼즐");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(move);
	glutKeyboardUpFunc(mykey);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	myinit();

	glutMainLoop();
}
