//binary-tree-postorder-traversal
//https://www.nowcoder.com/practice/32af374b322342b68460e6fd2641dd1b
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        stack<int> result;
        TreeNode* p = root;
        //把中右左的结果输入到栈中，再把栈输出即为结果
        while(p || !s.empty()){
            while(p){
                s.push(p);
                result.push(p->val);
                p = p->right;
            }
            if(!s.empty()){
                p = s.top();
                s.pop();
                p = p->left;
            }
        }
        vector<int> res;
        while(!result.empty()){
            res.push_back(result.top());
            result.pop();
        }
        return res;
    }
};