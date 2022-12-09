#include "GL/glut.h"

namespace WorldCup {
    void draw() {
        glPushMatrix();
        glColor3f(0.88, 0.67, 0.41);
        glTranslated(0, -0.01, 0.58);
            //drawSphere
            glPushMatrix();
            glTranslated(0, 0.065, 0);
            glScaled(0.4, 0.4, 0.4);
            glutSolidSphere(0.05, 100, 20);
            glPopMatrix();

            //draw cone
            glPushMatrix();
            glTranslated(0, 0.06, 0);
            glScaled(0.025, 0.08, 0.025);
            glRotated(90, 1, 0, 0);
            glutSolidCone(1, 1, 100, 20);
            glPopMatrix();

            glPushMatrix();
            glColor3f(0.88, 0.67, 0.41);
            glTranslated(0, 0.01, 0);
            glScaled(0.2, 0.03, 0.2);
            glutSolidSphere(0.1, 100, 20);
            glPopMatrix();
        glPopMatrix();
    }
}