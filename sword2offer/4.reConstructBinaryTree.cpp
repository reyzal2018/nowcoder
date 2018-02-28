//重建二叉树
//https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6
class Solution {
public:
    int error_;
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0){
            return NULL;
        }
        error_ = 0;
        return reConstructBinaryTree(&pre[0],&pre[pre.size() - 1],&vin[0],&vin[vin.size() - 1]);
    }

    TreeNode* reConstructBinaryTree(int* pre1,int* pre2,int* vin1,int* vin2) {
        if(pre1 > pre2){
            return NULL;
        }
        if(pre2 - pre1 != vin2 - vin1){
            error_ = 1;
            return NULL;
        }
        int root_val = *pre1;
        TreeNode* root = new TreeNode(root_val);
        int* root_in_vin = vin1;
        while(root_in_vin <= vin2){
            if(*root_in_vin == root_val){
                break;
            }
            root_in_vin ++;
        }
        if(root_in_vin > vin2){
            error_ = 1;
            return NULL;
        }
        int* left_pre1 = pre1 + 1;
        int* left_pre2 = pre1 + (root_in_vin - vin1);
        int* left_vin1 = vin1;
        int* left_vin2 = root_in_vin - 1;
        int* right_pre1 = left_pre2 + 1;
        int* right_pre2 = pre2;
        int* right_vin1 = root_in_vin + 1;
        int* right_vin2 = vin2;
        root->left = reConstructBinaryTree(left_pre1,left_pre2,left_vin1,left_vin2);
        root->right = reConstructBinaryTree(right_pre1,right_pre2,right_vin1,right_vin2);
        return root;
    }
};