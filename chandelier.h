#include <GL/glut.h>

void cup() {
	glPushMatrix(); {
		glScalef(0.7, 0.7, 1);
		glColor3f(0.45, 0.35, 0.05);
		GLUquadric *quad;
		quad = gluNewQuadric();
		gluCylinder(quad, 10, 1, 5, 200, 200);
		glPushMatrix(); {
			glColor3f(0.9, 0.9, 0.9);
			double equ[4];
			equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 0;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				glPushMatrix(); {
					equ[0] = 0; equ[1] = 0; equ[2] = 1; equ[3] = 20;
					glClipPlane(GL_CLIP_PLANE1, equ);
					glEnable(GL_CLIP_PLANE1); {
						glScalef(1.2, 1.2, 1.5);
						glTranslatef(0, 0, -18);
						glutSolidSphere(20, 200, 200);
					}
					glDisable(GL_CLIP_PLANE1);
					
				}
				glPopMatrix();
			}
			glDisable(GL_CLIP_PLANE0);
		}
		glPopMatrix();
		/*
		glPushMatrix(); {
			glTranslatef(0, 0, -0.3);
			glColor3f(0.7, 0.7, 0.7);
			//glScalef(1, 1, 1.3);
			float k = 9.2;
			for (; k < 15; ) {
				glTranslatef(0, 0, -0.1);
				glutSolidTorus(0.6, k, 50, 50); 
				if (k < 13) k += 0.04;
				else k += 0.05;
			}
			for (float z = 0; z < 1; z += 0.05) {
				glTranslatef(0, 0, -0.1);
				glutSolidTorus(0.6, k-z, 50, 50);
			}
			
		}
		glPopMatrix();
		*/
	}
	glPopMatrix();
}

void curve() {
	double equ[4];
	equ[0] = 0; equ[1] = 0; equ[2] = 1; equ[3] = 0;
	glClipPlane(GL_CLIP_PLANE0, equ);
	glEnable(GL_CLIP_PLANE0); {
		glPushMatrix(); {
			glScalef(2, 1, 1);
			glColor3f(0.45, 0.35, 0.05);
			glRotatef(90, 1, 0, 0);
			glTranslatef(15, 0, 0);
			glutSolidTorus(0.5, 10, 200, 200);
		}
		glPopMatrix();
	}
	glDisable(GL_CLIP_PLANE0);
	glPushMatrix(); {
		glTranslatef(50, 0, -5);
		cup();
	}
	glPopMatrix();


}
void drawChandelier(float angle) {
	glPushMatrix(); {
		glScalef(0.5, 0.5, 0.5); 
		glRotatef(angle, 0, 0, 1);
		glColor3f(0.7, 0.7, 0.7);
		GLUquadric *quad;
		quad = gluNewQuadric();
		gluCylinder(quad, 10, 10, 2, 200, 200);
		glColor3f(0.45, 0.35, 0.05);
		gluDisk(quad, 0, 10, 200, 200);
		glPushMatrix(); {
			glColor3f(0.45, 0.35, 0.05);
			glTranslatef(0, 0, 2);
			gluDisk(quad, 0, 10, 200, 200);
			glBegin(GL_LINES); {
				glVertex3f(0, 10, 0);
				glVertex3f(0, 10, 100);
			}
			glEnd();
			glBegin(GL_LINES); {
				glVertex3f(10, 0, 0);
				glVertex3f(10, 0, 100);
			}
			glEnd();
			glBegin(GL_LINES); {
				glVertex3f(0, -10, 0);
				glVertex3f(0, -10, 100);
			}
			glEnd();
			glBegin(GL_LINES); {
				glVertex3f(-10, 0, 0);
				glVertex3f(-10, 0, 100);
			}
			glEnd();
		}
		glPopMatrix();
		glColor3f(1, 1, 1);
		for (int k = 0; k < 6; k++) {
			float theta = 60 * k;
			float x = 15 * cos(theta);
			float y = 15 * sin(theta);
			glPushMatrix(); {
				//glTranslatef(x, y, 0);
				glRotatef(theta, 0, 0, 1);
				curve();
				
			}
			glPopMatrix();
		}
		
	}
	glPopMatrix();
}

