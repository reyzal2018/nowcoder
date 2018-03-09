#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	int maxcnt = 0;
	//A
	for (int i1 = 0; i1 < n; i1++)
	{
		//B
		for (int i2 = i1+1; i2 < n; i2++)
		{
			//C
			for (int i3 = 0; i3 < n; i3++)
			{
				if (i1 == i3 || i3 == i2 || (x[i1]-x[i2])*(y[i3] - y[i2]) == (y[i1] - y[i2])*(x[i3] - x[i2]))
				{
					continue;
				}
				int cnt = 0;
				for (int i4 = 0; i4 < n; i4++)
				{
					//共线或垂直
					if ((x[i1] - x[i2])*(y[i1] - y[i4]) == (y[i1] - y[i2])*(x[i1] - x[i4]) ||
						(x[i1] - x[i2])*(x[i3] - x[i4]) == -(y[i1] - y[i2])*(y[i3] - y[i4]))
					{
						cnt++;
					}
					maxcnt = max(maxcnt, cnt);
				}
			}
		}
	}
	cout << (maxcnt == 0 ? n : maxcnt) << endl;
	delete x;
	delete y;
	return 0;
}