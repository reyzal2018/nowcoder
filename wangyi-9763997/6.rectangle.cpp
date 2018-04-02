#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<int> xSet;
	set<int> ySet;
	int n;
	cin >> n;
	vector<int> x1(n);
	vector<int> y1(n);
	vector<int> x2(n);
	vector<int> y2(n);
	for (int i = 0; i < n; i++)
		cin >> x1[i];
	for (int i = 0; i < n; i++)
		cin >> y1[i];
	for (int i = 0; i < n; i++)
		cin >> x2[i];
	for (int i = 0; i < n; i++)
		cin >> y2[i];
	xSet.insert(x1.begin(), x1.end());
	xSet.insert(x2.begin(), x2.end());
	ySet.insert(y1.begin(), y1.end());
	ySet.insert(y2.begin(), y2.end());
	int result = 0;
	//遍历所有的交点和顶点，最终重叠区域一定是一个矩形，矩形必定由交点和顶点构成
	for(auto& x:xSet)
		for (auto& y : ySet) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (x >= x1[i] && x < x2[i] && y >= y1[i] && y < y2[i])
					cnt++;
			}
			result = max(result, cnt);
		}
	cout << result << endl;
	return 0;
}