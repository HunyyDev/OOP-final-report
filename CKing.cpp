#include "CKing.h"
#include<iostream>

using namespace std;

King::King()
{
}

King::King(int c)
{
	Color = c;
}

King::King(int a, int b)
{
	x = a;
	y = b;
	if (y >= 0 && y <= 4)
		Color = 0;
	if (y >= 5 && y <= 9) {
		Color = 1;
	}
}

void King::output(){
	if (Col() == 0)
		cout << "Ki0";
	else
		cout << "Ki1";
}

bool King::check(int xx, int yy, Board b)
{
	if (!((abs(xx - x) == 1 && yy == y) || (abs(yy - y) == 1 && xx == x)))
		return false;
	if (xx > 5 || xx < 3)
		return false;
	if (Color == 0) {
		if (yy < 0 || yy>2)
			return false;
	}
	else if (Color == 1) {
		if (yy > 9 || yy < 7)
			return false;
	}
	if (b.a[yy][xx] != NULL && b.a[yy][xx]->Col() == Color)
		return false;
	return true;
}

int King::move(Board& b)
{
	cout << "Enter destination (King):";
	return ChessMan::move(b);
}