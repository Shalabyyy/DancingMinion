#include "glut.h" 


int speed = 20;
int time_elapsed = 0;
float RL1 = 0.0f; float GL1 = 0.0f; float BL1 = 1.0f;
float RL2 = 1.0f; float GL2 = 0.0f; float BL2 = 0.0f;
float RL3 = 1.0f; float GL3 = 1.0f; float BL3 = 0.0f;
float RL4 = 0.0f; float GL4 = 1.0f; float BL4 = 1.0f;

float RB1 = 0.0f; float GB1 = 0.0f; float BB1 = 1.0f;
float RB2 = 1.0f; float GB2 = 0.0f; float BB2 = 0.0f;
float RB3 = 1.0f; float GB3 = 1.0f; float BB3 = 0.0f;
float RB4 = 0.0f; float GB4 = 1.0f; float BB4 = 1.0f;

float RK1 = 0.0f; float GK1 = 0.0f; float BK1 = 1.0f;
float RK2 = 1.0f; float GK2 = 0.0f; float BK2 = 0.0f;
float RK3 = 1.0f; float GK3 = 1.0f; float BK3 = 0.0f;
float RK4 = 0.0f; float GK4 = 1.0f; float BK4 = 1.0f;

//<<<<<<<<<<<<<<<<<<< axis >>>>>>>>>>>>>> 
void axis(double length) { // draw a z-axis, with cone at end  
	glPushMatrix();



	glBegin(GL_LINES);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, length); // along the z-axis 
	glEnd();

	glTranslated(0, 0, length - 0.2);
	glutWireCone(0.04, 0.2, 12, 9);

	glPopMatrix();
}
void drawDancer(){
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslated(0.5, 0.5, 0.5); // sphere at (1,1,0)
	glutWireSphere(0.125, 5, 5);
	glPopMatrix();

	glPushMatrix(); 
	glRotated(45, 1, 1, 0);
	glTranslated(1,1, 0.5); // cone at (1,0,1)     
	glutWireCone(0.2, 0.5, 10, 8);     
	glPopMatrix();

	glPopMatrix();

}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displayWire(void) {

	glClear(GL_COLOR_BUFFER_BIT); // clear the screen  

	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-2.0 * 640 / 480.0, 2.0 * 640 / 480.0, -2.0, 2.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);




	glColor3d(0, 0, 0); // draw black lines     
	
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	// Top face (y = 1.0f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom face (y = -1.0f) SIDE 1
	glColor3f(RB1, RB2, RB3);     // Orange
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3f(RB2, GB2, BB2);     // Red
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(RB3, GB3, BB3);     // Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(RB4, GB4, BB4);     // Magenta
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 1.0f);
	

	// Left face (x = -1.0f) SIDE 2
	glColor3f(RL1, GL1, BL1);     // Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(RL2, GL2, BL2);     // Red
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glColor3f(RL3, GL3, BL3);     // Yellow
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glColor3f(RL4, GL4, BL4);     // Magenta
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);

	// Back face (z = -1.0f) SIDE 3
	glColor3f(RK1, GK2, BK2);     // Black
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glColor3f(RK2, GK2, BK2);     // Red
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(RK3, GK3, BK3);     // Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(RK4, GK4, BK4);     // Magenta
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 1.0f, -1.0f);
	


	glEnd();  // End of drawing color-cube

	drawDancer();
	//glutWireCube(1.0); //biggest cube at the origin of the three axis



	glFlush();
}


