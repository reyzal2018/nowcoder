#include <bits/stdc++.h>
 
using namespace std;
 
int result = 0;
 
inline void swap(char& a,char& b) {
    a = a^b;
    b = a^b;
    a = a^b;
    result++;
}
 
int swapString(string s,char ch)
{
    result = 0;
    char* str = &s[0];
    char* p = str;
    while (*p) {
        while (*p && *p == ch) {
            p++;
        }
        if (!*p) break;
        while (p - 1 >= str && *(p - 1) == ch) {
            swap(*p, *(p - 1));
            p--;
        }
        p++;
    }
    return result;
}
 
int main()
{
    string s;
    cin >> s;
    cout << min(swapString(s, 'B'), swapString(s, 'G')) << endl;
    return 0;
}