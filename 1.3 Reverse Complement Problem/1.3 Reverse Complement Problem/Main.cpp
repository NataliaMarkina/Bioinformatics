#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strPattern, strReverse;
	cin >> strPattern;
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
	cout << strReverse;

	return 0;
}
