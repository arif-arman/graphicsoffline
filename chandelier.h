#include <GL/glut.h>
void curve() {
	double equ[4];
	equ[0] = 0; equ[1] = 0; equ[2] = 1; equ[3] = 0;
	glClipPlane(GL_CLIP_PLANE0, equ);
	glEnable(GL_CLIP_PLANE0); {
		glPushMatrix(); {
			glScalef(2, 1, 1);
			glColor3f(1, 1, 1);
			glRotatef(90, 1, 0, 0);
			glTranslatef(15, 0, 0);
			glutSolidTorus(0.5, 10, 200, 200);
		}
		glPopMatrix();
	}
	glDisable(GL_CLIP_PLANE0);

}
void drawChandelier() {
	glPushMatrix(); {
		glColor3f(0, 0, 1);
		GLUquadric *quad;
		quad = gluNewQuadric();
		gluCylinder(quad, 10, 10, 2, 200, 200);
		glColor3f(0.7, 0.7, 0.7);
		gluDisk(quad, 0, 10, 200, 200);
		glPushMatrix(); {
			glColor3f(0.7, 0.7, 0.7);
			glTranslatef(0, 0, 2);
			gluDisk(quad, 0, 10, 200, 200);
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

