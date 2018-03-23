//palindrome-partitioning-ii
//https://www.nowcoder.com/practice/1025ffc2939547e39e8a38a955de1dd3
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        //dp[i] 表示s中0~i子字符串所需要的最小切割数
        vector<int> dp(len,0);
        for(int i = 1;i<len;i++){
            //默认就是0~i-1的最小切割数+1
            dp[i] = dp[i-1]+1;
            for(int j = 0;j<i;j++){
                if(checkpalindrome(s.substr(j,i-j+1))){
                    if(j == 0){
                        //0~i全是回文，直接为0
                        dp[i] = 0;
                        break;
                    }
                    //j~i为回文，则最小切割数为 dp[j-1]+1
                    dp[i] = min(dp[i],dp[j - 1]+1);
                }
            }
        }
        return len == 0?0:dp[len-1];
    }
    bool checkpalindrome(string s){
        return s == string(s.rbegin(),s.rend());
    }
};
