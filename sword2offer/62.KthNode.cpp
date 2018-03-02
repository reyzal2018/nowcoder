//二叉搜索树的第k个结点
//https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int depth = 0;
        return KthNode(pRoot,depth,k);
    }

    TreeNode* KthNode(TreeNode* pRoot,int& depth, int k)
    {
        if(pRoot == NULL) return NULL;
        TreeNode* ret = NULL;
        if(pRoot->left)
            ret = KthNode(pRoot->left,depth,k);
        if(ret) return ret;
        if(++depth == k) return pRoot;
        if(pRoot->right)
            ret = KthNode(pRoot->right,depth,k);
        return ret;
    }
};