void timer(int val){
	time_elapsed++;
	if (time_elapsed % 250 == 0){
		RL1 = 1.0f;   GL1 = 0.0f;   BL1 = 0.0f; //RCGMBY 101
		RL2 = 0.0f;   GL2 = 1.0f;   BL2 = 1.0f; //011
		RL3 = 0.0f;   GL3 = 1.0f;   BL3 = 0.0f; //010
		RL4 = 1.0f;   GL4 = 0.0f;   BL4 = 1.0f; //101
		//001
		//110

	}
	else if (time_elapsed % 200 == 0){
		RL1 = 0.0f;   GL1 = 1.0f;   BL1 = 1.0f; //RCGMBY
		RL2 = 0.0f;   GL2 = 0.0f;   BL2 = 1.0f;
		RL3 = 1.0f;   GL3 = 0.0f;   BL3 = 1.0f;
		RL4 = 0.0f;   GL4 = 0.0f;   BL4 = 1.0f;

	}
	else if (time_elapsed % 150 == 0){
		RL1 = 0.0f;   GL1 = 1.0f;   BL1 = 0.0f; //RCGMBY
		RL2 = 1.0f;   GL2 = 0.0f;   BL2 = 1.0f;
		RL3 = 0.0f;   GL3 = 0.0f;   BL3 = 1.0f;
		RL4 = 1.0f;   GL4 = 1.0f;   BL4 = 0.0f;

	}
	else if (time_elapsed % 100 == 0){
		RL1 = 1.0f;   GL1 = 0.0f;   BL1 = 1.0f;
		RL2 = 0.0f;   GL2 = 0.0f;   BL2 = 1.0f;
		RL3 = 1.0f;   GL3 = 1.0f;   BL3 = 0.0f;
		RL4 = 1.0f;   GL4 = 0.0f;   BL4 = 0.0f;

	}
	else if (time_elapsed % 50 == 0){
		  RL1 = 0.0f;   GL1 = 0.0f;   BL1 = 1.0f;
		  RL2 = 1.0f;   GL2 = 1.0f;   BL2 = 0.0f;
		  RL3 = 1.0f;   GL3 = 0.0f;   BL3 = 0.0f;
		  RL4 = 0.0f;   GL4 = 1.0f;   BL4 = 1.0f;

	}

	if (time_elapsed % 250 == 0){
		RB1 = 1.0f;   GB1 = 0.0f;   BB1 = 0.0f; //RCGMBY 101
		RB2 = 0.0f;   GB2 = 1.0f;   BB2 = 1.0f; //011
		RB3 = 0.0f;   GB3 = 1.0f;   BB3 = 0.0f; //010
		RB4 = 1.0f;   GB4 = 0.0f;   BB4 = 1.0f; //101
		//001
		//110

	}
	else if (time_elapsed % 200 == 0){
		RB1 = 0.6f;   GB1 = 1.0f;   BB1 = 1.0f; //RCGMBY
		RB2 = 0.0f;   GB2 = 0.4f;   BB2 = 1.0f;
		RB3 = 1.0f;   GB3 = 0.4f;   BB3 = 1.0f;
		RB4 = 0.3f;   GB4 = 0.4f;   BB4 = 1.0f;

	}
	else if (time_elapsed % 150 == 0){
		RB1 = 0.0f;   GB1 = 1.0f;   BB1 = 0.4f; //RCGMBY
		RB2 = 1.0f;   GB2 = 0.4f;   BB2 = 1.0f;
		RB3 = 0.0f;   GB3 = 0.4f;   BB3 = 1.0f;
		RB4 = 1.0f;   GB4 = 1.0f;   BB4 = 0.4f;

	}
	else if (time_elapsed % 100 == 0){
		RB1 = 1.0f;   GB1 = 0.4f;   BB1 = 1.0f;
		RB2 = 0.4f;   GB2 = 0.4f;   BB2 = 1.0f;
		RB3 = 1.0f;   GB3 = 1.0f;   BB3 = 0.4f;
		RB4 = 1.0f;   GB4 = 0.4f;   BB4 = 0.04f;

	}
	else if (time_elapsed % 50 == 0){
		RB1 = 0.3f;   GB1 = 0.4f;   BB1 = 1.0f;
		RB2 = 1.0f;   GB2 = 1.0f;   BB2 = 0.4f;
		RB3 = 1.0f;   GB3 = 0.4f;   BB3 = 0.0f;
		RB4 = 0.6f;   GB4 = 1.0f;   BB4 = 1.0f;

	}

	if (time_elapsed % 250 == 0){
		RK1 = 0.85f;   GK1 = 0.0f;   BK1 = 0.0f; //RCGMBY 101
		RK2 = 0.0f;   GK2 = 0.85f;   BK2 = 0.85f; //011
		RK3 = 0.0f;   GK3 = 0.85f;   BK3 = 0.0f; //010
		RK4 = 0.85f;   GK4 = 0.0f;   BK4 = 0.85f; //101
		//001
		//110

	}
	else if (time_elapsed % 200 == 0){
		RK1 = 0.6f;   GK1 = 0.85f;   BK1 = 0.85f; //RCGMBY
		RK2 = 0.0f;   GK2 = 0.4f;   BK2 = 0.85f;
		RK3 = 0.85f;   GK3 = 0.4f;   BK3 = 0.85f;
		RK4 = 0.3f;   GK4 = 0.4f;   BK4 = 0.85f;

	}
	else if (time_elapsed % 150 == 0){
		RK1 = 0.0f;   GK1 = 0.85f;   BK1 = 0.4f; //RCGMBY
		RK2 = 0.85f;   GK2 = 0.4f;   BK2 = 0.85f;
		RK3 = 0.0f;   GK3 = 0.4f;   BK3 = 0.85f;
		RK4 = 0.85f;   GK4 = 0.85f;   BK4 = 0.4f;

	}
	else if (time_elapsed % 100 == 0){
		RK1 = 0.85f;   GK1 = 0.4f;   BK1 = 0.85f;
		RK2 = 0.4f;   GK2 = 0.4f;   BK2 = 0.85f;
		RK3 = 0.85f;   GK3 = 0.85f;   BK3 = 0.4f;
		RK4 = 0.85f;   GK4 = 0.4f;   BK4 = 0.04f;

	}
	else if (time_elapsed % 50 == 0){
		RK1 = 0.3f;   GK1 = 0.4f;   BK1 = 0.85f;
		RK2 = 0.85f;   GK2 = 0.85f;   BK2 = 0.4f;
		RK3 = 0.85f;   GK3 = 0.4f;   BK3 = 0.0f;
		RK4 = 0.6f;   GK4 = 0.85f;   BK4 = 0.85f;

	}
	glutPostRedisplay();
	glutTimerFunc(speed, timer, 0);
	
}
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformation testbed - wireframes");
	glutDisplayFunc(displayWire);
	glutTimerFunc(0, timer, 6);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white  
	//glViewport(0, 0, 640, 480);  // x y width height
	glutMainLoop();
}