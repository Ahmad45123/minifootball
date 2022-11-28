#include <GL/glut.h>

class Player {
    public:
    
    float angle=0.0;
    double curX = 0, curY = -0.05, curZ = 0;
    double dirX = 0, dirZ = 1;
    double STEP_SIZE = 0.001;

    bool keys[256];

    void keyDown(char c) {
        keys[c] = true;
    }

    void keyUp(char c) {
        keys[c] = false;
    }

    void tick() {
        static float fraction = 0.001f;
        static float angleSpeed = 0.05f;

        if(keys['w']){
            curX += dirX * fraction;
            curZ += dirZ * fraction;
        }
        if(keys['s']) {
            curX -= dirX * fraction;
            curZ -= dirZ * fraction;
        }

        if(keys['d']) {
            angle += angleSpeed;
            double olddirX = dirX;
            dirX = cos(angleSpeed)*dirX + sin(angleSpeed)*dirZ;
            dirZ = -sin(angleSpeed)*olddirX + cos(angleSpeed)*dirZ;
        }
        if(keys['a']) {
            angle -= angleSpeed;
            double olddirX = dirX;
            dirX = cos(-angleSpeed)*dirX + sin(-angleSpeed)*dirZ;
            dirZ = -sin(-angleSpeed)*olddirX + cos(-angleSpeed)*dirZ;
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