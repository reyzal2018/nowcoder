//扑克牌顺子
//https://www.nowcoder.com/practice/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false; 
        sort(numbers.begin(),numbers.end());
        int godCount = 0;
        for(auto& it:numbers){
            if(it == 0) godCount++;
            else break;
        }
        bool ret = true;
        for(int i = godCount;i<4;i++){
            if(numbers[i+1] == numbers[i] || numbers[i+1] - numbers[i] -1 > godCount){
                ret = false;
                break;
            }
            godCount -= numbers[i+1]-numbers[i]-1;
        }
        return ret;
    }
};