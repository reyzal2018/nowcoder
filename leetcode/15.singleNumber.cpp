//single-number
//https://www.nowcoder.com/practice/0bc646909e474ac5b031ec6836a47768
class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for(int i = 0;i<n;i++){
            res ^= A[i];
        }
        return res;
    }
};