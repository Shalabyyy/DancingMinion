#include <stdlib.h>
#include <glut.h>
#include <random>
#include <iostream>
#include <Windows.h>

/*
FRONT VIEW: Key 1
SIDE VIEW: KEY 2
TOP VIEW: KEY 3
SLOWMO: KEY 4

*/
float moveX = 0;
float moveY = 0;
float moveZ = 0;
int frames = 0;
int shuffle = 0;
int jump = 0;
int sturidge=0;
int gameSpeed = 50;
int floss = 0;
double flossL, flossR = 0;
double scale = 2.5;
double cubeAngleZ,cubeAngleX,cubeAngleY = 0;
double sysX, sysY, sysZ = 0;
int px, py, pz = 20;

double minionX, minionY, minionZ = 0;
double angleX, angleY, angleZ = 0;
double leftArm, RightArm = 0; // Y axis
double leftLeg, RightLeg = 0; // Z axis

//Camera Variables
float eyeX , eyeY , eyeZ , centerX , centerY , centerZ , upX , upY , upZ = 0;

// Wall 1 Variables
float W1R1C1R, W1R1C1G, W1R1C1B = 0;
float W1R1C2R, W1R1C2G, W1R1C2B = 0;
float W1R1C3R, W1R1C3G, W1R1C3B = 0;
float W1R2C1R, W1R2C1G, W1R2C1B = 0;
float W1R2C2R, W1R2C2G, W1R2C2B = 0;
float W1R2C3R, W1R2C3G, W1R2C3B = 0;
float W1R3C1R, W1R3C1G, W1R3C1B = 0;
float W1R3C2R, W1R3C2G, W1R3C2B = 0;
float W1R3C3R, W1R3C3G, W1R3C3B = 0;

// Wall 2 Variables
float W2R1C1R, W2R1C1G, W2R1C1B = 0;
float W2R1C2R, W2R1C2G, W2R1C2B = 0;
float W2R1C3R, W2R1C3G, W2R1C3B = 0;
float W2R2C1R, W2R2C1G, W2R2C1B = 0;
float W2R2C2R, W2R2C2G, W2R2C2B = 0;
float W2R2C3R, W2R2C3G, W2R2C3B = 0;
float W2R3C1R, W2R3C1G, W2R3C1B = 0;
float W2R3C2R, W2R3C2G, W2R3C2B = 0;
float W2R3C3R, W2R3C3G, W2R3C3B = 0;

// Wall 3 Variables
float W3R1C1R, W3R1C1G, W3R1C1B = 0;
float W3R1C2R, W3R1C2G, W3R1C2B = 0;
float W3R1C3R, W3R1C3G, W3R1C3B = 0;
float W3R2C1R, W3R2C1G, W3R2C1B = 0;
float W3R2C2R, W3R2C2G, W3R2C2B = 0;
float W3R2C3R, W3R2C3G, W3R2C3B = 0;
float W3R3C1R, W3R3C1G, W3R3C1B = 0;
float W3R3C2R, W3R3C2G, W3R3C2B = 0;
float W3R3C3R, W3R3C3G, W3R3C3B = 0;

// Wall 4 Variables
float W4R1C1R, W4R1C1G, W4R1C1B = 0;
float W4R1C2R, W4R1C2G, W4R1C2B = 0;
float W4R1C3R, W4R1C3G, W4R1C3B = 0;
float W4R2C1R, W4R2C1G, W4R2C1B = 0;
float W4R2C2R, W4R2C2G, W4R2C2B = 0;
float W4R2C3R, W4R2C3G, W4R2C3B = 0;
float W4R3C1R, W4R3C1G, W4R3C1B = 0;
float W4R3C2R, W4R3C2G, W4R3C2B = 0;
float W4R3C3R, W4R3C3G, W4R3C3B = 0;

