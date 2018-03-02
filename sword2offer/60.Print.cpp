//把二叉树打印成多行
//https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            queue<TreeNode*> q;
            vector<vector<int>> result;
            if(pRoot == NULL) return result;
            q.push(pRoot);
            TreeNode* last,*nlast = pRoot;
            vector<int> line;
            while(!q.empty()){
                TreeNode* pNode = q.front();
                q.pop();
                line.push_back(pNode->val);
                if(pNode->left)
                    q.push(pNode->left);
                if(pNode->right)
                    q.push(pNode->right);
                if(!q.empty()) last = q.back();
                if(pNode == nlast){
                    result.push_back(line);
                    line.resize(0);
                    nlast = last;
                }
            }
            return result;
        }
    
};