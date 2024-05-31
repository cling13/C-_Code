#include <iostream>

using namespace std;

void Search(int** arr, int y, int x);

int* stackx;
int* stacky;
int cnt = 0;
int ans = 0;
int t, n, m, k;

int main()
{
	int* x, * y;
	int** arr;

	cin >> t;

	for (int q = 0; q < t; q++)
	{
		cin >> m >> n >> k;

		stackx = new int[k];
		stacky = new int[k];

		x = new int[k];
		y = new int[k];

		ans = 0;

		for (int i = 0; i < k; i++)
			cin >> x[i] >> y[i];

		arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[m];
			for (int j = 0; j < m; j++)
				arr[i][j] = 0;
		}

		for (int i = 0; i < k; i++)
		{
			arr[y[i]][x[i]] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					Search(arr, i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;

		delete[] x;
		delete[] y;
		delete[] stackx;
		delete[] stacky;

		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}

	return 0;
}

void Search(int** arr, int y, int x)
{
	while (1)
	{
		if (x != m - 1 && arr[y][x + 1] == 1)
		{
			arr[y][x] = 0;
			stackx[cnt] = x;
			stacky[cnt] = y;
			cnt++;
			x++;
			Search(arr, y, x);
		}
		else if (y != n - 1 && arr[y + 1][x] == 1)
		{
			arr[y][x] = 0;
			stackx[cnt] = x;
			stacky[cnt] = y;
			cnt++;
			y++;
			Search(arr, y, x);
		}
		else if (x != 0 && arr[y][x - 1] == 1)
		{
			arr[y][x] = 0;
			stackx[cnt] = x;
			stacky[cnt] = y;
			cnt++;
			x--;
			Search(arr, y, x);
		}
		else if (y != 0 && arr[y - 1][x] == 1)
		{
			arr[y][x] = 0;
			stackx[cnt] = x;
			stacky[cnt] = y;
			cnt++;
			y--;
			Search(arr, y, x);
		}
		else if (cnt > 0)
		{
			arr[y][x] = 0;
			cnt--;
			x = stackx[cnt];
			y = stacky[cnt];
			Search(arr, y, x);
		}
		else
			break;
	}
}