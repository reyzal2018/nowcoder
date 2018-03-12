#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int result = s[0]-'0';
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            result += s[i + 1] - '0';
            i++;
        }
        else if (s[i] == '-') {
            result -= s[i + 1] - '0';
            i++;
        }
        else {
            result *= s[i + 1] - '0';
            i++;
        }
    }
    cout << result << endl;
    return 0;
}