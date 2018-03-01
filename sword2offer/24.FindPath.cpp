//二叉树中和为某一值的路径
//https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        if(root == NULL) return result;
        vector<int> path;
        _FindPath(root,path,0,expectNumber,result);
        return result;
    }
    
    void _FindPath(TreeNode* node,vector<int> path,int currentNumber,
                   int expectNumber,vector<vector<int> >& result){
        path.push_back(node->val);
        if(node->left){
            _FindPath(node->left,path,currentNumber+node->val,expectNumber,result);
        }
        if(node->right){
            _FindPath(node->right,path,currentNumber+node->val,expectNumber,result);
        }
        if(node->left == NULL && node->right == NULL){
            if(currentNumber+node->val == expectNumber){
                result.push_back(path);
            }
        }
    }
};