//正则表达式匹配
//https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //最好用动态规划来做 状态矩阵
        //1   0 0 0 0 0 0 0
        //    a b * a c * a
        //0 a 1 0 1 0 0 0 0
        //0 a 0 0 0 1 0 1 0
        //0 a 0 0 0 0 0 0 1
        int rows = strlen(str);
        int cols = strlen(pattern);
        vector<vector<bool>> dp(rows+1,vector<bool>(cols+1,false));
        dp[0][0] = true;//空字符串是相等的
        //对于第一行
        for(int i = 1;i<=dp[0].size();i++){
            if(pattern[i - 1] == '*') dp[0][i] = dp[0][i-2];
        }
        //其他每行
        for(int i = 1;i<=rows;i++)
            for(int j = 1;j<=cols;j++){
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(pattern[j-1] == '*'){
                    //如果*表示的字符和当前字符不相等，则*只能是0次
                    if(pattern[j-2] != str[i-1] && pattern[j-2] != '.') dp[i][j] = dp[i][j-2];
                    //如果相等，则可能0次 1次或多次
                    else dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                }
            }
        return dp[rows][cols];
    }
};