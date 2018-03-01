//连续子数组的最大和
//https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxSum = 0x80000000;
        int curSum = 0;
        for(auto& it:array){
            if(curSum < 0){
                curSum = it;
            }else{
                curSum += it;
            }
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};