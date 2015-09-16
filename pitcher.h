#include<GL/glut.h>
void drawPitcher() {
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix(); {
		glTranslatef(0, 0, 43);
		glColor4f(1, 1, 1, 1);
		float i = 10;
		for (; i > 5; i -= 0.05) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		for (i; i > 4; i -= 0.03) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		for (i; i > 3; i -= 0.01) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		i = 3;
		for (i; i < 4; i += 0.01) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		for (i; i < 4; i += 0.03) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		for (i; i < 10; i += 0.05) {
			glTranslatef(0, 0, -0.05);
			glutSolidTorus(1, i, 50, 50);
		}
		for (i; i < 20; i += 0.01) {
			glTranslatef(0, 0, -0.01);
			glutSolidTorus(1, i, 50, 50);
		}

	}
	glPopMatrix();
	glPushMatrix(); {
		glTranslatef(0, 0, 10);
		glColor4f(1, 1, 1, 1);
		glScalef(1, 1, 0.5);
		double equ[4];
		equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 0;
		glClipPlane(GL_CLIP_PLANE0, equ);
		glEnable(GL_CLIP_PLANE0); {
			glutSolidSphere(21, 500, 500);
		}
		glDisable(GL_CLIP_PLANE0);
	}
	glPopMatrix();
	glDisable(GL_BLEND);
}
