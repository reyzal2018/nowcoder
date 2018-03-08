#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
 
using namespace std;
 
 
long long getSum(long long num)
{
    long long sum = 0;
    while (num)
    {
        sum += num;
        num /= 10;
    }
    return sum;
}
 
int main()
{
    long long sum;
    cin >> sum;
    long long l = 0;
    long long r = sum;
    long long num = -1;
 
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long newSum = getSum(mid);
        if (newSum == sum)
        {
            num = mid;
            break;
        }
        else if (newSum > sum) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
 
    }
    cout << num << endl;
    return 0;
}