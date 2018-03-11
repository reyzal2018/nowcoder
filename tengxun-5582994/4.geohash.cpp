#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	int l = -90;
	int r = 90;
	while (l <= r)
	{
		int m = (r + l) / 2;
		if (m > n) {
			r = m;
			s.push_back('0');
		}
		else {
			l = m;
			s.push_back('1');
		}
		if (s.length() == 6)
			break;
	}
	cout << s << endl;
    return 0;
}