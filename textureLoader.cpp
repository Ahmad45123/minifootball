#include <stdio.h>
#include <GL/glut.h>

namespace TextureLoader {
    GLuint loadBitmap(const char* imagepath, bool wrap = true, bool colorize = false) {
        // Data read from the header of the BMP file
        unsigned char header[54]; // Each BMP file begins by a 54-bytes header
        unsigned int dataPos;     // Position in the file where the actual data begins
        unsigned int width, height;
        unsigned int imageSize;   // = width*height*3
        
        // Actual RGB data
        unsigned char * data;

        // Open the file
        FILE* file = fopen(imagepath, "rb");
        if(!file) {
            printf("Image could not be opened\n");
            return 0;
        }

        if(fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
            printf("Not a correct BMP file\n");
            return false;
        }

        if(header[0] != 'B' || header[1] != 'M') {
            printf("Not a correct BMP file\n");
            return 0;
        }

        // Read ints from the byte array
        dataPos    = *(int*)&(header[0x0A]);
        imageSize  = *(int*)&(header[0x22]);
        width      = *(int*)&(header[0x12]);
        height     = *(int*)&(header[0x16]);

        if(imageSize == 0) imageSize = width*height*3; // 3 : one byte for each Red, Green and Blue component
        if(dataPos == 0) dataPos = 54;

        data = new unsigned char [imageSize];
        fread(data, 1, imageSize, file);

        //Everything is in memory now, the file can be closed
        fclose(file);

        // Create one OpenGL texture
        GLuint textureID;
        glGenTextures(1, &textureID);

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, colorize ? GL_MODULATE : GL_REPLACE);

        return textureID;
    }
}