//Wall 5 Variables
float W5R1C1R, W5R1C1G, W5R1C1B = 0;
float W5R1C2R, W5R1C2G, W5R1C2B = 0;
float W5R1C3R, W5R1C3G, W5R1C3B = 0;
float W5R2C1R, W5R2C1G, W5R2C1B = 0;
float W5R2C2R, W5R2C2G, W5R2C2B = 0;
float W5R2C3R, W5R2C3G, W5R2C3B = 0;
float W5R3C1R, W5R3C1G, W5R3C1B = 0;
float W5R3C2R, W5R3C2G, W5R3C2B = 0;
float W5R3C3R, W5R3C3G, W5R3C3B = 0;

GLUquadricObj *quadratic = gluNewQuadric();

void drawSuperman(double thickness, double scale) {
	glPushMatrix();
	glRotated(angleY, 0.2, 0, 0.2);
	glRotated(angleZ, 0, 0, 1.0);
	//righteyes
	glPushMatrix(); 
	glColor3d(0.0, 0.0, 0.0);
	glTranslated(0.192, 0.45 * thickness + 0.057, 0.213);
	glScaled(0.06, 0.1, 0.02);
	gluSphere(quadratic, 0.02, 100, 100);
	glColor3d(0.6, 0.3, 0.0);
	gluDisk(quadratic, 0.02, 0.04, 100, 100);
	glPopMatrix();

	//lefteyes
	glPushMatrix();
	glColor3d(0.0, 0.0, 0.0);
	glTranslated(0.208, 0.45 * thickness + 0.057, 0.213);
	glScaled(0.06, 0.1, 0.02);
	gluSphere(quadratic, 0.02, 100, 100);
	glColor3d(0.6, 0.3, 0.0);
	gluDisk(quadratic, 0.02, 0.04, 100, 100);
	glPopMatrix();


	//gogglesleft
	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.208, 0.45 * thickness + 0.06, 0.213);
	glScaled(0.06, 0.1, 0.02);
	gluDisk(quadratic, 0.0, 0.09, 100, 100);
	gluCylinder(quadratic, 0.09, 0.09, 0.5, 100, 100);
	glPopMatrix();


	//gogglesright
	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.192, 0.45 * thickness + 0.06, 0.213);
	glScaled(0.06, 0.1, 0.02);
	gluDisk(quadratic, 0.0, 0.09, 100, 100);
	gluCylinder(quadratic, 0.09, 0.09, 0.5, 100, 100);
	glPopMatrix();


	//mouth
	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.209, 0.5 * thickness + 0.022, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.207, 0.5 * thickness + 0.0215, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.205, 0.5 * thickness + 0.021, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.203, 0.5 * thickness + 0.0205, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.201, 0.5 * thickness + 0.02, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.199, 0.5 * thickness + 0.0205, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.197, 0.5 * thickness + 0.021, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.195, 0.5 * thickness + 0.0215, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.193, 0.5 * thickness + 0.022, 0.212);
	glScaled(0.06, 0.1, 0.01);
	gluDisk(quadratic, 0.0, 0.03, 100, 100);
	glPopMatrix();

	//leftarm
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.20 , 0.5 * thickness + 0.025 + leftArm, 0.20+flossL);
	glRotated(90, 1.0, 1.0, 0.0);
	glScaled(0.06, 0.1, 0.02);
	gluCylinder(quadratic, 0.05, 0.05, 3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.245, 0.5 * thickness - 0.02 + leftArm, 0.201+flossL);
	glScaled(0.08, 0.1, 0.08);
	gluSphere(quadratic, 0.08, 100, 100);
	glPopMatrix();


	//rightarm
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.20, 0.5 * thickness + 0.025+RightArm, 0.20+flossR);
	glRotated(90, 0.0, 0.0, 1.0);
	glRotated(-90, 1.0, 1.0, 0.0);
	glScaled(0.06, 0.1, 0.02);
	gluCylinder(quadratic, 0.05, 0.05, 3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.155, 0.5 * thickness - 0.02 + RightArm, 0.201+flossR);
	glScaled(0.08, 0.1, 0.08);
	gluSphere(quadratic, 0.08, 100, 100);
	glPopMatrix();


	//body
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.20, 0.5 * thickness + 0.06, 0.20);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.02);
	gluCylinder(quadratic, 0.2, 0.2, 5, 100, 100);
	glPopMatrix();

	//rightleg
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.19, 0.5 * thickness, 0.20+RightLeg);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.02);
	gluCylinder(quadratic, 0.05, 0.05, 5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.19, 0.5 * thickness - 0.1, 0.205+RightLeg);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.04, 0.07, 0.04);
	glutSolidCube(0.25);
	glPopMatrix();

	//leftleg
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.21, 0.5 * thickness, 0.20+leftLeg);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.02);
	gluCylinder(quadratic, 0.05, 0.05, 5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslated(0.21, 0.5 * thickness - 0.1, 0.205+leftLeg);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.04, 0.07, 0.04);
	glutSolidCube(0.25);
	glPopMatrix();

	//clothes
	glPushMatrix();
	glColor3d(0.0, 0.0, 1.0);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.01);
	gluCylinder(quadratic, 0.21, 0.21, 5, 100, 100);
	glPopMatrix();

	//head
	glPushMatrix();
	glColor3d(1.0, 1.0, 0);
	glTranslated(0.20, 0.5 * thickness + 0.06, 0.20);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.1);
	gluSphere(quadratic, 0.2, 100, 100);
	glPopMatrix();

	//bottom
	glPushMatrix();
	glColor3d(0.0, 0.0, 1.0);
	glTranslated(0.20, 0.5 * thickness - 0.05, 0.20);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.1);
	gluSphere(quadratic, 0.21, 100, 100);
	glPopMatrix();


	//gogglesstrap
	glPushMatrix();
	glColor3d(0.0, 0.0, 0.0);
	glTranslated(0.20, 0.5 * thickness + 0.055, 0.20);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotated(90, 1.0, 0.0, 0.0);
	glScaled(0.06, 0.1, 0.01);
	gluCylinder(quadratic, 0.21, 0.21, 1, 100, 100);
	glPopMatrix();

	glPopMatrix();
}

