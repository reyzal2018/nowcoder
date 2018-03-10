#include <bits/stdc++.h>

using namespace std;

long long f(long long N)
{
    if (N <= 1) return N;
    if (N & 1)
    {
		return N + (N - 1) * (N - 1) / 4 + f(N >> 1);
    }
    else
    {
        //偶数
		return (N >> 1) * (N >> 1) + f(N >> 1);
    }
}

int main()
{
	long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}