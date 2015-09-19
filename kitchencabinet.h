#include <GL/glut.h>
void drawKitchenCabinet(int param) {
	glPushMatrix(); {
		glTranslatef(0, 0, 20);
		glScalef(1, 1, 2);
		for (int i = 0; i < 3; i++) {
			if (!i) glTranslatef(30 * param, 0, 0);
			else glTranslatef(20 * param, 0, 0);
			glColor3f(0.5, 0.38, 0.05);
			glutSolidCube(20);

			for (float k = 0; k < 3; k += 0.05) {
				glBegin(GL_QUADS); {
					glVertex3f(10, 10 + k, 10);
					glVertex3f(-10, 10 + k, 10);
					glVertex3f(-10, 10 + k, -10);
					glVertex3f(10, 10 + k, -10);
				}
				glEnd();
			}
			for (float i = 0; i < 3; i += 0.05) {
				glColor3f(0.5, 0.35, 0.05);
				glBegin(GL_QUADS); {
					glVertex3f(10, 12 + i, 10);
					glVertex3f(8, 12 + i, 10);
					glVertex3f(8, 12 + i, -10);
					glVertex3f(10, 12 + i, -10);
				}
				glEnd();
				glBegin(GL_QUADS); {
					glVertex3f(10, 12 + i, 10);
					glVertex3f(10, 12 + i, 8);
					glVertex3f(-10, 12 + i, 8);
					glVertex3f(-10, 12 + i, 10);
				}
				glEnd();
				glBegin(GL_QUADS); {
					glVertex3f(-10, 12 + i, 10);
					glVertex3f(-8, 12 + i, 10);
					glVertex3f(-8, 12 + i, -10);
					glVertex3f(-10, 12 + i, -10);
				}
				glEnd();
				glBegin(GL_QUADS); {
					glVertex3f(10, 12 + i, -10);
					glVertex3f(10, 12 + i, -8);
					glVertex3f(-10, 12 + i, -8);
					glVertex3f(-10, 12 + i, -10);
				}
				glEnd();
			}
			for (float k = 0; k < 1; k += 0.05) {
				glColor3f(1, 1, 1);
				glBegin(GL_QUADS); {
					glVertex3f(14, 16, 10 + k);
					glVertex3f(-14, 16, 10 + k);
					glVertex3f(-14, -12, 10 + k);
					glVertex3f(14, -12, 10 + k);
				}
				glEnd();
			}
			glPushMatrix(); {
				glColor3f(0.9, 0.9, 0.8);
				glTranslatef(0, 14.5, 8.7);
				glutSolidTorus(0.2, 5, 200, 200);
			}
			glPopMatrix();


		}

	}
	glPopMatrix();


}
