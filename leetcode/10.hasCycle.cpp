//linked-list-cycle
//https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&slow){
            fast = fast->next;
            if(fast == NULL) break;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        return fast?true:false;
    }
};