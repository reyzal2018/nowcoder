//丑数
//https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 0) return 0;
        vector<int> uglyNumber;
        uglyNumber.push_back(1);
        int i2 = 0,i3=0,i5=0;
        while(uglyNumber.size() < index){
            //下一个数是235的倍数
            int nextVal = min(min(uglyNumber[i2]*2,uglyNumber[i3]*3),uglyNumber[i5]*5);
            uglyNumber.push_back(nextVal);
            if(uglyNumber[i2]*2 == nextVal)
                i2++;
            if(uglyNumber[i3]*3 == nextVal)
                i3++;
            if(uglyNumber[i5]*5 == nextVal)
                i5++;
        }
        return uglyNumber.back();
    }
};