void drawWall(double thickness,double scale) {

	// Row One
	glPushMatrix();
	glColor3d(W1R1C1R/255, W1R1C1G/255, W1R1C1B/255);
	glTranslated(0.10, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R1C2R/255, W1R1C2G/255, W1R1C2B/255);
	glTranslated(0.10, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R1C3R/255, W1R1C3G/255, W1R1C3B/255);
	glTranslated(0.10, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row two
	glPushMatrix();
	glColor3d(W1R2C1R/255, W1R2C1G/255, W1R2C1B/255);
	glTranslated(0.20, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R2C2R/255, W1R2C2G/255, W1R2C2B/255);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R2C3R/255, W1R2C3G/255, W1R2C3B/255);
	glTranslated(0.20, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row Three
	glPushMatrix();
	glColor3d(W1R3C1R/255, W1R3C1G/255, W1R3C1B/255);
	glTranslated(0.30, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R3C2R/255, W1R3C2G/255, W1R3C2B/255);
	glTranslated(0.30, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W1R3C3R/255, W1R3C3G/255, W1R3C3B/255);
	glTranslated(0.30, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();
}
void drawWall2(double thickness, double scale) {

	// Row One
	glPushMatrix();
	glColor3d(W2R1C1R / 255, W2R1C1G / 255, W2R1C1B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R1C2R / 255, W2R1C2G / 255, W2R1C2B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R1C3R / 255, W2R1C3G / 255, W2R1C3B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row two
	glPushMatrix();
	glColor3d(W2R2C1R / 255, W2R2C1G / 255, W2R2C1B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R2C2R / 255, W2R2C2G / 255, W2R2C2B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R2C3R / 255, W2R2C3G / 255, W2R2C3B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row Three
	glPushMatrix();
	glColor3d(W2R3C1R / 255, W2R3C1G / 255, W2R3C1B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R3C2R / 255, W2R3C2G / 255, W2R3C2B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W2R3C3R / 255, W2R3C3G / 255, W2R3C3B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();
}
void drawWall3(double thickness, double scale) {

	// Row One
	glPushMatrix();
	glColor3d(W3R1C1R / 255, W3R1C1G / 255, W3R1C1B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R1C2R / 255, W3R1C2G / 255, W3R1C2B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R1C3R / 255, W3R1C3G / 255, W3R1C3B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row two
	glPushMatrix();
	glColor3d(W3R2C1R / 255, W3R2C1G / 255, W3R2C1B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R2C2R / 255, W3R2C2G / 255, W3R2C2B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R2C3R / 255, W3R2C3G / 255, W3R2C3B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row Three
	glPushMatrix();
	glColor3d(W3R3C1R / 255, W3R3C1G / 255, W3R3C1B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R3C2R / 255, W3R3C2G / 255, W3R3C2B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W3R3C3R / 255, W3R3C3G / 255, W3R3C3B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();
}
void drawWall4(double thickness, double scale) {

	// Row One
	glPushMatrix();
	glColor3d(W4R1C1R / 255, W4R1C1G / 255, W4R1C1B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R1C2R / 255, W4R1C2G / 255, W4R1C2B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R1C3R / 255, W4R1C3G / 255, W4R1C3B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row two
	glPushMatrix();
	glColor3d(W4R2C1R / 255, W4R2C1G / 255, W4R2C1B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R2C2R / 255, W4R2C2G / 255, W4R2C2B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R2C3R / 255, W4R2C3G / 255, W4R2C3B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row Three
	glPushMatrix();
	glColor3d(W4R3C1R / 255, W4R3C1G / 255, W4R3C1B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R3C2R / 255, W4R3C2G / 255, W4R3C2B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W4R3C3R / 255, W4R3C3G / 255, W4R3C3B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();
}
void drawWall5(double thickness, double scale) {

	// Row One
	glPushMatrix();
	glColor3d(W5R1C1R / 255, W5R1C1G / 255, W5R1C1B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R1C2R / 255, W5R1C2G / 255, W5R1C2B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R1C3R / 255, W5R1C3G / 255, W5R1C3B / 255);
	glTranslated(0.10, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row two
	glPushMatrix();
	glColor3d(W5R2C1R / 255, W5R2C1G / 255, W5R2C1B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R2C2R / 255, W5R2C2G / 255, W5R2C2B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R2C3R / 255, W5R2C3G / 255, W5R2C3B / 255);
	glTranslated(0.20, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	//Row Three
	glPushMatrix();
	glColor3d(W5R3C1R / 255, W5R3C1G / 255, W5R3C1B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.10);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R3C2R / 255, W5R3C2G / 255, W5R3C2B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.20);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(W5R3C3R / 255, W5R3C3G / 255, W5R3C3B / 255);
	glTranslated(0.30, 0.5 * thickness, 0.30);
	glScaled(scale, thickness, scale);
	glutSolidCube(1);
	glPopMatrix();
}

void drawTableLeg(double thick, double len) {
	glPushMatrix();
	glTranslated(0, len / 2, 0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawJackPart() {
	glPushMatrix();
	glScaled(0.2, 0.2, 1.0);
	glutSolidSphere(1, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 1.2);
	glutSolidSphere(0.2, 15, 15);
	glTranslated(0, 0, -2.4);
	glutSolidSphere(0.2, 15, 15);
	glPopMatrix();
}

void drawJack() {
	glPushMatrix();
	drawJackPart();
	glRotated(90.0, 0, 1, 0);
	drawJackPart();
	glRotated(90.0, 1, 0, 0);
	drawJackPart();
	glPopMatrix();
}

void drawTable(double topWid, double topThick, double legThick, double legLen){
	glPushMatrix();
	glTranslated(0, legLen, 0);
	glScaled(topWid, topThick, topWid);
	glutSolidCube(1.0);
	glPopMatrix();

	double dist = 0.95*topWid / 2.0 - legThick / 2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(-2 * dist, 0, 2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glPopMatrix();
}

void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
	//gluPerspective(1200, 640 / 480, 0.001, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.1 + moveX, 0.1+moveY, 0.1+moveZ, 0.0 + moveX, 0.0+moveY, 0.0+moveZ, 0.0, 1.0, 0.0);
	gluLookAt(0.1 + eyeX, 0.1 + eyeY, 0.1 + eyeZ, 0.0 + centerX, 0.0 + centerY, 0.0 + centerY, 0.0+upX, 1.0+upY, 0.0+upZ);
}
void Keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'r':
		eyeX = eyeY = eyeZ = centerX = centerY = centerZ = upX = upY = upZ = cubeAngleX=cubeAngleY= cubeAngleZ=0;
		break;
	case 'q':
		eyeX += 0.01;
		break;
	case 'w':
		eyeY += 0.01;
		break;
	case 'e':
		eyeZ += 0.01;
		break;
	case 'a':
		eyeX -= 0.01;
		break;
	case 's':
		eyeY -= 0.01;
		break;
	case 'd':
		eyeZ -= 0.01;
		break;
	case 'i':
		centerX += 0.01;
		break;
	case 'o':
		centerY += 0.01;
		break;
	case 'p':
		centerZ += 0.01;
		break;
	case 'j':
		centerX -= 0.01;
		break;
	case 'k':
		centerY -= 0.01;
		break;
	case 'l':
		centerZ -= 0.01;
		break;

	case 'f':
		sysX += 0.01;
		break;
	case 'g':
		sysY += 0.01;
		break;
	case 'h':
		sysZ += 0.01;
		break;
	case 'v':
		sysX -= 0.01;
		break;
	case 'b':
		sysY -= 0.01;
		break;
	case 'n':
		sysZ -= 0.01;
		break;

	case 'z':
		cubeAngleZ = cubeAngleZ + 1 % 360;
		break;
	case 'x':
		cubeAngleX = cubeAngleX + 1 % 360;
		break;
	case 'c':
		cubeAngleY = cubeAngleY + 1 % 360;
		break;
	case'1'://S 2 times for Front View
		eyeX = -0.1; eyeY = -0.08; eyeZ = -0.01;
		centerX, centerY, centerZ = 0;
		angleX,angleY, angleZ = 0;
		sysX = -0.27; sysY = -0.36; sysZ = 0.06;
		break;
	case '2':
		eyeX = -0.37; eyeY = -0.09; eyeZ = 0;
		centerX = -0; centerY, centerZ = 0;
		angleX, angleZ = 0; cubeAngleY = 22;
		sysX = -1.41; sysY = -0.42; sysZ = 0.14;
		break;
	case '3':
		eyeX = -0.01; eyeY = 0.32; eyeZ = -0.1;
		centerX = 0; centerY, centerZ = 0;
		angleX, angleZ = 0; cubeAngleY = 0;
		sysX = -0.01; sysY = 1.14; sysZ = -0.35;
		break;
	case '4':
		gameSpeed = 50;
		break;
	case '5':
		gameSpeed = 350;
		break;


	}
	printf("Eyes:(%f,%f,%f) \n",eyeX, eyeY, eyeZ);
	printf("Center:(%f,%f,%f) \n", centerX, centerY, centerZ);

	printf("Angle:(%f,%f,%f) \n", cubeAngleX, cubeAngleY, cubeAngleZ);
	printf("Translation:(%f,%f,%f) \n", sysX, sysY, sysZ);

	glutPostRedisplay();
}

void randomizeWall1(){
	W1R1C1R = rand() % 255 + 1;
	W1R1C1G = rand() % 255 + 1;
	W1R1C1B = rand() % 255 + 1;
	W1R1C2R = rand() % 255 + 1;
	W1R1C2G = rand() % 255 + 1;
	W1R1C2B = rand() % 255 + 1;
	W1R1C3R = rand() % 255 + 1;
	W1R1C3G = rand() % 255 + 1;
	W1R1C3B = rand() % 255 + 1;
	W1R2C1R = rand() % 255 + 1;
	W1R2C1G = rand() % 255 + 1;
	W1R2C1B = rand() % 255 + 1;
	W1R2C2R = rand() % 255 + 1;
	W1R2C2G = rand() % 255 + 1;
	W1R2C2B = rand() % 255 + 1;
	W1R2C3R = rand() % 255 + 1;
	W1R2C3G = rand() % 255 + 1;
	W1R2C3B = rand() % 255 + 1;
	W1R3C1R = rand() % 255 + 1;
	W1R3C1G = rand() % 255 + 1;
	W1R3C1B = rand() % 255 + 1;
	W1R3C2R = rand() % 255 + 1;
	W1R3C2G = rand() % 255 + 1;
	W1R3C2B = rand() % 255 + 1;
	W1R3C3R = rand() % 255 + 1;
	W1R3C3G = rand() % 255 + 1;
	W1R3C3B = rand() % 255 + 1;
	glutPostRedisplay();
}
void randomizeWall2(){
	W2R1C1R = rand() % 255 + 1;
	W2R1C1G = rand() % 255 + 1;
	W2R1C1B = rand() % 255 + 1;
	W2R1C2R = rand() % 255 + 1;
	W2R1C2G = rand() % 255 + 1;
	W2R1C2B = rand() % 255 + 1;
	W2R1C3R = rand() % 255 + 1;
	W2R1C3G = rand() % 255 + 1;
	W2R1C3B = rand() % 255 + 1;
	W2R2C1R = rand() % 255 + 1;
	W2R2C1G = rand() % 255 + 1;
	W2R2C1B = rand() % 255 + 1;
	W2R2C2R = rand() % 255 + 1;
	W2R2C2G = rand() % 255 + 1;
	W2R2C2B = rand() % 255 + 1;
	W2R2C3R = rand() % 255 + 1;
	W2R2C3G = rand() % 255 + 1;
	W2R2C3B = rand() % 255 + 1;
	W2R3C1R = rand() % 255 + 1;
	W2R3C1G = rand() % 255 + 1;
	W2R3C1B = rand() % 255 + 1;
	W2R3C2R = rand() % 255 + 1;
	W2R3C2G = rand() % 255 + 1;
	W2R3C2B = rand() % 255 + 1;
	W2R3C3R = rand() % 255 + 1;
	W2R3C3G = rand() % 255 + 1;
	W2R3C3B = rand() % 255 + 1;
	glutPostRedisplay();
}
void randomizeWall3(){
	W3R1C1R = rand() % 255 + 1;
	W3R1C1G = rand() % 255 + 1;
	W3R1C1B = rand() % 255 + 1;
	W3R1C2R = rand() % 255 + 1;
	W3R1C2G = rand() % 255 + 1;
	W3R1C2B = rand() % 255 + 1;
	W3R1C3R = rand() % 255 + 1;
	W3R1C3G = rand() % 255 + 1;
	W3R1C3B = rand() % 255 + 1;
	W3R2C1R = rand() % 255 + 1;
	W3R2C1G = rand() % 255 + 1;
	W3R2C1B = rand() % 255 + 1;
	W3R2C2R = rand() % 255 + 1;
	W3R2C2G = rand() % 255 + 1;
	W3R2C2B = rand() % 255 + 1;
	W3R2C3R = rand() % 255 + 1;
	W3R2C3G = rand() % 255 + 1;
	W3R2C3B = rand() % 255 + 1;
	W3R3C1R = rand() % 255 + 1;
	W3R3C1G = rand() % 255 + 1;
	W3R3C1B = rand() % 255 + 1;
	W3R3C2R = rand() % 255 + 1;
	W3R3C2G = rand() % 255 + 1;
	W3R3C2B = rand() % 255 + 1;
	W3R3C3R = rand() % 255 + 1;
	W3R3C3G = rand() % 255 + 1;
	W3R3C3B = rand() % 255 + 1;
	glutPostRedisplay();
}
void randomizeWall4(){
	W4R1C1R = rand() % 255 + 1;
	W4R1C1G = rand() % 255 + 1;
	W4R1C1B = rand() % 255 + 1;
	W4R1C2R = rand() % 255 + 1;
	W4R1C2G = rand() % 255 + 1;
	W4R1C2B = rand() % 255 + 1;
	W4R1C3R = rand() % 255 + 1;
	W4R1C3G = rand() % 255 + 1;
	W4R1C3B = rand() % 255 + 1;
	W4R2C1R = rand() % 255 + 1;
	W4R2C1G = rand() % 255 + 1;
	W4R2C1B = rand() % 255 + 1;
	W4R2C2R = rand() % 255 + 1;
	W4R2C2G = rand() % 255 + 1;
	W4R2C2B = rand() % 255 + 1;
	W4R2C3R = rand() % 255 + 1;
	W4R2C3G = rand() % 255 + 1;
	W4R2C3B = rand() % 255 + 1;
	W4R3C1R = rand() % 255 + 1;
	W4R3C1G = rand() % 255 + 1;
	W4R3C1B = rand() % 255 + 1;
	W4R3C2R = rand() % 255 + 1;
	W4R3C2G = rand() % 255 + 1;
	W4R3C2B = rand() % 255 + 1;
	W4R3C3R = rand() % 255 + 1;
	W4R3C3G = rand() % 255 + 1;
	W4R3C3B = rand() % 255 + 1;
	glutPostRedisplay();
}
void randomizeWall5(){
	W5R1C1R = rand() % 255 + 1;
	W5R1C1G = rand() % 255 + 1;
	W5R1C1B = rand() % 255 + 1;
	W5R1C2R = rand() % 255 + 1;
	W5R1C2G = rand() % 255 + 1;
	W5R1C2B = rand() % 255 + 1;
	W5R1C3R = rand() % 255 + 1;
	W5R1C3G = rand() % 255 + 1;
	W5R1C3B = rand() % 255 + 1;
	W5R2C1R = rand() % 255 + 1;
	W5R2C1G = rand() % 255 + 1;
	W5R2C1B = rand() % 255 + 1;
	W5R2C2R = rand() % 255 + 1;
	W5R2C2G = rand() % 255 + 1;
	W5R2C2B = rand() % 255 + 1;
	W5R2C3R = rand() % 255 + 1;
	W5R2C3G = rand() % 255 + 1;
	W5R2C3B = rand() % 255 + 1;
	W5R3C1R = rand() % 255 + 1;
	W5R3C1G = rand() % 255 + 1;
	W5R3C1B = rand() % 255 + 1;
	W5R3C2R = rand() % 255 + 1;
	W5R3C2G = rand() % 255 + 1;
	W5R3C2B = rand() % 255 + 1;
	W5R3C3R = rand() % 255 + 1;
	W5R3C3G = rand() % 255 + 1;
	W5R3C3B = rand() % 255 + 1;
	glutPostRedisplay();
}

void print(float x, float y, float z, char* string)
{
	int len, i;
	glRasterPos3f(x, y, z);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void timer(int v){
	frames++;
	jump++;
	sturidge++;
	shuffle++;
	floss++;
	if (frames % 10==0){
		//Switch Colors
		//rand() % 255 + 1;
		randomizeWall1();
		randomizeWall2();
		randomizeWall3();
		randomizeWall4();
		randomizeWall5();
		
	}
	//sysX = -7.01; sysY = 7.14; sysZ = -7.35;

	printf("%d \n", frames);
	//Dance 1 (Jump)
	if (frames > 0 && frames<=500){

		if (jump % 5 == 0){
			minionY = 0.01;
		}
		else{
			minionY = 0;
		}
		sturidge = 0;
	}
	else if (frames > 500 && frames<=1250){			//Dance 2 (Sturidge)
		if (sturidge >10.0 && sturidge<25.0){
			leftArm = 0.015;
			RightArm = 0;
		}
		else{
			leftArm = 0;
			RightArm = 0.015;
			if (sturidge == 30){
				sturidge = 0;
				RightArm = 0;
				leftArm = 0;
			}
		}
		shuffle = 0;
	}
	else if (frames > 1250 && frames<=1750){	//Dance 3 (Shuffle)
		if (shuffle >10.0 && shuffle<25.0){
			leftLeg = 0.007;
			RightLeg = -0.007;
			minionY = 0.005;
			angleY = angleY + 0.25;
		}
		else{
			leftLeg = -0.007;
			RightLeg = 0.007;
			minionY = 0;
			angleY = angleY - 0.25;
			if (shuffle == 30){
				shuffle = 0;
				leftLeg, RightLeg = 0;
				minionY, angleY = 0;
			}
		}
		jump = 0; 
		sturidge = 0;
		floss = 0;

	}
	else if (sturidge >10.0 && sturidge<25.0){ //Jump again 

		if (jump % 5 == 0){
			minionY = 0.02;
		}
		else{
			minionY = 0;
		}
		floss = 0;
		/*sturidge = 0;*/
	}
	//else if (frames > 0 && frames<=500){ //Floss
	//	
	//	if (floss >10.0 && floss<25.0){
	//		flossL = -0.01;
	//		flossR = 0.01;
	//		RightArm = -0.01;
	//		leftArm = -0.01;
	//		angleY = angleY - 0.05;
	//	}
	//	else{
	//		if (floss == 35){
	//			floss = 0;
	//		}
	//		flossL, flossR = 0;
	//		//minionY = 0.005;
	//		leftArm = 0.01;
	//		RightArm = 0.01;
	//		angleY = angleY + 0.05;
	//	}
	//}
	else if (frames > 1750 && frames<=2000){ //Floss
	
		if (frames % 3 == 0)
		{
			angleY = 4;
		}
		else{
			angleY = -4;
		}
	}
	else {
		angleY = 0;
		PlaySound(0, 0, 0);
		eyeX = -0.01; eyeY = 0.32; eyeZ = -0.1;
		centerX = 0; centerY, centerZ = 0;
		angleX, angleZ = 0; cubeAngleY = 0;
		sysX = -7.01; sysY = 7.14; sysZ = -7.35;
		px, py, pz = 0;
	}

	

	

	

	glutPostRedisplay();
	glutTimerFunc(gameSpeed, timer, 0);
	
}

void Display() {
	setupLights();
	setupCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslated(sysX, sysY, sysZ);
	glRotated(cubeAngleX, 1.0, 0, 0);
	glRotated(cubeAngleY, 0, 1.0, 0);
	glRotated(cubeAngleZ, 0, 0, 1.0);
	
	//Wall 1
	glPushMatrix();
	glTranslated(-0.02*scale, -0.02*scale, -0.04*scale);
	glRotated(90, 0, 0, 1.0);
	glScaled(scale, scale, scale);
	drawWall(0.02, 0.1);
	glPopMatrix();

	//Wall 2
	glPushMatrix();
	glTranslated(-0.09*scale, 0.01*scale, -0.05*scale);
	glRotated(0, 0, 0, 1.0);
	glScaled(scale, scale, scale);
	drawWall2(0.02, 0.1);
	glPopMatrix();

	//Wall 3
	glPushMatrix();
	glTranslated(-0.09*scale, -0.03*scale, 0.02*scale);
	glRotated(-90, 1.0, 0, 0);
	glScaled(scale, scale, scale);
	drawWall3(0.02, 0.1);
	glPopMatrix();

	//Wall 4
	glPushMatrix();
	glTranslated(0.24*scale, 0.375*scale, -0.04*scale);
	glRotated(-90, 0, 0, 1.0);
	glScaled(scale, scale, scale);
	drawWall4(0.02, 0.1);
	glPopMatrix();

	//Wall 5
	glPushMatrix();
	glTranslated(-0.09*scale, 0.32*scale, -0.04*scale);
	glRotated(0, 0, 0, 1.0);
	glScaled(scale, scale, scale);
	drawWall5(0.02, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.09 + minionX, 0.05 + minionY, -0.05 + minionZ);
	/*glRotated(angleY, 0, 1.0, 0);*/
	drawSuperman(0.25, 0.07);
	glPopMatrix();

	
	glPopMatrix();

	glPushMatrix();
	glTranslated(px, py, pz);
	print(0.0f, 0.0f, 0.0f, "The End");
	glPopMatrix();


	//text
	
		
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Lab 5");
	bool played = PlaySound(TEXT("C:/Users/Youssef Shalaby/Downloads/wavs.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(0, timer, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}