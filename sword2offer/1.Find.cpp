//二维数组中的查找
//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0) return false;
        int i = 0;
        int j = array.size() - 1;
        while(i < array.size() && j >= 0){
            if(array[i][j] > target){
                j--;
            }else if(array[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};