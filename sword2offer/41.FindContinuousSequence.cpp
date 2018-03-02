//和为S的连续正数序列
//https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int curSum = 0;
        list<int> l;
        vector<vector<int> > result;
        vector<int> line;
        for(int i = 1;i<=sum/2+sum%2+1;){
            if(curSum < sum){
                curSum += i;
                l.push_back(i);
                i++;
            }
            if(curSum == sum && l.size() > 1){
                line.resize(0);
                for(auto& it:l){
                    line.push_back(it);
                }
                result.push_back(line);
            }
            if(curSum >= sum){
                curSum -= l.front();
                l.pop_front();
            }
        }
        return result;
    }
};