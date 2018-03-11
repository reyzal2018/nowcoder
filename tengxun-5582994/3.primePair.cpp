#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int num)
{
	for (int i = 2; i*i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int l = 2;
	int r = n;
	int result = 0;
	while (l <= r) {
		if (!IsPrime(l)) {
			l++;
			continue;
		}
		if (!IsPrime(r))
		{
			r--;
			continue;
		}
		if (l + r == n) {
			result++;
			l++;
			r--;
		}
		else if (l + r > n) {
			r--;
		}
		else if (l + r < n) {
			l++;
		}
	}
	cout << result << endl;
    return 0;
}