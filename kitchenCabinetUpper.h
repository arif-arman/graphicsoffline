#include<GL/glut.h>
#define gray 0.5, 0.5, 0.5
#define dark_gray 0.8, 0.8, 0.8

void drawKitchenCabinetUpper() {
	glPushMatrix(); {
		glScalef(2, 1, 1);
		for (int l = 0; l < 2; l++) {
			glTranslatef(0, 0, 10 + 10*l);
			glPushMatrix(); {
				for (int k = 0; k < 2; k++) {
					glTranslatef(10 + 10 * k, 0, 0);
					glColor3f(dark_gray);
					glutSolidCube(20);
					for (float i = 0; i < 1; i += 0.05) {
						glColor3f(gray);
						glBegin(GL_QUADS); {
							float y = 10 + i;
							glVertex3f(8, y, 6);
							glVertex3f(8, y, -6);
							glVertex3f(-8, y, -6);
							glVertex3f(-8, y, 6);
						}
						glEnd();
					}
					for (float i = 0; i < 1.2; i += 0.05) {
						glColor3f(dark_gray);
						float y = 10 + i;
						glBegin(GL_QUADS); {
							glVertex3f(10, y, 10);
							glVertex3f(8, y, 10);
							glVertex3f(8, y, -10);
							glVertex3f(10, y, -10);
						}
						glEnd();
						glBegin(GL_QUADS); {
							glVertex3f(10, y, 10);
							glVertex3f(10, y, 6);
							glVertex3f(-10, y, 6);
							glVertex3f(-10, y, 10);
						}
						glEnd();
						glBegin(GL_QUADS); {
							glVertex3f(-10, y, 10);
							glVertex3f(-8, y, 10);
							glVertex3f(-8, y, -10);
							glVertex3f(-10, y, -10);
						}
						glEnd();
						glBegin(GL_QUADS); {
							glVertex3f(10, y, -10);
							glVertex3f(10, y, -6);
							glVertex3f(-10, y, -6);
							glVertex3f(-10, y, -10);
						}
						glEnd();
					}
					
					

				}
			}
			
			glPopMatrix();
			
			glPushMatrix(); {
				if(l) {
					for (int k = 0; k < 2; k++) {
						glTranslatef(10 + 10 * k, 0, 0);
						glColor3f(0.2, 0.2, 0.2);
						for (float m = 0; m < 1; m += 0.05) {
							glBegin(GL_QUADS); {
								float z = -10 - m;
								glVertex3f(10.2, 11.5, z);
								glVertex3f(-10.2, 11.5, z);
								glVertex3f(-10.2, -10, z);
								glVertex3f(10.2, -10, z);
							}
							glEnd();
						}
					}
				}
			}
			glPopMatrix();
			
			

		}
		

	}
	glPopMatrix();
	

}
