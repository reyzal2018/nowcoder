//数组中只出现一次的数字
//https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int num = 0;
        for(auto& it:data){
            num ^= it;
        }
        int i;
        for(i = 0;i<32;i++){
            if( (num >> i) & 1){
                break;
            }
        }
        *num1 = 0;
        for(auto& it:data){
            if((it>>i)&1){
                *num1 ^= it;
            }
        }
        *num2 = num ^ *num1;
        if(*num1 > *num2)
            swap(*num1,*num2);
    }
};