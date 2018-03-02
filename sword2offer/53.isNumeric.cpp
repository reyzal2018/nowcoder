//表示数值的字符串
//https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL) return false;
        char* p = string;
        if(*p == '+' || *p == '-')
            p++;
        bool dotflag = false;
        bool eflag = false;
        while(*p != '\0'){
            if(*p >= '0' && *p <= '9'){
                p++;
                continue;
            }
            if(*p == '.'){
                if(dotflag || eflag) return false;
                dotflag = true;
                p++;
                continue;
            }
            if(*p == 'e' || *p == 'E'){
                if(eflag) return false;
                eflag = true;
                p++;
                if(*p == '+' ||*p == '-')
                    p++;
                if(p == '\0') return false;
                continue;
            }else
                return false;
        }
        return true;
    }

};