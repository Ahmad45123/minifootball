#include <GL/glut.h>

namespace net {
    double netX = 0.5, netZ = 0; 

    void drawNetEx() {
        glPushMatrix();
            glTranslated(0, 0.05, 0);
            glRotated(90, 0, 0, 1);
            glScaled(10, 1, 0.5);
            glutSolidCube(0.01);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.095, 0.1, 0);
            glScaled(20, 1, 0.5);
            glutSolidCube(0.01);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.095*2, 0.05, 0);
            glRotated(90, 0, 0, 1);
            glScaled(10, 1, 0.5);
            glutSolidCube(0.01);
        glPopMatrix();
    }

    void drawNet() {
        glPushMatrix();
            glTranslated(netX, 0, netZ);
            glRotated(90, 0, 1, 0);
            glColor3f(0.00, 1.00, 1.00);

            glPushMatrix();
                drawNetEx();
            glPopMatrix();

            glPushMatrix();
                glTranslated(0, -0.015, 0.1);
                drawNetEx();
            glPopMatrix();

            glPushMatrix();
                glTranslated(0, 0.1-0.009, 0.05);
                glRotated(90, 0, 1, 0);
                glRotated(7, 0, 0, 1);
                glScaled(10, 1, 0.5);
                glutSolidCube(0.01);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0, 0.1-0.009, 0.05);
                glRotated(90, 0, 1, 0);
                glRotated(7, 0, 0, 1);
                glScaled(10, 1, 0.5);
                glutSolidCube(0.01);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0.19, 0.1-0.009, 0.05);
                glRotated(90, 0, 1, 0);
                glRotated(7, 0, 0, 1);
                glScaled(10, 1, 0.5);
                glutSolidCube(0.01);
            glPopMatrix();

        glPopMatrix();
    }
}