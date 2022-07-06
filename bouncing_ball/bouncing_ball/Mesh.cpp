#include "Mesh.h"
#define PI 3.14159265f
using namespace std;

Mesh::Mesh() {
}

Mesh::~Mesh() {

}
void Mesh::init() {	
	createBar();		// 바 생성
	createBall();		// 공 생성
	createBlock();	    // 블록 생성
}
void Mesh::createBall() {		// 공 생성
	_ball._pos_x = 450.0f;		// x 좌표 설정
	_ball._pos_y = 450.0f;		// y 좌표 설정
	_ball._speed_x = -3.0f;		// 공 x 축 속도
	_ball._speed_y = -3.0f;		// 공 y 축 속도
	_ball._radius = 6.0;		// 공 반지름
}

void Mesh::createBar() {	// 바 생성
	_bar._width = 130.0f;	// 바 가로 길이 조정
	_bar._height = 12.0f;   // 바 세로 길이 조정
	_bar._pos_x = 330.0f;	// x 좌표 설정
	_bar._pos_y = 550.0f;	// y 좌표 설정
}

void Mesh::createBlock() {	// 블록 생성
	Block b1;
	b1._width = 50.0f;		// 블록 가로 길이 조정
	b1._height = 30.0f;		// 블록 세로 길이 조정
	float blue = 0.5f, green = 0.5f, red = 1.0f;
	for (int i = 0; i < 3; ++i) {		// 블록 세로 줄 생성
		for (int j = 0; j < 13; ++j) {	// 블록 가로 줄 생성
			b1._pos_x = 50.0f + j * b1._width + j * 3;
			b1._pos_y = 50.0f + i * b1._height + i * 3;
			b1._red = red;				// 블록의 r,g,b 값 설정
			b1._green = green;
			b1._blue = blue;
			_blocks.push_back(b1);
		}
		green += 0.25f;
	}
	blue = 1.0f, green = 0.5f, red = 0.5f;	// 색상 초기화
	for (int i = 0; i < 3; ++i) {			// 블록 세로 줄 생성
		for (int j = 0; j < 13; ++j) {		// 블록 가로 줄 생성
			b1._pos_x = 50.0f + j * b1._width + j * 3;
			b1._pos_y = 240.0f + i * b1._height + i * 3;
			b1._red = red;					// 블록의 r,g,b 값 설정
			b1._green = green;
			b1._blue = blue;
			_blocks.push_back(b1);
		}
		green += 0.25f;
	}

}

void Mesh::draw() {

	drawBall();  // 공 그리기
	drawBlock(); // 블록 그리기
	drawBar();   // 바 그리기
}

