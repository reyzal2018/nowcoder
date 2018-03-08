#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int depth = 0;
	int maxdepth = 0;
	for (auto& it : s) {
		if (it == '(') {
			depth++;
			maxdepth = max(maxdepth, depth);
		}
		else {
			depth--;
		}
	}
	cout << maxdepth << endl;
	return 0;
}