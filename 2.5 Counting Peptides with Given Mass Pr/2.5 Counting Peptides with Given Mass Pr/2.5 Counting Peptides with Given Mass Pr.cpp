// 2.5 Counting Peptides with Given Mass Pr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


int AminoAcidMass[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
map<int, unsigned long long int> tmp;


unsigned long long int CountPeptide(int mass)
{
	tmp[0] = 1;
	for (int i = 57; i <= mass; i++)
	{
		tmp[i] = 0;
		for (int j = 0; j < 18; j++)
		{
			if (tmp.find(i - AminoAcidMass[j]) != tmp.end())
			{
				tmp[i] += tmp[i - AminoAcidMass[j]];
			}
		}
	}
	return tmp[mass];
}


int main()
{
	int m;

	cin >> m;
	cout << CountPeptide(m);

	return 0;
}