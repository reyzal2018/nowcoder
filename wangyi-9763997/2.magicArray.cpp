#include <bits/stdc++.h>
using namespace std;
 
int getCount(int n) {
    if (n % 3 == 0)
        return 2 * (n / 3);
    else
        return 2 * (n / 3) + n % 3 - 1;
}
 
//找规模
int main() {
    int l, r;
    cin >> l >> r;
    cout << getCount(r) - getCount(max(l - 1, 0)) << endl;
    return 0;
}