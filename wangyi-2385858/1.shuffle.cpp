#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> data(2*n);
		for (int i = 0; i < n; i++)
		{
			cin >> data[i * 2] >> data[i * 2 + 1];
		}
		for (int i = 0; i < k; i++)
		{
			vector<int> d1(data.begin(), data.begin() + n);
			vector<int> d2(data.begin() + n, data.begin() + 2*n);
			int c = 0;
			for (int j = 0; j < n; j++)
			{
				data[c++] = d1[j];
				data[c++] = d2[j];
			}
		}
		for (int i = 0; i < 2*n; i++)
		{
			cout << data[i] << (i == 2 * n - 1 ? "\n" : " ");
		}
	}
	return 0;
}