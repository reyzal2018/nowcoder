//二叉搜索树与双向链表
//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode = NULL;
        ConvertNode(pRootOfTree,&pLastNode);
        if(pLastNode) pLastNode->right = NULL;
        //返回头结点
        pRootOfTree = pLastNode;
        while(pRootOfTree && pRootOfTree->left)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
    
    void ConvertNode(TreeNode* pNode,TreeNode** pLastNode){
        if(pNode == NULL) return;
        //中序遍历
        if(pNode->left){
            ConvertNode(pNode->left,pLastNode);
        }
        pNode->left = *pLastNode;
        if(*pLastNode)
            (*pLastNode)->right = pNode;
        *pLastNode = pNode;
        if(pNode->right)
            ConvertNode(pNode->right,pLastNode);
    }
};