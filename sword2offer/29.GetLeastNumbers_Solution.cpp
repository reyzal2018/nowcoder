//最小的K个数
//https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        set<int,greater<int>> s;
        vector<int> result;
        if(k == 0 || k > input.size()) return result;
        for(auto& it:input){
            if(s.size() < k){
                s.insert(it);
            }else{
                auto itSet = s.begin();
                if(*itSet > it){
                    s.erase(itSet);
                    s.insert(it);
                }
            }
        }
        for(auto& it:s){
            result.push_back(it);
        }
        return result;
    }
};