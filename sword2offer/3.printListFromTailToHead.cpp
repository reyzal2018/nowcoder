//从尾到头打印链表
//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if(head == NULL) return result;
        _printListFromTailToHead(head,result);
        return result;
    }

    void _printListFromTailToHead(ListNode* node,vector<int>& result){
        if(node->next){
            _printListFromTailToHead(node->next,result);
        }
        result.push_back(node->val);
    }
};
