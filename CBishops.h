#pragma once
#include "CChessMan.h"
class Bishops : public ChessMan
{
public:
	Bishops();
	Bishops(int c);
	Bishops(int a, int b);

	bool check(int xx, int yy, Board b);
	int move(Board& b);
	void output();
};