//和为S的两个数字
//https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size() == 0) return result;
        int l = 0;
        int r = array.size() - 1;
        while(l < r){
            int tmpSum = array[l]+array[r];
            if(tmpSum == sum){
                result.push_back(array[l]);
                result.push_back(array[r]);
                break;
            }
            if(tmpSum > sum)
                r--;
            else
                l++;
        }
        return result;
    }
};