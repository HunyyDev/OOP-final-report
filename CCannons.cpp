#include "CCannons.h"
#include <iostream>

using namespace std;

Cannons::Cannons()
{
}

Cannons::Cannons(int c)
{
	Color = c;
}

Cannons::Cannons(int a, int b)
{
	x = a;
	y = b;
	if (y >= 0 && y <= 4)
		Color = 0;
	if (y >= 5 && y <= 9) {
		Color = 1;
	}
}

void Cannons::output()
{
	if (Col() == 0)
		cout << "Ca0";
	else
		cout << "Ca1";
}

bool Cannons::check(int xx, int yy, Board b)
{
	if (xx < 0 || xx> 8 || yy < 0 || yy > 9)
		return false;
	if (!((xx != x && yy == y) || (xx == x && yy != y)))
		return false;
	if (b.a[yy][xx] == NULL) {
		if (xx == x) {
			if (yy > y) {
				for (int i = y + 1; i < yy; i++) {
					if (b.a[i][x] != NULL)
						return false;
				}
			}
			else if (yy < y) {
				for (int i = y - 1; i > yy; i--) {
					if (b.a[i][x] != NULL)
						return false;
				}
			}
		}
		if (yy == y) {
			if (xx > x) {
				for (int i = x + 1; i < xx; i++) {
					if (b.a[y][i] != NULL)
						return false;
				}
			}
			if (xx < x) {
				for (int i = x; i > xx; i--) {
					if (b.a[y][i] != NULL)
						return false;
				}
			}
		}
	}
	if (b.a[yy][xx] != NULL && b.a[yy][xx]->Col() != Color) {
		int temp;
		if (xx == x) {
			temp = 0;
			if (yy > y) {
				for (int i = y + 1; i < yy; i++) {
					if (b.a[i][x] != NULL)
						temp++;
				}
				if (temp != 1)
					return false;
			}
			if (yy < y) {
				for (int i = y - 1; i > yy; i--) {
					if (b.a[i][x] != NULL) {
						temp++;
					}
				}
				if (temp != 1)
					return false;
			}
		}
		if (yy == y) {
			int temp;
			if (xx > x) {
				temp = 0;
				for (int i = x + 1; i < xx; i++) {
					if (b.a[y][i] != NULL)
						temp++;
				}
				if (temp != 1)
					return false;
			}
			else if (xx < x) {
				temp = 0;
				for (int i = x - 1; i > xx; i--) {
					if (b.a[y][i] != NULL) {
						temp++;
					}
				}
				if (temp != 1)
					return false;
			}
		}
	}
	if (b.a[yy][xx] != NULL && b.a[yy][xx]->Col() == Color)
		return false;
	return true;

}

int Cannons::move(Board& b)
{
	cout << "Enter destination (Cannon):";
	return ChessMan::move(b);
}
