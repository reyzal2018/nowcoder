//insertion-sort-list
//https://www.nowcoder.com/practice/152bc6c5b14149e49bf5d8c46f53152b
class Solution {
public:
    //一直纠结应该如何记录前面的节点，后来发现，只要将链表倒置就可以了
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        //新增加一个链表头
        ListNode newHead(-1);
        newHead.next = insertionSortList(head->next);
        ListNode* pNewHead = &newHead;
        ListNode* pNewNode = pNewHead;
        //找到合适的插入点
        while(pNewNode && pNewNode->next && pNewNode->next->val < head->val){
            pNewNode = pNewNode->next;
        }
        head->next = pNewNode->next;
        pNewNode->next = head;
        return pNewHead->next;
    }
};