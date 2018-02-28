//树的子结构
//https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        bool ret = false;
        if(pRoot1->val == pRoot2->val)
            ret = Tree1HasTree2(pRoot1,pRoot2);
        if(!ret && pRoot1->left)
            ret = HasSubtree(pRoot1->left,pRoot2);
        if(!ret && pRoot1->right)
            ret = HasSubtree(pRoot1->right,pRoot2);
        return ret;
    }
    
    bool Tree1HasTree2(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        if(pRoot1->val != pRoot2->val){
            return false;
        }
        return Tree1HasTree2(pRoot1->left,pRoot2->left) && 
            Tree1HasTree2(pRoot1->right,pRoot2->right);
    }
};