#include <GL/glut.h>
#include <math.h>
#include <string>

using namespace std;

#include "camera.cpp"
#include "player.cpp"
#include "ball.cpp"
#include "stadium.cpp"

Player *player;
Ball *ball;
int timeRemaining = 60;
bool hasLost, hasWon;

void keyDown(unsigned char c, int x, int y) {
	Camera::keyDown(c);
	player->keyDown(c);
}
void keyUp(unsigned char c, int x, int y) {
	Camera::keyUp(c);
	player->keyUp(c);
}
void specialKeysDown(int c, int x, int y) {
	Camera::specialKeyDown(c);
}
void specialKeysUp(int c, int x, int y) {
	Camera::specialKeyUp(c);
}

void timerFunc(int tmp) {
	Camera::tick();
	player->tick();
	ball->tick();

	// decrement time if a second has passed
	static int lastTime = glutGet(GLUT_ELAPSED_TIME);
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	if(currentTime - lastTime > 1000) {
		timeRemaining--;
		if(timeRemaining == 0) {
			hasLost = true;
		}
		lastTime = currentTime;
	}

	// check win
	if(ball->isInGoal) {
		hasWon = true;
	}

	glutTimerFunc(10, timerFunc, 0);
    glutPostRedisplay();
}

void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(60.0f, ratio, 0.001f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
}

void drawString(string str, int x, int y, bool small = false) {
  glPushMatrix();
  glRasterPos2i(x, y);
  for( size_t i = 0; i < str.size(); ++i ) {
      glutBitmapCharacter(small ? GLUT_BITMAP_TIMES_ROMAN_10 : GLUT_BITMAP_TIMES_ROMAN_24, (int)str[i] );
  }
  glPopMatrix();
}

void renderScene() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1500, 1000, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(hasLost) {
        glColor3f(1, 0, 0);
        drawString("You lost!", 450, 600);
        glutSwapBuffers();
        return;
    }
    if(hasWon) {
        glColor3f(0, 1, 0);
        drawString("You won :D", 450, 600);
        glutSwapBuffers();
        return;
    }

	// Draw time remaining
	glPushMatrix();
		drawString("Time remaining: " + to_string(timeRemaining), 10, 30);
	glPopMatrix();

	changeSize(1500, 1000);
	glClear(GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Camera::draw();

	Stadium::draw();

	player->draw();
	ball->draw();


	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1500, 1000);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("FIFA 2022");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(specialKeysDown);
	glutSpecialUpFunc(specialKeysUp);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(0, timerFunc, 0);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	Stadium::init();

	ball = new Ball();
	player = new Player(ball);

	glutMainLoop();
    return 0;
}
