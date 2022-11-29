#ifndef BALLFILE
#define BALLFILE

#include "iostream"
#include <GL/glut.h>

#include "net.cpp"

class Ball {
    public:
    double curX = 0, curY = 0.02, curZ = 0.05;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0;
    double MAX_STEP_SIZE = 0.008;
    int moveFor = 0;
    int lastUpdated = 0;

    void tick() {
        if(moveFor > 0 /*&& glutGet(GLUT_ELAPSED_TIME) - lastUpdated > 10*/) {
            curX += dirX * STEP_SIZE;
            curZ += dirZ * STEP_SIZE;
            moveFor --;
            STEP_SIZE -= 0.0001;
            if(STEP_SIZE < 0.0001) STEP_SIZE = 0.0001;
            lastUpdated = glutGet(GLUT_ELAPSED_TIME);
        }

        // check if collides with net
        if(curZ < net::netZ  && curZ > net::netZ - 0.095*2) {
            if(curX > net::netX + 0.1/2 && curX < net::netX + 0.1) {
                STEP_SIZE = 0.001;
            }
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