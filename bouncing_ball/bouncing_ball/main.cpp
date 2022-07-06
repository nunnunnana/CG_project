#include <windows.h> 
#include <GL/glut.h>  
#include <Math.h>    
#include "Mesh.h"


Mesh _mesh;

// 그래픽 초기화
void initGL() {
	_mesh.init();
}

void Timer(int value) {
	glutPostRedisplay();    // 디스플레이 활성화를 위한 페인트 요청 게시
}

void GL_Display() {
	glClear(GL_COLOR_BUFFER_BIT);	 // 컬러 버퍼 지우기
	glMatrixMode(GL_PROJECTION);	 // 투상 모드 설정
	glLoadIdentity();				 // 좌표계 초기화

	glOrtho(0.0f, 800, 600, 0.0f, 0.0f, 1.0f); // 왜곡현상을 막고 종횡비를 유지하기 위해서 glOrtho() 사용
	_mesh.draw();					 //	게임 실행

	glutTimerFunc(0, Timer, 0);		 // 타이머 콜백 
	glutSwapBuffers();				 // 전면 버퍼와 후면 버퍼 스왑
}

// 창 크기가 조정되면 다시 콜백
void GL_Reshape(int width, int height) {
	if (width == 0) {
		height = 1;
	}
	glViewport(0, 0, width, height);	
	glMatrixMode(GL_PROJECTION);		// 투상 모드 설정
	glLoadIdentity();				    // 좌표계 초기화
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);			// 모델뷰 모드 설정
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
	glutInit(&argc, argv);				// GLUT 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 이중 버퍼 모드 사용
	glutInitWindowSize(800, 600);		// 윈도우 너비 및 높이
	glutInitWindowPosition(100, 100);	// 윈도우 생성 위치
	glutCreateWindow("Bouncing Ball");	// 윈도우 제목
	glutDisplayFunc(GL_Display);		// 윈도우 re-paint에 대한 콜백 처리기 등록
	glutReshapeFunc(GL_Reshape);		// 윈도우 크기을 변경할 콜백 처리기 등록
	glutSpecialFunc(GL_keyboard);		// 키보드 입력
	glutPassiveMotionFunc(GL_Mouse);	// 마우스 입력
	initGL();							// 자체 OpenGL 초기화
	glutMainLoop();						// 이벤트 처리 루프 입력

	return 0;
}