//第一个只出现一次的字符
//https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> m;
        for(auto& it:str)
            m[it]++;
        for(int i = 0;i<str.length();i++){
            if(m[str[i]] == 1) return i;
        }
        return -1;
    }
};