#include<GL/glut.h>
const float twoPi = 2.0*3.1416;
void drawTable() {
	// table
	glPushMatrix(); {
		//glScalef(2, 2, 2);
		glColor3f(0.4, 0.4, 0.4);
		int n = 40;
		float pointx = 0, pointy = 0, pointz = 20;
		float depth = 2 + pointz;

		float radius = 20;
		while (pointz < depth) {
			glBegin(GL_TRIANGLE_FAN); {
				glVertex3f(pointx, pointy, pointz);
				for (int i = 0; i <= n; i++) {
					//cout << pointx + radius * cos(i*twoPi / n) << " " << pointy + radius * cos(i*twoPi / n) << " " << endl;
					glVertex3f(
						pointx + radius * cos(i*twoPi / n),
						pointy + radius * sin(i*twoPi / n),
						pointz
						);
				}
			}
			glEnd();
			pointz += 0.3;

		}
		for (int step = 0; step < 4; step++) {
			n = 40;
			radius = 1;
			float px1, px2, px3, py1, py2, py3;
			if (step == 0) {
				px1 = 0; py1 = 15;
				px2 = 0; py2 = 10;
				px3 = 0; py3 = 6;

			}
			else if (step == 1) {
				px1 = 0; py1 = -15;
				px2 = 0; py2 = -10;
				px3 = 0; py3 = -6;
			}
			else if (step == 2) {
				px1 = 15; py1 = 0;
				px2 = 10; py2 = 0;
				px3 = 6; py3 = 0;
			}
			else {
				px1 = -15; py1 = 0;
				px2 = -10; py2 = 0;
				px3 = -6; py3 = 0;

			}
			glColor3f(0.7, 0.7, 0.7);
			for (int k = 0; k < 2; k++) {
				double z = 20;
				if (k) z = 0;

				glBegin(GL_TRIANGLES); {
					glVertex3f(px1, py1, z);
					glVertex3f(px2, py2, 12);
					glVertex3f(px3, py3, 12);
				}
				glEnd();
			}



		}

		//glutSolidTorus(8, 10, 50, 50);
		glColor3f(0.4, 0.4, 0.4);
		glBegin(GL_LINE_LOOP); {
			radius = 8;
			n = 300;
			for (float z = 12; z <= 13; z += 0.05) {
				for (int i = 0; i < n; i++) {
					glVertex3f(
						radius * cos(i*twoPi / n),
						radius * sin(i*twoPi / n),
						z
						);
				}
			}
			for (float z = 10.5; z <= 11.5; z += 0.05) {
				for (int i = 0; i < n; i++) {
					glVertex3f(
						radius * cos(i*twoPi / n),
						radius * sin(i*twoPi / n),
						z
						);
				}
			}

		}
		glEnd();
	}
	glPopMatrix();

}
