#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int base[4];
    base[3] = 1;//aaaa aaab的间距
    base[2] = 25 * base[3] + 1;//aaa aab的间距
    base[1] = 25 * base[2] + 1;//aa ab的间距
    base[0] = 25 * base[1] + 1;//a b的间距
    long long result = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        result += base[i] * (s[i] - 'a');
    }
    cout << result << endl;
    return 0;
}