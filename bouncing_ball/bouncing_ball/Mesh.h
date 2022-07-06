#ifndef __MESH_H__
#define __MESH_H__

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <gl/glut.h>
#include "Ball.h"  
#include "Bar.h"  
#include "Block.h" 

class Mesh
{	
public:
	std::vector<Ball>	_balls;
	std::vector<Block>	_blocks;
	Ball				_ball;
	Bar					_bar;
public:
	Mesh();
	~Mesh();
public:
	void init();
	void createBall();
	void createBar();
	void createBlock();
	void draw();
	void drawBall();
	void drawBar();
	void drawBlock();
	void keyboard(int key, int x, int y);
	void mouse(int x, int y);


};
#endif