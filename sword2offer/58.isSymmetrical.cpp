//对称的二叉树
//https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL) return true;
        return isSymmetrical(pRoot->left,pRoot->right);
    }
    bool isSymmetrical(TreeNode* pLeft,TreeNode* pRight)
    {
        if(pLeft == NULL) return pRight == NULL;
        if(pRight == NULL) return false;
        if(pLeft->val != pRight->val) return false;
        return isSymmetrical(pLeft->left,pRight->right)&&
            isSymmetrical(pLeft->right,pRight->left);
    }
};