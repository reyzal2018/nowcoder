#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
bool check(string& s) {
    int count = 0;
    for (auto& it : s) {
        if (it == '(') {
            count++;
        }
        else {
            count--;
        }
        if (count < 0) return false;
    }
    return count == 0;
}
 
int main()
{
    string s;
    cin >> s;
    set<string> record;
    //lcs的长度必定是s.length-1 所以只能改变一个字符,改变后还得继续是一个合法括号
    for (int i = 0; i < s.length(); i++) {
        string tmp(s);
        tmp.erase(i, 1);
        for (int j = 0; j < tmp.length(); j++) {
            string s1(tmp);
            s1.insert(j,1, s[i]);
            if (check(s1)) {
                record.insert(s1);
            }
        }
    }
    cout << record.size() - 1 << endl;
    return 0;
}