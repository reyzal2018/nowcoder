//求1+2+3+...+n
//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1
typedef int(*FUN)(int);
FUN f[2];
static int fun(int n) {
    return n + f[!n](n - 1);
}
static int endFun(int n) {
    return 0;
}
class Solution {
public:
	int Sum_Solution(int n) {
        f[0] = fun;
		f[1] = endFun;
		return fun(n);
	}
};