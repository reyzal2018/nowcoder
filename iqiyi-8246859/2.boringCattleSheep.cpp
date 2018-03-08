#include <iostream>
#include <cmath>

using namespace std;

inline double C2(int n)
{
	return n*(n - 1) / 2.0;
}
int main()
{
	int n, m;
	cin >> n >> m;
	//当前选择有三种情况
	//1 n选2 m选0
	//2 n选1 m选1
	//3 n选0 m选2
	//分别计算三种情况的概率，然后递推 f(k) = 1 + f(k)*p(3)+f(k-1)*p(1)+f(k-2)*p(2) => f(k) = [1+f(k-1)*p(1)+f(k-2)*p(2)]/[1-p(3)]
	int all = n + m;
	double div = all*(all - 1) / 2.0;//c(all,2)
	double f0 = 0, f1 = all / 2.0;
	for (int i = 2; i <= m; i++)
	{
		//还剩i个不无聊人时的概率
		//无聊人=all-i
		double tmp = (1 + C2(i) / div*f0 + i*(all - i) / div*f1) / (1 - C2(all - i) / div);
		f0 = f1;
		f1 = tmp;
	}
	printf("%.1lf\n", round(f1 * 10) / 10);
	return 0;
}