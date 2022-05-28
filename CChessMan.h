#pragma once
#include"CBoard.h"
#include <string>

using namespace std;

class ChessMan
{
protected:
	int x, y;
	int Color;
	int dead = 0;
public:
	int isDead();
	void die();
	int Col();

	virtual int move(Board& b);
	virtual bool check(Board b);
	virtual void output();
	virtual bool check(int xx, int yy, Board b);

	string getViTri();
};