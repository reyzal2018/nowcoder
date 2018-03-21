//word-break-ii
//https://www.nowcoder.com/practice/bd73f6b52fdc421d91b14f9c909f9104
class Solution {
    public:
    map<string, vector<string>> mapResult;
    //在牛客网无法AC，因为输出结果的顺序和它题目的顺序不一致，在Leetcode网可以AC
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        dfs(s, dict, result);
        return result;
    }
 
    void dfs(string s, unordered_set<string>& dict, vector<string>& result)
    {
        if (s == "") {
            result.push_back("");
            return;
        }
        if (mapResult.count(s) > 0) {
            result = mapResult[s];
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            string sub = s.substr(0, i + 1);
            if (dict.count(sub) == 0)
                continue;
            vector<string> rightList;
            dfs(s.substr(i + 1), dict, rightList);
            if (rightList.size() == 0)
                continue;
            for (auto& it : rightList) {
                string tmp;
                tmp.append(sub);
                if(it.length() > 0)
                    tmp.append(" ");
                tmp.append(it);
                result.insert(result.begin(),tmp);
            }
        }
        mapResult[s] = result;
    }
};