#include <GL/glut.h>

class Player {
    public:
    
    double curX = 0, curY = 0, curZ = 0;
    double STEP_SIZE = 0.001;

    int keys[256];

    void keyDown(char c) {
        keys[c] = true;
    }

    void keyUp(char c) {
        keys[c] = false;
    }

    void tick() {
        if(keys['w'])
            curZ -= STEP_SIZE;
        if(keys['s'])
            curZ += STEP_SIZE;
        if(keys['d'])
            curX += STEP_SIZE;
        if(keys['a'])
            curX -= STEP_SIZE;
    }

    void draw() {
        glPushMatrix();
        glTranslated(curX, curY, curZ);

        glPushMatrix();
        glTranslated(0, 0.09, 0);
        glColor3f(0.88, 0.67, 0.41);
        glutSolidSphere(0.01, 50, 50);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0, 0.07, 0);
        glScaled(1.5, 2, 1.5);
        glColor3f(1, 0, 0);
        glutSolidCube(0.01f);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.01, 0.07, 0);
        glScaled(0.5, 1.5, 0.5);
        glColor3f(0.88, 0.67, 0.41);
        glutSolidCube(0.01f);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.01, 0.07, 0);
        glScaled(0.5, 1.5, 0.5);
        glColor3f(0.88, 0.67, 0.41);
        glutSolidCube(0.01f);
        glPopMatrix();

        glPopMatrix();
    }
};