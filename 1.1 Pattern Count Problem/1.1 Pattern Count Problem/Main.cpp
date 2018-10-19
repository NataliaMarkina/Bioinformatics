#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strPattern, strGenome;
	cin >> strPattern;
	cin >> strGenome;
	int res = 0;
	for (int i = 0; i < strGenome.length(); i++)
	{
		if (strGenome[i] == strPattern[0])
		{
			if (strGenome.substr(i, strPattern.length()) == strPattern)
			{
				res++;
			}
		}
	}
	cout << res;

	return 0;
}