//旋转数组的最小数字
//https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        int index1 = 0,index2 = rotateArray.size() - 1;
        int mid_index = index1;
        //index1始终指着第一递增数组
        //index2始终指着第二递增数组
        while(rotateArray[index1] >= rotateArray[index2]){
            if(index2 - index1 == 1){
                mid_index = index2;
                break;
            }
            mid_index = index1 + (index2-index1)/2;
            if(rotateArray[mid_index] >= rotateArray[index1])
                index1 = mid_index;
            if(rotateArray[mid_index] <= rotateArray[index2])
                index2 = mid_index;
        }
        return rotateArray[mid_index];
    }
};