#include <iostream>

using namespace std;

int main()
{
	long n;
	long i = 1;
	long idx = 1;
	long a, b;

	cin >> n;

	while (1)
	{
		n -= i;

		if (n <= 0)
		{
			n += i;
			break;
		}

		idx++;
		i++;
	}

	if (idx % 2 == 1)
	{
		a = idx;
		b = 1;
	}
	else
	{
		a = 1;
		b = idx;
	}

	for (int i = 1; i < n; i++)
	{
		if (idx % 2 == 1)
		{
			a--;
			b++;
		}
		else
		{
			a++;
			b--;
		}
	}

	cout << a << "/" << b;

	return 0;
}