#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m;
    cin >> n >> m;
    set<string> remember;
    map<string,int> system;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        remember.insert(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        system[s] = s.length() * s.length();
    }
    int result = 0;
    for (auto& it : remember) {
        result += system[it];
    }
    cout << result << endl;
    return 0;
}