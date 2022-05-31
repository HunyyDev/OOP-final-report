#include <iostream>
#include "CPlayer.h"
#include "CBoard.h"

using namespace std;

int main()
{
	Player A, B;
	Board C;
	KhoiTao(A, B, C);

	int turn = 0;
	while (A.KingIsDead() == 0 && B.KingIsDead() == 0)
	{
		C.Display();
		if (turn % 2 == 0)
		{
			cout << "Luot cua nguoi choi 0:\n";
			A.TakeTurn(C);
		}
		else
		{
			cout << "Luot cua nguoi choi 1:\n";
			B.TakeTurn(C);
		}
		turn++;
	}
	C.Display();
	if (A.KingIsDead() == 1)
	{
		cout << "Nguoi choi 1 chien thang";
	}
	else
	{
		cout << "Nguoi choi 0 chien thang";
	}
	return 0;
}