//链表中环的入口结点
//https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        do{
            if(fast == NULL || fast->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        slow = pHead;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};