#include <GL/glut.h>

namespace benches {
    void drawBenches() {
        glPushMatrix();
            glColor3f(0.53, 0.24, 0.11);
            glTranslated(0, 0.05, 0);
            glPushMatrix();
                glTranslated(0, -0.015, 0);
                glScaled(5, 0.55, 1);
                glutSolidCube(0.05);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0, 0.02, -0.03);
                glScaled(5, 2, 0.2);
                glRotated(90, 1, 0, 0);
                glutSolidCube(0.05);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0, 0.07, 0);
                glScaled(5, 0.2, 1);
                glutSolidCube(0.05);
            glPopMatrix();
        glPopMatrix();

    }
}