void Mesh::drawBall() {
		// 공 그리기
		glBegin(GL_TRIANGLE_FAN);	    // 정점을 기준으로 삼각형 그리기
		glColor3f(1.0, 1.0, 0.0);		// 공 색상 설정
		for (int i = 0; i < 80; i++) {  // 첫번 째 꼭짓점과 동일한 마지막 꼭짓점
			double angle = 2.0f * PI * (double)i / 80.0f; //  모든 세그먼트에 대해 360도
			glVertex2f(_ball._pos_x + (cos(angle) * _ball._radius), _ball._pos_y + (sin(angle) * _ball._radius));
		}
		glEnd();

		// 새로운 위치 설정
		_ball._pos_x += _ball._speed_x;	// 공의 x축 속도를 x 좌표에 더함
		_ball._pos_y += _ball._speed_y;	// 공의 y축 속도를 y 좌표에 더함

		// 공이 왼쪽 벽과 오른쪽 벽에 충돌했을 경우
		if ((_ball._pos_x <= 10) || (_ball._pos_x >= 790)) {
			_ball._speed_x *= -1;
			// 공의 x 좌표가 10 보다 작거나 또는 790 보다 크면 x 방향을 반대로 전환 
		}
		if (_ball._pos_y <= 10) {		// 천장에 닿을 경우
			_ball._speed_y *= -1;		// y 방향을 반대로 전환
		}

		// 공의 x좌표가 바 x 좌표와 바 x 좌표 + 바 가로길이 사이에 있을 경우
		if (_ball._pos_x >= _bar._pos_x && _ball._pos_x <= _bar._pos_x + _bar._width) {
			// 공의 y 좌표가 바 y좌표와 같을 경우
			if ((_ball._pos_y - _bar._pos_y) >= -5 && (_ball._pos_y - _bar._pos_y) <= 0) {
				_ball._speed_y *= -1; // 공의 y 방향을 반대로 전환
			}
		}
		// 블록과 충돌
		vector<Block>::iterator bl;
		for (bl = _blocks.begin(); bl != _blocks.end(); ) {
			// 공의 y좌표가 블록의 y좌표와 블록의 y좌표 + 블록의 세로길이 사이에 있을경우
			if (_ball._pos_y >= bl->_pos_y && _ball._pos_y <= bl->_pos_y + bl->_height) {
				// 공의 x좌표 - 블록의 x좌표 - 블록의 가로 길이가 0보다 크고 5보다 작을 경우
				if ((_ball._pos_x - bl->_pos_x - bl->_width) <= 5 && (_ball._pos_x - bl->_pos_x - bl->_width) >= 0) {
					_ball._speed_x *= -1;		// 공의 x 방향을 반대로 전환
					bl = _blocks.erase(bl);		// 충돌된 블록을 지움
					continue;
				}

				// 공의 x좌표 - 블록의 x좌표가 -5보다 크고 0보다 작을 경우
				if ((_ball._pos_x - bl->_pos_x) >= -5 && (_ball._pos_x - bl->_pos_x) <= 0) {
					_ball._speed_x *= -1;		// 공의 x 방향을 반대로 전환
					bl = _blocks.erase(bl);		// 충돌된 블록을 지움
					continue;
				}
			}

			// 공의 x좌표가 블록의 x좌표와 블록의 x좌표 + 블록의 가로길이 사이에 있을경우
			if (_ball._pos_x >= bl->_pos_x && _ball._pos_x <= bl->_pos_x + bl->_width) {
				// 공의 y좌표 - 블록의 y좌표 - 블록의 세로 길이가 0보다 크고 5보다 작을 경우
				if ((_ball._pos_y- bl->_pos_y - bl->_height) <= 5 && (_ball._pos_y- bl->_pos_y - bl->_height) >= 0) {
					_ball._speed_y *= -1;		// 공의 y 방향을 반대로 전환
					bl = _blocks.erase(bl);		// 충돌된 블록을 지움
					continue;
				}

				// 공의 y좌표 - 블록의 y좌표가 -5보다 크고 0보다 작을 경우
				if ((_ball._pos_y - bl->_pos_y) >= -5 && (_ball._pos_y - bl->_pos_y) <= 0) {
					_ball._speed_y *= -1;		// 공의 y 방향을 반대로 전환
					bl = _blocks.erase(bl);		// 충돌된 블록을 지움
					continue;
				}
			}
			++bl;
	}
}

void Mesh::drawBar() {
	glColor3f(0.5, 1.0, 0.2);	// 바 색상 설정
	// 바의 좌표와 가로, 세로길이를 통해 사각형 그리기
	glRectf(_bar._pos_x, _bar._pos_y, _bar._pos_x + _bar._width, _bar._pos_y + _bar._height);
}

void Mesh::drawBlock() {
	vector<Block>::iterator bl;	// 여러개 생성하기 위해서 반복자 정의
	for (bl = _blocks.begin(); bl != _blocks.end(); ++bl) {
		glColor3f(bl->_red, bl->_green, bl->_blue);	// 블록 색상 설정
		// 블록의 좌표와 가로, 세로길이를 통해 사각형 그리기
		glRectf(bl->_pos_x, bl->_pos_y, bl->_pos_x + bl->_width, bl->_pos_y + bl->_height);
	}
}

void Mesh::keyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_bar._pos_x -= 20.0f;	// 왼쪽 키를 눌렀을 때 바 x 좌표를 -20 함
		if (_bar._pos_x < 0) {	// 바 x 좌표가 0보다 작으면
			_bar._pos_x = 0.0f; // 바의 x 좌표를 0으로 설정
		}
		break;
	case GLUT_KEY_RIGHT:
		_bar._pos_x += 20.0f;					// 오른쪽 키를 눌렀을 때 바 x 좌표를 +20 함
		if (_bar._pos_x + _bar._width > 800) {	// 바 x 좌표가 800보다 크면
			_bar._pos_x = 800.0f - _bar._width; // 바의 x 좌표를 800 - 바 너비로 설정
		}
		break;
	default:
		break;
	}
}

void Mesh::mouse(int x, int y) {
	if (x >= 0 && x <= 800) {	// 마우스 x 좌표가 0보다 크고 800보다 작으면
		_bar._pos_x = x - _bar._width / 2.0f;	// 바 x좌표를 마우스 x좌표 - 바 너비 /2 로 변경
	}
	glutPostRedisplay();
}