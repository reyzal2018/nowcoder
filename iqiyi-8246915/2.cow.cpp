#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cows(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cows[i];
	}
	sort(cows.begin(), cows.end());
	long long result = 1;
	for (int i = 0; i < n; i++)
	{
		result = ((cows[i] - i) % 1000000007 * result) % 1000000007;
	}
	cout << result<< endl;
	return 0;
}