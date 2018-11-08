// 2.1 Protein Translation Problem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int A = 0, C = 1, G = 2, U = 3;
	int pos1, pos2, pos3;
	string Pattern, Peptide;
	string CodonTranslator[4][4][4];
	string str = "ACGU";

	CodonTranslator[A][A][A] = "K";
	CodonTranslator[A][A][C] = "N";
	CodonTranslator[A][A][G] = "K";
	CodonTranslator[A][A][U] = "N";
	CodonTranslator[A][C][A] = "T";
	CodonTranslator[A][C][C] = "T";
	CodonTranslator[A][C][G] = "T";
	CodonTranslator[A][C][U] = "T";
	CodonTranslator[A][G][A] = "R";
	CodonTranslator[A][G][C] = "S";
	CodonTranslator[A][G][G] = "R";
	CodonTranslator[A][G][U] = "S";
	CodonTranslator[A][U][A] = "I";
	CodonTranslator[A][U][C] = "I";
	CodonTranslator[A][U][G] = "M";
	CodonTranslator[A][U][U] = "I";

	CodonTranslator[C][A][A] = "Q";
	CodonTranslator[C][A][C] = "H";
	CodonTranslator[C][A][G] = "Q";
	CodonTranslator[C][A][U] = "H";
	CodonTranslator[C][C][A] = "P";
	CodonTranslator[C][C][C] = "P";
	CodonTranslator[C][C][G] = "P";
	CodonTranslator[C][C][U] = "P";
	CodonTranslator[C][G][A] = "R";
	CodonTranslator[C][G][C] = "R";
	CodonTranslator[C][G][G] = "R";
	CodonTranslator[C][G][U] = "R";
	CodonTranslator[C][U][A] = "L";
	CodonTranslator[C][U][C] = "L";
	CodonTranslator[C][U][G] = "L";
	CodonTranslator[C][U][U] = "L";

	CodonTranslator[G][A][A] = "E";
	CodonTranslator[G][A][C] = "D";
	CodonTranslator[G][A][G] = "E";
	CodonTranslator[G][A][U] = "D";
	CodonTranslator[G][C][A] = "A";
	CodonTranslator[G][C][C] = "A";
	CodonTranslator[G][C][G] = "A";
	CodonTranslator[G][C][U] = "A";
	CodonTranslator[G][G][A] = "G";
	CodonTranslator[G][G][C] = "G";
	CodonTranslator[G][G][G] = "G";
	CodonTranslator[G][G][U] = "G";
	CodonTranslator[G][U][A] = "V";
	CodonTranslator[G][U][C] = "V";
	CodonTranslator[G][U][G] = "V";
	CodonTranslator[G][U][U] = "V";

	CodonTranslator[U][A][A] = "*";
	CodonTranslator[U][A][C] = "Y";
	CodonTranslator[U][A][G] = "*";
	CodonTranslator[U][A][U] = "Y";
	CodonTranslator[U][C][A] = "S";
	CodonTranslator[U][C][C] = "S";
	CodonTranslator[U][C][G] = "S";
	CodonTranslator[U][C][U] = "S";
	CodonTranslator[U][G][A] = "*";
	CodonTranslator[U][G][C] = "C";
	CodonTranslator[U][G][G] = "W";
	CodonTranslator[U][G][U] = "C";
	CodonTranslator[U][U][A] = "L";
	CodonTranslator[U][U][C] = "F";
	CodonTranslator[U][U][G] = "L";
	CodonTranslator[U][U][U] = "F";

	cin >> Pattern;

	for (int i = 0; i < Pattern.length() - 2; i += 3)
	{
		pos1 = str.find(Pattern.substr(i, 1));
		pos2 = str.find(Pattern.substr(i + 1, 1));
		pos3 = str.find(Pattern.substr(i + 2, 1));

		if (CodonTranslator[pos1][pos2][pos3] == "*")
			break;
		else
			Peptide = Peptide + CodonTranslator[pos1][pos2][pos3];
	}

	cout << Peptide;

	return 0;
}