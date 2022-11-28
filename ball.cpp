#ifndef BALLFILE
#define BALLFILE

#include <GL/glut.h>

class Ball {
    public:
    double curX = 0, curY = 0.02, curZ = 0;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0.001;
    int moveFor = 0;



    void tick() {
        while(moveFor > 0) {
            curX += dirX * STEP_SIZE;
            curZ += dirZ * STEP_SIZE;
            moveFor --;
        }
    }

    void kick(double dirX, double dirZ, int time) {
        this->dirX = dirX;
        this->dirZ = dirZ;
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