//二进制中1的个数
//https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
             count++;
             n = n&(n-1);
         }
         return count;
     }
};