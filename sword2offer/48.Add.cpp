//不用加减乘除做加法
//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2){
            int tmp = num1;
            num1 = num1 ^ num2;
            num2 = (tmp & num2)<<1;
        }
        return num1;
    }
};