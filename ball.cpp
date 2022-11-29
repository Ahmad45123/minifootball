#ifndef BALLFILE
#define BALLFILE

#include <GL/glut.h>

#include "textureLoader.cpp"
#include "net.cpp"

class Ball {
    public:
    double curX = 0, curY = 0.02, curZ = 0.05;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0;
    double MAX_STEP_SIZE = 0.008;
    int moveFor = 0;

    GLuint texture;

    Ball() {
        texture = TextureLoader::loadBitmap("textures/football.bmp");
    }

    void tick() {
        // check if collides with net
        if(curZ < net::netZ  && curZ > net::netZ - 0.095*2) {
            if(curX > net::netX + 0.1/2 && curX < net::netX + 0.1) {
                STEP_SIZE = 0.001;
            }
        }

        // check if collides with wall
        if(curX > 0.75 || curX < -0.75 || curZ > 0.5 || curZ < -0.5) {
            dirX *= -1;
            dirZ *= -1;
        }

        if(moveFor > 0) {
            curX += dirX * STEP_SIZE;
            curZ += dirZ * STEP_SIZE;
            moveFor --;
            STEP_SIZE -= 0.0001;
            if(STEP_SIZE < 0.0001) STEP_SIZE = 0.0001;
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
        glDisable(GL_COLOR);
        glEnable(GL_TEXTURE_2D);

        GLUquadricObj *quadricObj = gluNewQuadric();
        gluQuadricDrawStyle(quadricObj, GLU_FILL);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluQuadricTexture(quadricObj, GL_TRUE);
        gluQuadricNormals(quadricObj, GLU_SMOOTH);
        gluSphere(quadricObj, 0.01, 50, 50);

        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR);
        glPopMatrix();
    }
};

#endif