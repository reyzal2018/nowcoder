//斐波那契数列
//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3
class Solution {
public:
    int Fibonacci(int n) {
        //1 1 2 3 ...
        if(n < 2) return n;
        int pre = 1;
        int pre_pre = 1;
        for(int i = 2;i<n;i++){
            pre = pre + pre_pre;
            pre_pre = pre - pre_pre;
        }
        return pre;
    }
};