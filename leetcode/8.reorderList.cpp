//reorder-list
//https://www.nowcoder.com/practice/3d281dc0b3704347846a110bf561ef6b
class Solution {
public:
    void reorderList(ListNode *head) {
        int len = getListLength(head);
        if(len <= 2) return;
        ListNode* listLeft = head;
        ListNode* listRight = reverseList(getKthNode(head,len/2));
        //合并链表
        ListNode* pNewHead = listLeft;
        listLeft = listLeft->next;
        while(listLeft&&listRight){
            pNewHead->next = listRight;
            listRight = listRight->next;
            pNewHead = pNewHead->next;
            pNewHead->next = listLeft;
            listLeft = listLeft->next;
            pNewHead = pNewHead->next;
        }
        if(listLeft)
            pNewHead->next = listLeft;
        if(listRight)
            pNewHead->next = listRight;
    }
    
    int getListLength(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    //得到第k个节点
    ListNode* getKthNode(ListNode* head,int k){
        ListNode* pre = head;
        for(int i = 0;i<k;i++){
            pre = head;
            head = head->next;
        }
        //k-1节点截断
        pre->next = NULL;
        return head;
    }
    
    //逆序链表
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* pNewHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pNewHead;
    }
};