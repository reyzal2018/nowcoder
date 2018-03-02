//序列化二叉树
//https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        stringstream ss;
        Serialize(root,ss);
        char* str = new char[ss.str().length()+1];
        strcpy(str,ss.str().c_str());
        return str;
    }
    
    void Serialize(TreeNode *root,stringstream& ss){
        if(root == NULL){
            ss<<"# ";
            return ;
        }
        ss<<root->val<<" ";
        Serialize(root->left,ss);
        Serialize(root->right,ss);
    }
    TreeNode* Deserialize(char *str) {
        stringstream ss;
        ss.str(str);
        return Deserialize(ss);
    }
    
    TreeNode* Deserialize(stringstream& ss){
        string val = "";
        ss>>val;
        if(val == "#") return NULL;
        TreeNode* pNode = new TreeNode(atoi(val.c_str()));
        pNode->left = Deserialize(ss);
        pNode->right = Deserialize(ss);
        return pNode;
    }
};