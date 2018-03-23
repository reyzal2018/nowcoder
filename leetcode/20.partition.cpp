//palindrome-partitioning
//https://www.nowcoder.com/practice/f983806a2ecb4106a17a365a642a9632
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> item;
        dfs(0,s,item);
        return result;
    }
    
    void dfs(int cur,string& s,vector<string>& item)
    {
        if(cur == s.length()){
            result.push_back(item);
            return;
        }
        for(int i = 1;i<=s.length()-cur;i++){
            if(checkpalindrome(s.substr(cur,i))){
                item.push_back(s.substr(cur,i));
                dfs(cur+i,s,item);
                item.pop_back();
            }
        }
    }
    
    bool checkpalindrome(string s)
    {
        return s == string(s.rbegin(), s.rend());
    }
};