#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char buf[81];
    cin.getline(buf,81);
    string s(buf);
    for (auto& it : s) {
        if ((it >= 'a'&& it <= 'z') || (it >= 'A' && it <= 'Z')) {
            if (it == 'z') it = 'a';
            else if (it == 'Z') it = 'A';
            else it = it + 1;
        }
    }
    cout << s << endl;
    return 0;
}
