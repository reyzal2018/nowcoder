//word-break
//https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //dp[i] 表示0-i是否可被单词组合成功
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i<len; i++) {
            if (!dp[i]) continue;
            for (int j = i; j<len; j++) {
                auto word = dict.find(s.substr(i, j - i + 1));
                if (word != dict.end()) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[len];
    }
};