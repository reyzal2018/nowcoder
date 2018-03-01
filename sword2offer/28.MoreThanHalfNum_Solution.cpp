//数组中出现次数超过一半的数字
//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        int result = numbers[0];
        int count = 1;
        for(int i = 1;i<numbers.size();i++){
            if(numbers[i] == result)
                count++;
            else{
                if(--count == 0){
                    result = numbers[i];
                    count = 1;
                }
            }
        }
        //验证得到的数字是否确实大于一半
        int times = 0;
        for(int i = 0;i<numbers.size();i++){
            if(result == numbers[i])
                times++;
        }
        return times > numbers.size() / 2 ? result:0;
    }
};