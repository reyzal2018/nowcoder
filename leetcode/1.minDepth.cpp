//minimum-depth-of-binary-tree
//https://www.nowcoder.com/practice/e08819cfdeb34985a8de9c4e6562e724
class Solution {
public:
    int run(TreeNode *root) {
        if(root == NULL) return 0;
        int left = run(root->left);
        int right = run(root->right);
        if(left == 0 || right == 0)
            return left + right + 1;
        return min(left,right)+1;
    }
};