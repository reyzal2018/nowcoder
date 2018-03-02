//按之字形顺序打印二叉树
//https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == NULL) return result;
        stack<TreeNode*> s1,s2;
        s1.push(pRoot);
        TreeNode* last = pRoot;
        while(!s1.empty() || !s2.empty()){
            vector<int> line;
            while(!s1.empty()){
                TreeNode* pNode = s1.top();
                s1.pop();
                line.push_back(pNode->val);
                if(pNode->left)
                    s2.push(pNode->left);
                if(pNode->right)
                    s2.push(pNode->right);
            }
            if(line.size() > 0) result.push_back(line);
            line.resize(0);
            while(!s2.empty()){
                TreeNode* pNode = s2.top();
                s2.pop();
                line.push_back(pNode->val);
                if(pNode->right)
                    s1.push(pNode->right);
                if(pNode->left)
                    s1.push(pNode->left);
            }
            if(line.size() > 0) result.push_back(line);
        }
        return result;
    }
    
};