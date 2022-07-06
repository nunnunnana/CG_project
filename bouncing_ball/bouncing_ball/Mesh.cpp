#include "Mesh.h"
#define PI 3.14159265f
using namespace std;

Mesh::Mesh() {
}

Mesh::~Mesh() {

}
void Mesh::init() {	
	createBar();		// �� ����
	createBall();		// �� ����
	createBlock();	    // ��� ����
}
void Mesh::createBall() {		// �� ����
	_ball._pos_x = 450.0f;		// x ��ǥ ����
	_ball._pos_y = 450.0f;		// y ��ǥ ����
	_ball._speed_x = -3.0f;		// �� x �� �ӵ�
	_ball._speed_y = -3.0f;		// �� y �� �ӵ�
	_ball._radius = 6.0;		// �� ������
}

void Mesh::createBar() {	// �� ����
	_bar._width = 130.0f;	// �� ���� ���� ����
	_bar._height = 12.0f;   // �� ���� ���� ����
	_bar._pos_x = 330.0f;	// x ��ǥ ����
	_bar._pos_y = 550.0f;	// y ��ǥ ����
}

void Mesh::createBlock() {	// ��� ����
	Block b1;
	b1._width = 50.0f;		// ��� ���� ���� ����
	b1._height = 30.0f;		// ��� ���� ���� ����
	float blue = 0.5f, green = 0.5f, red = 1.0f;
	for (int i = 0; i < 3; ++i) {		// ��� ���� �� ����
		for (int j = 0; j < 13; ++j) {	// ��� ���� �� ����
			b1._pos_x = 50.0f + j * b1._width + j * 3;
			b1._pos_y = 50.0f + i * b1._height + i * 3;
			b1._red = red;				// ����� r,g,b �� ����
			b1._green = green;
			b1._blue = blue;
			_blocks.push_back(b1);
		}
		green += 0.25f;
	}
	blue = 1.0f, green = 0.5f, red = 0.5f;	// ���� �ʱ�ȭ
	for (int i = 0; i < 3; ++i) {			// ��� ���� �� ����
		for (int j = 0; j < 13; ++j) {		// ��� ���� �� ����
			b1._pos_x = 50.0f + j * b1._width + j * 3;
			b1._pos_y = 240.0f + i * b1._height + i * 3;
			b1._red = red;					// ����� r,g,b �� ����
			b1._green = green;
			b1._blue = blue;
			_blocks.push_back(b1);
		}
		green += 0.25f;
	}

}

void Mesh::draw() {

	drawBall();  // �� �׸���
	drawBlock(); // ��� �׸���
	drawBar();   // �� �׸���
}

