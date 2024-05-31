#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string word1, string word2);

int main()
{
	int n;

	cin >> n;

	vector<string>arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}

bool compare(string word1, string word2)
{
	int s1 = size(word1);
	int s2 = size(word2);

	if (s1 != s2)
	{
		return s1 < s2;
	}

	else
	{
		return word1 < word2;
	}
}