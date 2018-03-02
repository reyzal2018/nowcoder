//翻转单词顺序列
//https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3
class Solution {
public:
    void reverseString(char* begin,char* end){
        while(begin<end){
            swap(*begin++,*end--);
        }
    }
    string ReverseSentence(string str) {
        if(str.length() == 0) return str;
        reverseString(&str[0],&str[str.length()-1]);
        char* begin = &str[0];
        for(int i = 1;i<str.length();i++){
            if(str[i] == ' '){
                reverseString(begin,&str[i-1]);
                begin = &str[i]+1;
            }
        }
        if(begin < &str[str.length()-1])
            reverseString(begin,&str[str.length()-1]);
        return str;
    }
};