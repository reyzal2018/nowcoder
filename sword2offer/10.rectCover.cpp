//矩形覆盖
//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6
class Solution {
public:
    int rectCover(int number) {
        //依旧是斐波拉契
        if(number <=2) return number;
        int pre = 2;
        int pre_pre = 1;
        for(int i = 2;i<number;i++){
            pre = pre+ pre_pre;
            pre_pre = pre - pre_pre;
        }
        return pre;
    }
};