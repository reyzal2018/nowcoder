//数组中重复的数字
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<char,int> mapCount;
        for(int i = 0;i<length;i++){
            if(++mapCount[numbers[i]] > 1){
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};