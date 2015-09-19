#include <GL\glut.h>

void drawSeat(double x, double y) {
	glPushMatrix(); {
		double equ[4];
		equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 0;
		glClipPlane(GL_CLIP_PLANE0, equ);
		glEnable(GL_CLIP_PLANE0); {
			glRotatef(90, 1, 0, 0);
			glScalef(2.5, 1, 0.6);
			glutSolidTorus(x,y, 200, 200);
		}
		glDisable(GL_CLIP_PLANE0);
	}
	glPopMatrix();
}

void drawLeg() {
	glPushMatrix(); {
			GLUquadric *quad;
			quad = gluNewQuadric();
			gluCylinder(quad, 1, 1, 10, 200, 200);
	}
	glPopMatrix();
}

void drawChair() {

	glPushMatrix(); {
		double equ[4];
		glColor3f(0.7, 0.7, 0.7);
		equ[0] = -1; equ[1] = 0; equ[2] = 0; equ[3] = 0;
		glClipPlane(GL_CLIP_PLANE0, equ);
		glEnable(GL_CLIP_PLANE0); {
			glScalef(1, 2, 1);
			float k = 8;
			for (; k < 10; k += 0.05) {
				glTranslatef(0, 0, -0.5);
				glutSolidTorus(0.5, k, 50, 50);

			}
			for (; k>9.5; k -= 0.1) {
				glTranslatef(0, 0, -0.5);
				glutSolidTorus(0.5, k, 50, 50);

			}
			for (; k>7; k -= 0.1) {
				glTranslatef(0, 0, -0.3);
				glutSolidTorus(0.5, k, 50, 50);
			}
			for (; k<7.5; k += 0.1) {
				glTranslatef(0, 0, -0.3);
				glutSolidTorus(0.5, k, 50, 50);
			}
			for (; k<8.5; k += 0.1) {
				glTranslatef(0, 0, -0.5);
				glutSolidTorus(0.5, k, 50, 50);

			}
			
			/*
			glScalef(1, 2.5, 1);
			
			glPopMatrix();
			*/
			
		}
		glDisable(GL_CLIP_PLANE0);
	}
	glPopMatrix();
	glPushMatrix(); {
		//glColor3f(0, 1, 0);
		glRotatef(3, 0, 1, 0);
		glTranslatef(15.5, 0, -37);
		glPushMatrix(); {
			for (float k = 0; k < 10; k+=.5) {
				glTranslatef(0, 0.8, 0);
				drawSeat(0.5, 6);
			}
		}
		glPopMatrix();
		glPushMatrix(); {
			drawSeat(0.5, 6);
		}
		glPopMatrix();
		glPushMatrix(); {
			for (float k = 0; k < 10; k += .5) {
				glTranslatef(0, -0.8, 0);
				drawSeat(0.5, 6);
			}
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(0.4, 0.4, 0.4);
			glRotatef(5, 0, 1, 0);
			glTranslatef(0, -16.8, 0);
			glScalef(1, 1, 1);
			glPushMatrix(); {
				for (float k = 2; k>1; k -= 0.2) {
					glTranslatef(0, 0, 0.3);
					drawSeat(1.5,5);
				}
			}
			glPopMatrix();
		}
		glPushMatrix(); {
			glColor3f(0.4, 0.4, 0.4);
			glRotatef(0, 0, 1, 0);
			glTranslatef(0, 33.3, -.5);
			glScalef(1, 1, 1);
			glPushMatrix(); {
				for (float k = 2; k>1; k -= 0.2) {
					glTranslatef(0, 0, 0.3);
					drawSeat(1.5, 5);
				}
			}
			glPopMatrix();
		}
		glPopMatrix();

	}
	glPopMatrix();
	glPushMatrix(); {
		glColor3f(0.7, 0.7, 0.7);
		glTranslatef(-6, -15, -35);
		glScalef(0.6, 3, 1);
		glRotatef(45, 0, 1, 0);
		glBegin(GL_QUADS); {
				glVertex3f(0, 0, 0);
				glVertex3f(0, 10, 0);
				glVertex3f(10, 10, 0);
				glVertex3f(10, 0, 0);
			
		}
		glEnd();
		
	}
	glPopMatrix();
	glPushMatrix(); {
		
		glPushMatrix(); {
			glColor3f(1, 0, 0);
			glTranslatef(-6, -6, -60);
			glScalef(1, 1, 2);
			drawLeg();
		}
		glPopMatrix();
	}
	glPopMatrix();
	
}