// 2.3 Subpeptides Count Problem.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	long int Lenght, NumberSubpeptides;

	cin >> Lenght;
	NumberSubpeptides = Lenght * (Lenght - 1);
	cout << NumberSubpeptides;

	return 0;
}

