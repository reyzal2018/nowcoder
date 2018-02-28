//跳台阶
//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4
class Solution {
public:
    int jumpFloor(int number) {
        if(number < 2) return number;
        int pre = 2;
        int pre_pre = 1;
        for(int i = 2;i<number;i++){
            pre = pre+pre_pre;
            pre_pre = pre-pre_pre;
        }
        return pre;
    }
};