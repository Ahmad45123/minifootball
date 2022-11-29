#include <GL/glut.h>

#include "util.cpp"
#include "textureLoader.cpp"
#include "net.cpp"
#include "benches.cpp"

namespace Stadium {
    GLuint groundTexture;
    void init() {
        groundTexture = TextureLoader::loadBitmap("textures/grass.bmp");
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
    }
}