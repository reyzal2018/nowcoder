//binary-tree-preorder-traversal
//https://www.nowcoder.com/practice/501fb3ca49bb4474bf5fa87274e884b4
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode* p = root;
        stack<TreeNode*> s;
        vector<int> result;
        while(p || !s.empty()){
            while(p){
                result.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty()){
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return result;
    }
};