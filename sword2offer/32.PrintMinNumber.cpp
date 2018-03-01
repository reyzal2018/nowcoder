//把数组排成最小的数
//https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993
class Solution {
public:
    static bool cmp(int i1,int i2){
        stringstream ss1,ss2;
        ss1<<i1<<i2;
        ss2<<i2<<i1;
        return ss2.str().compare(ss1.str())>0;
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        stringstream ss;
        for(auto& it:numbers)
            ss<<it;
        return ss.str();
    }
};