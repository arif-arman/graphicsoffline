#include <GL\glut.h>


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
			GLUquadric *quad;
			quad = gluNewQuadric();
			gluCylinder(quad, 5, 3.5, 20, 200, 200);
			glTranslatef(0, 0, -0.5);
			glPushMatrix(); {
				glTranslatef(0, 0, -0.5); 
				glColor3f(1, 0, 0);
				for (float k = 4.5; k > 2; k -= 0.1) {
					glTranslatef(0, 0, -0.1);
					glutSolidTorus(1, k, 200, 200);
				}
			}
			glPopMatrix();
			*/
			
		}
		glDisable(GL_CLIP_PLANE0);
		
		
		
	}
	glPopMatrix();
}