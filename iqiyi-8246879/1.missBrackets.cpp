#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int depth = 0;
    int count = 0;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '(')
            depth++;
        else if (depth == 0)
            count++;
        else
            depth--;
        i++;
    }
    cout << count + depth << endl;
    return 0;
}