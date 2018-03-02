//构建乘积数组
//https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B = A;
        if(A.size() == 0) return B;
        B[0] = 1;
        for(int i = 1;i<A.size();i++){
            B[i] = B[i-1]*A[i-1];
        }
        int tmp = 1;
        for(int i = A.size()-2;i>=0;i--){
            tmp *= A[i+1];
            B[i] *= tmp;
        }
        return B;
    }
};