//把字符串转换成整数
//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e
class Solution {
public:
    int StrToInt(string str) {
        if(str.length() == 0) return 0;
        int neg = 1;
        char* p = &str[0];
        if(*p == '-'){
            neg = -1;
            p++;
        }else if(*p == '+') p++;
        int result = 0;
        while(*p){
            if(*p < '0' || *p > '9') return 0;
            result = result * 10 + (*p-'0');
            p++;
        }
        return neg*result;
    }
};