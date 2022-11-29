#ifndef BALLFILE
#define BALLFILE

#include <GL/glut.h>

class Ball {
    public:
    double curX = 0, curY = 0.02, curZ = 0.05;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0;
    double MAX_STEP_SIZE = 0.008;
    int moveFor = 0;
    int lastUpdated = 0;

    void tick() {
        while(moveFor > 0 && glutGet(GLUT_ELAPSED_TIME) - lastUpdated > 10) {
            curX += dirX * STEP_SIZE;
            curZ += dirZ * STEP_SIZE;
            moveFor --;
            STEP_SIZE -= 0.0001;
            if(STEP_SIZE < 0.0001) STEP_SIZE = 0.0001;
            lastUpdated = glutGet(GLUT_ELAPSED_TIME);
        }
    }

    void kick(double dirX, double dirZ, int time) {
        this->dirX = dirX;
        this->dirZ = dirZ;
        STEP_SIZE = MAX_STEP_SIZE;
        moveFor = time;
    }

    void draw() {
        glPushMatrix();
        glTranslated(curX, curY, curZ);
        glColor3f(1, 1, 1);
        glutSolidSphere(0.01, 50, 50);
        glPopMatrix();
    }
};

#endif