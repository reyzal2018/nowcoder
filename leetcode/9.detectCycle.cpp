//linked-list-cycle-ii
//https://www.nowcoder.com/practice/6e630519bf86480296d0f1c868d425ad
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && slow){
            fast = fast->next;
            if(fast == NULL) break;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        //无环
        if(fast== NULL) return NULL;
        //有环 慢节点从头开始，再次相遇即为有环点
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};