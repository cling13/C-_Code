#include <iostream>
#include <cmath>

using namespace std;

int funtion(int a, int b);

int main()
{
	int t;
	int* n;
	int* m;

	cin >> t;

	n = new int[t];
	m = new int[t];

	for (int i = 0; i < t; i++)
	{
		cin >> n[i] >> m[i];
	}

	for (int i = 0; i < t; i++)
	{
		cout << funtion(n[i], m[i]) << endl;
	}

	return 0;
}

int funtion(int a, int b)
{
	int j = b - a;
	int i = sqrt(j);
	int cnt = (i * 2) - 1;

	int k = i * (i - 1) + i;

	if (k == j)
		return cnt;
	else if (k + i >= j)
		return cnt + 1;
	else
		return cnt + 2;

	return 0;
}