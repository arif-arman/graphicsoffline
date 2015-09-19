#include<GL/glut.h>

void drawGlass() {
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix(); {
		glTranslatef(0, 0, 10);
		glScalef(0.2, 0.2, 0.2);
		glPushMatrix(); {
			glScalef(0.8, 0.8, 1);
			glTranslatef(0, 0, 38);
			double equ[4];
			equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 15;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				glutSolidCone(20, 30, 500, 500);
			}
			glDisable(GL_CLIP_PLANE0);
			glPushMatrix(); {
				glScalef(1, 1, 0.5);
				equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 0;
				glClipPlane(GL_CLIP_PLANE0, equ);
				glEnable(GL_CLIP_PLANE0); {
					glutSolidSphere(20, 50, 50);
				}
				glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();

		}
		glPopMatrix();


		glPushMatrix(); {
			glRotatef(180, 1, 0, 0);
			glTranslatef(0, 0, -29);
			glScalef(1, 1, 2);
			double equ[4];
			equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 5;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				glutSolidCone(1, 10, 500, 500);

			}
			glDisable(GL_CLIP_PLANE0);
			glPushMatrix(); {
				glRotatef(180, 1, 0, 0);
				glTranslatef(0, 0, -18);
				equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 15;
				glClipPlane(GL_CLIP_PLANE0, equ);
				glEnable(GL_CLIP_PLANE0); {
					glutSolidCone(2, 20, 500, 500);
				}
				glDisable(GL_CLIP_PLANE0);
			}
			glPopMatrix();


			/*
			int n = 200;
			float pointx = 0, pointy = 0;
			int radius = 1;
			glBegin(GL_LINES); {
			for (int i = 0; i <= n; i++) {

			glVertex3f(
			pointx + radius * cos(i*twoPi / n),
			pointy + radius * sin(i*twoPi / n),
			0);
			glVertex3f(
			pointx + radius * cos(i*twoPi / n),
			pointy + radius * sin(i*twoPi / n),
			30);
			}

			}
			glEnd();
			*/
		}
		glPopMatrix();
		glPushMatrix(); {
			glTranslatef(0, 0, -10);
			double equ[4];
			equ[0] = 0; equ[1] = 0; equ[2] = -1; equ[3] = 3.5;
			glClipPlane(GL_CLIP_PLANE0, equ);
			glEnable(GL_CLIP_PLANE0); {
				glutSolidCone(12, 4, 500, 500);
			}
			glDisable(GL_CLIP_PLANE0);
		}
		glPopMatrix();
	}
	glPopMatrix();
	glDisable(GL_BLEND);

}
