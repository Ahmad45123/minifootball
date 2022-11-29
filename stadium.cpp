#include <GL/glut.h>

#include "util.cpp"
#include "textureLoader.cpp"
#include "net.cpp"
#include "benches.cpp"

namespace Stadium {
    
    GLuint groundTexture;
    GLuint egyptTexture;
    GLuint ukTexture;
    GLuint germanyTexture;

    void init() {
        groundTexture = TextureLoader::loadBitmap("textures/grass.bmp");
        egyptTexture = TextureLoader::loadBitmap("textures/egypt_flag.bmp");
        ukTexture = TextureLoader::loadBitmap("textures/uk_flag.bmp");
        germanyTexture = TextureLoader::loadBitmap("textures/germany_flag.bmp");
    }

    void drawFlag() {
        // draw a rectangle on the ground
        glPushMatrix();
            glTranslated(0, -0.003, 0);
            glRotated(-90, 0, 1, 0);
            glScaled(1, 0.1, 1);
            util::drawCube(0.099);
        glPopMatrix();
    }

    void draw() {
        glPushMatrix();
            glDisable(GL_COLOR);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, groundTexture);
            glScaled(1.5, 0.02, 1.0);
            util::drawCube(1, 4);
            glDisable(GL_TEXTURE_2D);
            glEnable(GL_COLOR);
        glPopMatrix();
        
        // Draw outer ring
        glPushMatrix();
            glColor3f(0.40, 0.21, 0.02);
            glTranslated(0, -0.01, 0);
            glScaled(1.3*1.5, 0.02, 1.3);
            glutSolidCube(1);
        glPopMatrix();

        // Draw benches
	    benches::draw();

        // Draw nets
        net::draw();

        // Draw flaags
        glDisable(GL_COLOR);
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, egyptTexture);
            glTranslated(-0.85, 0, 0);
            drawFlag();
        glPopMatrix();
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, germanyTexture);
            glTranslated(-0.85, 0, -0.4);
            drawFlag();
        glPopMatrix();
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, ukTexture);
            glTranslated(-0.85, 0, 0.4);
            drawFlag();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR);
    }
}