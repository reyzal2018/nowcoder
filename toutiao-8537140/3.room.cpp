//编程题2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    while (cin >> n) {
        cin >> x;
        if (n == 0) continue;
        vector<long long> data(n);
		long long mindata = 0x7fffffff;
        for (size_t i = 0; i < n; i++) {
            cin >> data[i];
            mindata = min(data[i], mindata);
        }
        if (mindata == data[x - 1]) {
            for (auto& it : data) {
                it -= mindata;
            }
            data[x - 1] = mindata * n;
        } else {
            //从x往前出发，遇到的第一个最小值就是开始点
            int begin = x - 1 + n;
            int count = 0;
            while (mindata != data[begin % n]) {
                data[begin % n]--;
                count++;
                begin--;
            }
            for (auto& it : data) {
                it -= mindata;
            }
            data[begin % n] = mindata * n + count;
        }
		for (size_t i = 0; i < n; i++)
		{
			cout << data[i] << (i == n - 1 ? '\n' : ' ');
		}
    }

    return 0;
}