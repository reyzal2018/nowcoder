//反转链表
//https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pPrv = NULL;
        ListNode* pNxt = pHead;
        ListNode* pNode = NULL;
        while(pNxt){
            pNode = pNxt;
            pNxt = pNxt->next;
            pNode->next = pPrv;
            pPrv = pNode;
        }
        return pPrv;
    }
};