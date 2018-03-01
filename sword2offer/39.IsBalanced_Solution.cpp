//平衡二叉树
//https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return IsBalanced_Solution(pRoot,depth);
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot,int& depth){
        if(pRoot == NULL){
            depth = 0;
            return true;
        } 
        int left,right;
        bool ret = IsBalanced_Solution(pRoot->left,left);
        if(!ret) return false;
        ret = IsBalanced_Solution(pRoot->right,right);
        if(!ret) return false;
        depth = max(left,right)+1;
        return abs(left-right) <= 1;
    }
};