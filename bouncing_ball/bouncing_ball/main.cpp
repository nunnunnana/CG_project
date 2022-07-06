#include <windows.h> 
#include <GL/glut.h>  
#include <Math.h>    
#include "Mesh.h"


Mesh _mesh;

// �׷��� �ʱ�ȭ
void initGL() {
	_mesh.init();
}

void Timer(int value) {
	glutPostRedisplay();    // ���÷��� Ȱ��ȭ�� ���� ����Ʈ ��û �Խ�
}

void GL_Display() {
	glClear(GL_COLOR_BUFFER_BIT);	 // �÷� ���� �����
	glMatrixMode(GL_PROJECTION);	 // ���� ��� ����
	glLoadIdentity();				 // ��ǥ�� �ʱ�ȭ

	glOrtho(0.0f, 800, 600, 0.0f, 0.0f, 1.0f); // �ְ������� ���� ��Ⱦ�� �����ϱ� ���ؼ� glOrtho() ���
	_mesh.draw();					 //	���� ����

	glutTimerFunc(0, Timer, 0);		 // Ÿ�̸� �ݹ� 
	glutSwapBuffers();				 // ���� ���ۿ� �ĸ� ���� ����
}

// â ũ�Ⱑ �����Ǹ� �ٽ� �ݹ�
void GL_Reshape(int width, int height) {
	if (width == 0) {
		height = 1;
	}
	glViewport(0, 0, width, height);	
	glMatrixMode(GL_PROJECTION);		// ���� ��� ����
	glLoadIdentity();				    // ��ǥ�� �ʱ�ȭ
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);			// �𵨺� ��� ����
}
void GL_keyboard(int key, int x, int y)
{
	_mesh.keyboard(key, x, y);
}

void GL_Mouse(int x, int y)
{
	_mesh.mouse(x, y);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);				// GLUT �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���� ��� ���
	glutInitWindowSize(800, 600);		// ������ �ʺ� �� ����
	glutInitWindowPosition(100, 100);	// ������ ���� ��ġ
	glutCreateWindow("Bouncing Ball");	// ������ ����
	glutDisplayFunc(GL_Display);		// ������ re-paint�� ���� �ݹ� ó���� ���
	glutReshapeFunc(GL_Reshape);		// ������ ũ���� ������ �ݹ� ó���� ���
	glutSpecialFunc(GL_keyboard);		// Ű���� �Է�
	glutPassiveMotionFunc(GL_Mouse);	// ���콺 �Է�
	initGL();							// ��ü OpenGL �ʱ�ȭ
	glutMainLoop();						// �̺�Ʈ ó�� ���� �Է�

	return 0;
}