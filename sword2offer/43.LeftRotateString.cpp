//左旋转字符串
//https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec
class Solution {
public:
    void reverseString(char* beg,char* end){
        while(beg < end){
            swap(*beg,*end);
            beg++;
            end--;
        }
    }
    
    string LeftRotateString(string str, int n) {
        if(str.length() <= 1) return str;
        reverseString(&str[0],&str[n-1]);
        reverseString(&str[n],&str[str.length()-1]);
        reverseString(&str[0],&str[str.length()-1]);
        return str;
    }
};