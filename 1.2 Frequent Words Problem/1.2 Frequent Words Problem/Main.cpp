#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strText, strFrequentPatterns, strPattern;
	int k, maxCount = 0;
	cin >> strText;
	cin >> k;
	int *count = new int[strText.length() - k + 1];
	for (int i = 0; i <= strText.length() - k; i++)
	{
		strPattern = strText.substr(i, k);
		count[i] = 0;
		for (int i = 0; i < strText.length(); i++)
		{
			if (strText[i] == strPattern[0])
			{
				if (strText.substr(i, strPattern.length()) == strPattern)
				{
					count[i]++;
				}
			}
		}
	}
	for (int i = 0; i <= strText.length() - k; i++)
	{
		if (count[i] > maxCount)
			maxCount = count[i];
	}
	for (int i = 0; i <= strText.length() - k; i++)
	{
		if (count[i] == maxCount)
			strFrequentPatterns = strFrequentPatterns + " " + strText.substr(i, k);
	}
	string Pattern, strResult;
	for (int i = 1; i < strFrequentPatterns.length(); i = i + (k + 1))
	{
		Pattern = strFrequentPatterns.substr(i, k);
		if (strResult.find(Pattern) == -1)
			strResult = strResult + " " + Pattern;
	}
	strResult = strResult.erase(0, 1);
	cout << strResult;

	return 0;
}