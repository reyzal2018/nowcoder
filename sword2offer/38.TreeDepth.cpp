//二叉树的深度
//https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};