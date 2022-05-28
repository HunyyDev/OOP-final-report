#pragma once
#include "CChessMan.h"
class Rooks : public ChessMan
{
public:
	Rooks();
	Rooks(int c);
	Rooks(int a, int b);
	bool check(int xx, int yy, Board b);
	int move(Board& b);
	void output();
};