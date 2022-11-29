#include <GL/glut.h>

namespace benches {
    void deawBench() {
        glPushMatrix();
            glColor3f(0.24, 0.22, 0.21);
            glTranslated(0, 0.03, -0.55);
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

    void draw() {
        glPushMatrix(); {
            glTranslated(-0.4, 0, 0);
            deawBench();
        } glPopMatrix();
        glPushMatrix(); {
            glTranslated(0.4, 0, 0);
            deawBench();
        } glPopMatrix();
    }
}