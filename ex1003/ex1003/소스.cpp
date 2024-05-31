#include <iostream>

int* memo0;
int* memo1;

using namespace std;

int fibo0(int k);
int fibo1(int k);

int main()
{
	int* arr;
	int max = 0;
	int n;

	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	memo0 = new int[max + 1];
	memo1 = new int[max + 1];

	for (int i = 0; i <= max; i++)
	{
		memo0[i] = 0;
		memo1[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << fibo0(arr[i]) << " ";
		cout << fibo1(arr[i]);
		cout << endl;
	}
}

int fibo0(int k)
{
	if (k == 0)
		return 1;
	else if (k == 1)
		return 0;
	else if (memo0[k] != 0)
		return memo0[k];
	memo0[k] = fibo0(k - 1) + fibo0(k - 2);
	return memo0[k];
}

int fibo1(int k)
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	if (memo1[k] != 0)
		return memo1[k];
	memo1[k] = fibo1(k - 1) + fibo1(k - 2);
	return memo1[k];
}