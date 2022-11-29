#include <GL/glut.h>

#include "ball.cpp"

class Player {
    public:

    Ball *ball;
    float angle=0.0;
    double curX = 0, curY = -0.05, curZ = 0;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0.003;
    float ANGLE_SPEED = 0.05f;

    bool keys[256];

    Player(Ball *ball) {
        this->ball = ball;
    }

    void keyDown(char c) {
        keys[c] = true;
    }

    void keyUp(char c) {
        keys[c] = false;
    }

    void tick() {

        if(keys['w']){
            curX += dirX * STEP_SIZE;
            curZ += dirZ * STEP_SIZE;
        }
        if(keys['s']) {
            curX -= dirX * STEP_SIZE;
            curZ -= dirZ * STEP_SIZE;
        }

        if(keys['d']) {
            angle += ANGLE_SPEED;
            double olddirX = dirX;
            dirX = cos(ANGLE_SPEED)*dirX + sin(ANGLE_SPEED)*dirZ;
            dirZ = -sin(ANGLE_SPEED)*olddirX + cos(ANGLE_SPEED)*dirZ;
        }
        if(keys['a']) {
            angle -= ANGLE_SPEED;
            double olddirX = dirX;
            dirX = cos(-ANGLE_SPEED)*dirX + sin(-ANGLE_SPEED)*dirZ;
            dirZ = -sin(-ANGLE_SPEED)*olddirX + cos(-ANGLE_SPEED)*dirZ;
        }

        // check if collides with ball
        if(curX > ball->curX - 0.01 && curX < ball->curX + 0.01) {
            if(curZ > ball->curZ - 0.01 && curZ < ball->curZ + 0.01) {
                ball->kick(dirX, dirZ, 50);
            }
        }
    }

    void draw() {
        glPushMatrix();
        glTranslated(curX, curY, curZ);
        glRotated(angle * 180/M_PI, 0, 1, 0);

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

        // eyes
        glPushMatrix();
        glTranslated(-0.005, 0.09, 0.009);
        glColor3f(0, 0, 0);
        glutSolidSphere(0.001, 50, 50);
        glPopMatrix();

        // eyes 2
        glPushMatrix();
        glTranslated(0.005, 0.09, 0.009);
        glColor3f(0, 0, 0);
        glutSolidSphere(0.001, 50, 50);
        glPopMatrix();

        glPopMatrix();
    }
};