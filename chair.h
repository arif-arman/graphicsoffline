#include <GL\glut.h>

void leg() {
	glPushMatrix(); {
		glScalef(0.5, 0.5, 0.5);
		double equ[4];
		equ[0] = 0; equ[1] = 1; equ[2] = 0; equ[3] = 0;
		glClipPlane(GL_CLIP_PLANE1, equ);
		glEnable(GL_CLIP_PLANE1); {
			glPushMatrix(); {
				double equ[4];
				equ[0] = 0; equ[1] = 0; equ[2] = 1; equ[3] = 0;
				glClipPlane(GL_CLIP_PLANE0, equ);
				glEnable(GL_CLIP_PLANE0); {
					glRotatef(90, 0, 1, 0);
					glScalef(1, 2, 1);

					glutSolidTorus(0.7, 5, 50, 50);
				}
				glDisable(GL_CLIP_PLANE0);

			}
			glPopMatrix();
			glPushMatrix(); {
				glTranslatef(0, 10, -30);
				GLUquadric *quad;
				quad = gluNewQuadric();
				gluCylinder(quad, 1, 1, 30, 200, 200);
			}
			glPopMatrix();
		}
		glDisable(GL_CLIP_PLANE1);
	}
	glPopMatrix();
	
	

}

void drawChair() {
	glPushMatrix(); {
		glTranslatef(0, 0, 5);
		glPushMatrix(); {
			glColor3f(1, 1, 1);
			glTranslatef(0, 0, 10.5);
			double equ[4];
			equ[0] = 0; equ[1] = -1; equ[2] = 0; equ[3] = 0;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				glScalef(1, .5, 1);
				GLUquadric *quad;
				quad = gluNewQuadric();
				gluCylinder(quad, 10, 7, 20, 200, 200);
			}
			glDisable(GL_CLIP_PLANE0);
			equ[0] = 0; equ[1] = -1; equ[2] = 0; equ[3] = 0;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				for (float k = 10; k > 6; k -= 0.5) {
					glTranslatef(0, 0, -0.5);
					glPushMatrix(); {
						//glScalef(1, 0.5, 1);
						glutSolidTorus(0.5, k, 50, 50);
					}
					glPopMatrix();
				}
				for (float k = 6; k < 8; k += 0.5) {
					glTranslatef(0, 0, -0.5);
					glPushMatrix(); {
						//glScalef(1, 0.5, 1);
						glutSolidTorus(0.5, 6, 50, 50);
					}
					glPopMatrix();
				}
				for (float k = 6; k < 10; k += 0.8) {
					glTranslatef(0, 0, -0.5);
					glPushMatrix(); {
						//glScalef(1, 0.5, 1);
						glutSolidTorus(0.5, k, 50, 50);
					}
					glPopMatrix();
				}
				for (float k = 15; k>0; k --) {
					glTranslatef(0, .8, -0.55);
					glPushMatrix(); {
						//glScalef(1, 0.5, 1);
						glutSolidTorus(0.5, 10.2, 50, 50);
					}
					glPopMatrix();
				}
			}
			glDisable(GL_CLIP_PLANE0);
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(1, 1, 1);
			double equ[4];
			equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 0;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				
				glRotatef(-90, 1, 0, 0);
				glPushMatrix(); {
					glScalef(1, 0.4, 1);
					GLUquadric *quad;
					quad = gluNewQuadric();
					gluCylinder(quad, 10, 14, 20, 200, 200);
				}
				glPopMatrix();
				
			}
			glDisable(GL_CLIP_PLANE0);
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(1, 1, 1);
			for (int k = 0; k < 20; k++) {
				glBegin(GL_LINES); {
					glVertex3f(10.1, -0.1, k*0.1);
					glVertex3f(11.4, 6, 0);
				}
				glEnd();
			}
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(1, 1, 1);
			for (int k = 0; k < 20; k++) {
				glBegin(GL_LINES); {
					glVertex3f(-10.1, -0.1, k*0.1);
					glVertex3f(-11.4, 6, 0);
				}
				glEnd();
			}
		}
		glPopMatrix();

		glPushMatrix(); {
			glColor3f(0.3, 0.03, 0.03);
			glRotatef(15, 1, 0, 0);
			glTranslatef(8, 10, -10);
			leg();
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(0.3, 0.03, 0.03);
			glRotatef(15, 1, 0, 0);
			glTranslatef(-8, 10, -10);
			leg();
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(0.3, 0.03, 0.03);
			glRotatef(180, 0, 0, 1);
			glPushMatrix(); {
				glRotatef(15, 1, 0, 0);
				glTranslatef(-8, -8, -5);
				leg();
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix(); {
			glColor3f(0.3, 0.03, 0.03);
			glRotatef(180, 0, 0, 1);
			glPushMatrix(); {
				glRotatef(15, 1, 0, 0);
				glTranslatef(8, -8, -5);
				leg();
			}
			glPopMatrix();
		}
		glPopMatrix();
		
		
	}
	glPopMatrix();
}