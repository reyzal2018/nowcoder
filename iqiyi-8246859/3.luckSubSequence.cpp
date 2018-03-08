#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >>n;
    int res = 0;
    while(n--){
        int x;
        cin >>x;
        while(!s.empty() && s.top() <= x){
            res = max(s.top()^x,res);
            //有x的情况下，x前面比x小的数不可能再得到新的结果
            //因为如果新数y是最大值，那么结果就是y^x
            //如果y不是最大值，那么结果就是x^y或者x^(x以前的数)
            //x^(x以前的数)在之前已经计算过，所以这里可以将小于x的数pop
            s.pop();
        }
        //s.top和x构成最大值，
        //s.top和s中的其他数之前已经计算过
        if(!s.empty()) res = max(s.top()^x,res);
        s.push(x);
    }
    cout<<res<<endl;
    return 0;
}