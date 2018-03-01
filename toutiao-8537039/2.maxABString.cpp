//编程题2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int m, n;
    cin >> n >> m;
    cin >> s;
	
    vector<int> count;
    count.push_back(0);
    int numA = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a') numA++;
        count.push_back(numA);
    }
	int l = 0;
	int r = n;
	int result = 0;
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		bool flag = false;
		//mid长度的连续子串是否可以得到
		for (size_t i = 0; i + mid <= n; i++)
		{
			if ((m >= (count[i + mid] - count[i])) ||
				(m >= (mid - count[i + mid] + count[i])))
			{
				flag = true;
				break;
			}
		}
		if (flag) {
			result = mid;
			l = mid + 1;
		}
		else
			r = mid;
	}
    cout << result << endl;
    return 0;
}