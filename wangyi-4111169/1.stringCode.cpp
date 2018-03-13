#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{  
    string s;
    stringstream ss;
    cin >> s;
    char ch = s[0];
    int count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == ch) {
            count++;
        }
        else {
            ss << count << ch;
            count = 1;
            ch = s[i];
        }
    }
    ss << count << ch;
    cout << ss.str() << endl;
    return 0;
}