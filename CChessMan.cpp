#include "CChessMan.h"
#include <string>
#include <iostream>

using namespace std;

int ChessMan::isDead()
{
	return dead;
}

void ChessMan::die()
{
	dead = 1;
}

int ChessMan::Col()
{
	return Color;
}

int ChessMan::move(Board& b)
{
	int xx, yy;
	cout << "\nNhap x = -1 de chon lai con co: ";
	cout << "\nNhap x: ";
	cin >> xx;
	if (xx == -1)
		return 1;
	cout << "Nhap y: ";
	cin >> yy;
	while (check(xx, yy, b) == false) {
		cout << "Khong hop le, nhap lai\n";
		cout << "Nhap x: ";
		cin >> xx;
		if (xx == -1)
			return 1;
		cout << "Nhap y: ";
		cin >> yy;
	}

	if (b.a[yy][xx] != NULL)
		b.a[yy][xx]->die();

	b.a[yy][xx] = b.a[y][x];
	b.a[y][x] = NULL;
	x = xx;
	y = yy;

	return 0;
}


bool ChessMan::check(Board b)
{
	return true;
}

bool ChessMan::check(int xx, int yy, Board b)
{
	return false;
}

void ChessMan::output()
{
	return;
}

string ChessMan::getViTri()
{
	return '(' + to_string(x) +","+ to_string(y) + ')';
}
