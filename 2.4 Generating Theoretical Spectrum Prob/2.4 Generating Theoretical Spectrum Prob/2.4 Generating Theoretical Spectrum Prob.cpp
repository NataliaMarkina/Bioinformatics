// 2.4 Generating Theoretical Spectrum Prob.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> AminoacidMass = { { "G",57 },{ "A",71 },{ "S",87 },{ "P",97 },{ "V",99 },{ "T",101 },{ "C",103 },{ "I",113 },{ "L",113 },{ "N",114 },
									{ "D",115 },{ "K",128 },{ "Q",128 },{ "E",129 },{ "M",131 },{ "H",137 },{ "F",147 },{ "R",156 },{ "Y",163 },
									{ "W",186 } };

int GetMass(string str)
{
	int mass = 0;
	for (int i = 0; i < str.length(); i++)
		mass += AminoacidMass.at(str.substr(i, 1));
	return mass;
}

int main()
{
	string Peptide, Cyclospectrum;
	string subpeptide = " ";
	string ResMass;
	int mass;

	cin >> Peptide;

	cout << "0 ";

	for (int i = 1; i < Peptide.length(); i++)
	{
		for (int j = 0; j < Peptide.length(); j++)
		{
			if ((i + j) <= Peptide.length())
				subpeptide = Peptide.substr(j, i);
			else
				subpeptide = Peptide.substr(j) + Peptide.substr(0, i + j - Peptide.length());

			cout << GetMass(subpeptide) << " ";
		}
	}

	cout << GetMass(Peptide);

	return 0;
}