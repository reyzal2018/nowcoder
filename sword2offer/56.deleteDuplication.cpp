//删除链表中重复的结点
//https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* pNewHead = new ListNode(-1);
        ListNode* pNode = pHead;
        ListNode* pNewNode = pNewHead;
        while(pNode){
            ListNode* pTmpNode = pNode;
            while(pTmpNode->next && pTmpNode->next->val == pTmpNode->val){
                pTmpNode = pTmpNode->next;
            }
            if(pNode == pTmpNode){
                pNewNode->next = pTmpNode;
                pNewNode = pNewNode->next;
            }
            pNode = pTmpNode->next;
        }
        pNewNode->next = NULL;
        pNewNode = pNewHead->next;
        delete pNewHead;
        return pNewNode;
    }
};