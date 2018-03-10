#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x[4];
    cin >> x[0] >> x[1] >> x[2] >> x[3];
	int A = (x[0] + x[2]) / 2;
	int B = A - x[0];
	int C = x[3] - B;
	if (A - B == x[0] && B - C == x[1] && A + B == x[2] && B + C == x[3]) {
		cout << A << " " << B << " " << C << endl;
	}
	else {
		cout << "No" << endl;
	}
    return 0;
}