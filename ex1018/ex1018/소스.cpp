#include <iostream>

using namespace std;

int divi(int a);

int main()
{
	int n;
	int cnt = 0;

	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		if (i < 100)
			cnt++;
		else
			cnt += divi(i);
	}

	cout << cnt;

	return 0;
}

int divi(int a)
{
	int t[4];
	int k = 0;
	int b = a;

	while (a != 0)
	{
		t[k] = ((a / 10) % 10) - (a % 10);
		a /= 10;

		k++;
	}

	if (b < 1000 && t[0] == t[1])
		return 1;
	else if (t[0] == t[1] && t[1] == t[2])
		return 1;
	else
		return 0;

}