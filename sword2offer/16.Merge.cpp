//合并两个排序的链表
//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pHead = new ListNode(-1);
        ListNode* pNode = pHead;
        while(pHead1 && pHead2){
            if(pHead1->val > pHead2->val){
                pNode->next = pHead2;
                pHead2 = pHead2->next;
            }else{
                pNode->next = pHead1;
                pHead1 = pHead1->next;
            }
            pNode = pNode->next;
        }
        if(pHead1)
            pNode->next = pHead1;
        if(pHead2)
            pNode->next = pHead2;
        pNode = pHead->next;
        delete pHead;
        return pNode;
    }
};