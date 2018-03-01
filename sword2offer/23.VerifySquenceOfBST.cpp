//二叉搜索树的后序遍历序列
//https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return _VerifySquenceOfBST(&sequence[0],sequence.size());
    }
    
    bool _VerifySquenceOfBST(int* data,int size){
        if(size <= 1) return true;
        int root = data[size-1];
        int left_size = 0;
        for(int i = 0;i<size-1;i++){
            if(data[i] < root)
                left_size++;
            else
                break;
        }
        for(int i = left_size;i<size-1;i++){
            if(data[i] < root) return false;
        }
        return _VerifySquenceOfBST(data,left_size)&&
            _VerifySquenceOfBST(data+left_size,size-1-left_size);
    }
};