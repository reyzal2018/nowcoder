//链表中倒数第k个结点
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* first = pListHead;
        ListNode* second = pListHead;
        int n = 0;
        //first走k-1步，second开始走，当first走到最后时，second正好是倒数第k个节点
        while(first && n < k){
            first = first->next;
            n++;
        }
        if(n != k) return NULL;
        while(first){
            first = first->next;
            second = second->next;
        }
        return second;
    }
};