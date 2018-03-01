//字符串的排列
//https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.length() == 0) return result;
        //用set自动去重复
        set<string> s;
        Permutation(&str[0],&str[0],s);
        for(auto& it:s)
            result.push_back(it);
        return result;
    }
    
    void Permutation(char* str,char* begin,set<string>& s){
        if(*begin == '\0'){
            s.insert(str);
            return;
        }
        for(char* ch = begin;*ch != '\0';ch++){
            swap(*ch,*begin);
            Permutation(str,begin+1,s);
            swap(*ch,*begin);
        }
    }
};