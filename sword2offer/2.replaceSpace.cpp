//替换空格
//https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423
class Solution {
public:
    int error_;
	void replaceSpace(char *str,int length) {
        int space_count = 0;
        error_ = 0;
        char *p = str,*q;
        while(*p){
            if(*p++ == ' ') 
                space_count++;
        } 
        q = p + space_count * 2;
        if(q - str > length){
            error_ = 1;
            return;
        }
        while(p >= str){
            if(*p == ' '){
                *q-- = '0';
                *q-- = '2';
                *q-- = '%';
            }else{
                *q-- = *p;
            }
            p--;
        }
	}
};