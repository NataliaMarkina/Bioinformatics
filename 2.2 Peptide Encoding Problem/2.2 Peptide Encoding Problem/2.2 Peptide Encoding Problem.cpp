// 2.2 Peptide Encoding Problem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


map<string, char> GeneticCode = { { "AAU",'N' },{ "AAC",'N' },{ "AAA",'K' },{ "AAG",'K' },{ "ACU",'T' },{ "ACC",'T' },{ "ACA",'T' },{ "ACG",'T' },
								{ "AGU",'S' },{ "AGC",'S' },{ "AGA",'R' },{ "AGG",'R' },{ "AUU",'I' },{ "AUC",'I' },{ "AUA",'I' },{ "AUG",'M' },
								{ "CAU",'H' },{ "CAC",'H' },{ "CAA",'Q' },{ "CAG",'Q' },{ "CCU",'P' },{ "CCC",'P' },{ "CCA",'P' },{ "CCG",'P' },
								{ "CGU",'R' },{ "CGC",'R' },{ "CGA",'R' },{ "CGG",'R' },{ "CUU",'L' },{ "CUC",'L' },{ "CUA",'L' },{ "CUG",'L' },
								{ "GAU",'D' },{ "GAC",'D' },{ "GAA",'E' },{ "GAG",'E' },{ "GCU",'A' },{ "GCC",'A' },{ "GCA",'A' },{ "GCG",'A' },
								{ "GGU",'G' },{ "GGC",'G' },{ "GGA",'G' },{ "GGG",'G' },{ "GUU",'V' },{ "GUC",'V' },{ "GUA",'V' },{ "GUG",'V' },
								{ "UAU",'Y' },{ "UAC",'Y' },{ "UAA",'*' },{ "UAG",'*' },{ "UCU",'S' },{ "UCC",'S' },{ "UCA",'S' },{ "UCG",'S' },
								{ "UGU",'C' },{ "UGC",'C' },{ "UGA",'*' },{ "UGG",'W' },{ "UUU",'F' },{ "UUC",'F' },{ "UUA",'L' },{ "UUG",'L' } };

string DnaToRna(string dna)
{
	for (int i = 0; i < dna.length(); i++)
	{
		if (dna[i] == 'T')
			dna[i] = 'U';
	}
	return dna;
}

string Reverse(string strPattern)
{
	string strReverse;
	strReverse.resize(strPattern.length());
	for (int i = strPattern.length() - 1; i >= 0; i--)
	{
		switch (strPattern[i])
		{
		case 'A':
			strReverse[strPattern.length() - 1 - i] = 'T';
			break;
		case 'T':
			strReverse[strPattern.length() - 1 - i] = 'A';
			break;
		case 'C':
			strReverse[strPattern.length() - 1 - i] = 'G';
			break;
		case 'G':
			strReverse[strPattern.length() - 1 - i] = 'C';
			break;
		}
	}
	return strReverse;
}

string RnaToPeptide(string rna)
{
	string peptide;
	for (int j = 0; j < rna.length(); j += 3)
	{
		peptide += GeneticCode.at(rna.substr(j, 3));
	}
	return peptide;
}


int main()
{
	string dna, peptide, result;
	string pathDna;
	string reversePathDna;
	string pathRna, reversePathRna;
	string pathRnaPeptide, reversePathRnaPeptide;

	cin >> dna;
	cin >> peptide;

	for (int i = 0; i <= dna.length() - peptide.length() * 3; i++)
	{
		pathDna = dna.substr(i, peptide.length() * 3);
		reversePathDna = Reverse(pathDna);
		pathRna = DnaToRna(pathDna);
		reversePathRna = DnaToRna(reversePathDna);

		pathRnaPeptide = RnaToPeptide(pathRna);
		reversePathRnaPeptide = RnaToPeptide(reversePathRna);

		if (pathRnaPeptide == peptide || reversePathRnaPeptide == peptide)
			result += dna.substr(i, peptide.length() * 3) + "\n";
	}

	cout << result;

	return 0;
}