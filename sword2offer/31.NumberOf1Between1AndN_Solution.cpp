//整数中1出现的次数（从1到n整数中1出现的次数）
//https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        char strN[20];
        sprintf(strN,"%d",n);
        return NumberOf1Between1AndN_Solution(strN);
    }
    
    int NumberOf1Between1AndN_Solution(const char* strN){
        if(strN == NULL || *strN < '0' || *strN > '9' || *strN == '\0')
            return 0;
        //假如传入34512
        int len = strlen(strN);
        int first = *strN - '0';
        if(len == 1 && first == 0) return 0;
        int numberOfFirst = 0;
        if(first > 1)
            //34512 有 10000个1
            numberOfFirst = pow(10,len-1);
        else if(first == 1)
            //14512 只有4513个1
            numberOfFirst = atoi(strN+1)+1;
        //4513 - 34512 除了第一位以外的1的个数
        //总共30000个数 对于后4位 固定1位 有1000个1 有4中固定方法
        int numberOfOther = 0;
        if(len >= 2)
            numberOfOther = first * (len-1) * pow(10,(len-2));
        else
            numberOfOther = first * (len-1);
        int numberRecursive = NumberOf1Between1AndN_Solution(strN+1);
        return numberOfFirst + numberOfOther+numberRecursive;
    }
};