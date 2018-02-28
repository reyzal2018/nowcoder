//二叉树的镜像
//https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};