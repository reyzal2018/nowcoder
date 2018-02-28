//调整数组顺序使奇数位于偶数前面
//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0;
        int j;
        while(i < array.size()){
            while(i < array.size() && array[i] & 1){
                i++;
            }
            if(i == array.size()) break;
            j = i+1;
            while(j < array.size() && !(array[j] & 1)){
                j++;
            }
            if(j == array.size()) break;
            while(i < j){
                swap(array[j],array[j-1]);
                j --;
            }
        }
    }
};