void Mesh::drawBall() {
		// �� �׸���
		glBegin(GL_TRIANGLE_FAN);	    // ������ �������� �ﰢ�� �׸���
		glColor3f(1.0, 1.0, 0.0);		// �� ���� ����
		for (int i = 0; i < 80; i++) {  // ù�� ° �������� ������ ������ ������
			double angle = 2.0f * PI * (double)i / 80.0f; //  ��� ���׸�Ʈ�� ���� 360��
			glVertex2f(_ball._pos_x + (cos(angle) * _ball._radius), _ball._pos_y + (sin(angle) * _ball._radius));
		}
		glEnd();

		// ���ο� ��ġ ����
		_ball._pos_x += _ball._speed_x;	// ���� x�� �ӵ��� x ��ǥ�� ����
		_ball._pos_y += _ball._speed_y;	// ���� y�� �ӵ��� y ��ǥ�� ����

		// ���� ���� ���� ������ ���� �浹���� ���
		if ((_ball._pos_x <= 10) || (_ball._pos_x >= 790)) {
			_ball._speed_x *= -1;
			// ���� x ��ǥ�� 10 ���� �۰ų� �Ǵ� 790 ���� ũ�� x ������ �ݴ�� ��ȯ 
		}
		if (_ball._pos_y <= 10) {		// õ�忡 ���� ���
			_ball._speed_y *= -1;		// y ������ �ݴ�� ��ȯ
		}

		// ���� x��ǥ�� �� x ��ǥ�� �� x ��ǥ + �� ���α��� ���̿� ���� ���
		if (_ball._pos_x >= _bar._pos_x && _ball._pos_x <= _bar._pos_x + _bar._width) {
			// ���� y ��ǥ�� �� y��ǥ�� ���� ���
			if ((_ball._pos_y - _bar._pos_y) >= -5 && (_ball._pos_y - _bar._pos_y) <= 0) {
				_ball._speed_y *= -1; // ���� y ������ �ݴ�� ��ȯ
			}
		}
		// ��ϰ� �浹
		vector<Block>::iterator bl;
		for (bl = _blocks.begin(); bl != _blocks.end(); ) {
			// ���� y��ǥ�� ����� y��ǥ�� ����� y��ǥ + ����� ���α��� ���̿� �������
			if (_ball._pos_y >= bl->_pos_y && _ball._pos_y <= bl->_pos_y + bl->_height) {
				// ���� x��ǥ - ����� x��ǥ - ����� ���� ���̰� 0���� ũ�� 5���� ���� ���
				if ((_ball._pos_x - bl->_pos_x - bl->_width) <= 5 && (_ball._pos_x - bl->_pos_x - bl->_width) >= 0) {
					_ball._speed_x *= -1;		// ���� x ������ �ݴ�� ��ȯ
					bl = _blocks.erase(bl);		// �浹�� ����� ����
					continue;
				}

				// ���� x��ǥ - ����� x��ǥ�� -5���� ũ�� 0���� ���� ���
				if ((_ball._pos_x - bl->_pos_x) >= -5 && (_ball._pos_x - bl->_pos_x) <= 0) {
					_ball._speed_x *= -1;		// ���� x ������ �ݴ�� ��ȯ
					bl = _blocks.erase(bl);		// �浹�� ����� ����
					continue;
				}
			}

			// ���� x��ǥ�� ����� x��ǥ�� ����� x��ǥ + ����� ���α��� ���̿� �������
			if (_ball._pos_x >= bl->_pos_x && _ball._pos_x <= bl->_pos_x + bl->_width) {
				// ���� y��ǥ - ����� y��ǥ - ����� ���� ���̰� 0���� ũ�� 5���� ���� ���
				if ((_ball._pos_y- bl->_pos_y - bl->_height) <= 5 && (_ball._pos_y- bl->_pos_y - bl->_height) >= 0) {
					_ball._speed_y *= -1;		// ���� y ������ �ݴ�� ��ȯ
					bl = _blocks.erase(bl);		// �浹�� ����� ����
					continue;
				}

				// ���� y��ǥ - ����� y��ǥ�� -5���� ũ�� 0���� ���� ���
				if ((_ball._pos_y - bl->_pos_y) >= -5 && (_ball._pos_y - bl->_pos_y) <= 0) {
					_ball._speed_y *= -1;		// ���� y ������ �ݴ�� ��ȯ
					bl = _blocks.erase(bl);		// �浹�� ����� ����
					continue;
				}
			}
			++bl;
	}
}

void Mesh::drawBar() {
	glColor3f(0.5, 1.0, 0.2);	// �� ���� ����
	// ���� ��ǥ�� ����, ���α��̸� ���� �簢�� �׸���
	glRectf(_bar._pos_x, _bar._pos_y, _bar._pos_x + _bar._width, _bar._pos_y + _bar._height);
}

void Mesh::drawBlock() {
	vector<Block>::iterator bl;	// ������ �����ϱ� ���ؼ� �ݺ��� ����
	for (bl = _blocks.begin(); bl != _blocks.end(); ++bl) {
		glColor3f(bl->_red, bl->_green, bl->_blue);	// ��� ���� ����
		// ����� ��ǥ�� ����, ���α��̸� ���� �簢�� �׸���
		glRectf(bl->_pos_x, bl->_pos_y, bl->_pos_x + bl->_width, bl->_pos_y + bl->_height);
	}
}

void Mesh::keyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_bar._pos_x -= 20.0f;	// ���� Ű�� ������ �� �� x ��ǥ�� -20 ��
		if (_bar._pos_x < 0) {	// �� x ��ǥ�� 0���� ������
			_bar._pos_x = 0.0f; // ���� x ��ǥ�� 0���� ����
		}
		break;
	case GLUT_KEY_RIGHT:
		_bar._pos_x += 20.0f;					// ������ Ű�� ������ �� �� x ��ǥ�� +20 ��
		if (_bar._pos_x + _bar._width > 800) {	// �� x ��ǥ�� 800���� ũ��
			_bar._pos_x = 800.0f - _bar._width; // ���� x ��ǥ�� 800 - �� �ʺ�� ����
		}
		break;
	default:
		break;
	}
}

void Mesh::mouse(int x, int y) {
	if (x >= 0 && x <= 800) {	// ���콺 x ��ǥ�� 0���� ũ�� 800���� ������
		_bar._pos_x = x - _bar._width / 2.0f;	// �� x��ǥ�� ���콺 x��ǥ - �� �ʺ� /2 �� ����
	}
	glutPostRedisplay();
}