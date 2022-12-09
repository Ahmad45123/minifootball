#include <GL/glut.h>
#include <math.h>

#include "camera.cpp"
#include "player.cpp"
#include "ball.cpp"
#include "stadium.cpp"

Player *player;
Ball *ball;

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

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
