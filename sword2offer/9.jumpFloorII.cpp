//变态跳台阶
//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387
class Solution {
public:
    //f(n) = f(n-1) + f(n-2) + ... + f(n - n + 1) + f(n - n)
    //f(n-1) = f(n-2)+...+ f(1) + f(0)
    //所以f(n) = 2*f(n-1);
    //f(0) = 1
    //f(1) = 1
    //f(2) = 2;
    int jumpFloorII(int number) {
        if(number <= 1) return number;
        int pre = 1;
        for(int i = 1;i<number;i++)
            pre *= 2;
        return pre;
    }
};