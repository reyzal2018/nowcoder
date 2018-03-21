//single-number-ii
//https://www.nowcoder.com/practice/1097ca585245418ea2efd0e8b4d9eb7a
class Solution {
public:
    //32大小的数组分别统计A中元素每一位中1的个数。出现3次的结果为3的倍数
    int singleNumber(int A[], int n) {
        int bit[32] = {0};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<32;j++){
                bit[j] += getBit(A[i],j);
            }
        }
        int res = 0;
        for(int i = 0;i<32;i++){
            res |= (bit[i]%3) << i;
        }
        return res;
    }
    
    int getBit(int n,int i){
        return n&(1<<i)?1:0;
    }
};