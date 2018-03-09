#include <iostream>
#include <string>

using namespace std;
inline void swap(char& a, char& b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

inline bool isUpper(char& a) {
	return a >= 'A' && a <= 'Z';
}

int main()
{
	string s;
	while (cin >> s) {
		char* p = &s[0];
		while (*p) {
			while (*p && isUpper(*p)) {
				p++;
			}
			while (*p && p > &s[0] && isUpper(*(p - 1))) {
				swap(*p, *(p - 1));
				p--;
			}
			p++;
		}
		cout << s << endl;
	}
	return 0;
}