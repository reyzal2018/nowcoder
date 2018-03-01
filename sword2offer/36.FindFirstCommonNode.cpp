//两个链表的第一个公共结点
//https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46
class Solution {
public:
    int GetListLength(ListNode* pNode){
        int length = 0;
        while(pNode){
            length++;
            pNode = pNode->next;
        }
        return length;
    }
    ListNode* GetKthNode(ListNode* pNode,int k){
        for(int i = 0;i<k;i++){
            pNode =  pNode->next;
        }
        return pNode;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = GetListLength(pHead1);
        int len2 = GetListLength(pHead2);
        if(len1 > len2){
            pHead1 = GetKthNode(pHead1,len1-len2);
        }else if(len1 < len2){
            pHead2 = GetKthNode(pHead2,len2-len1);
        }
        ListNode* pNode = NULL;
        while(pHead1 && pHead2){
            if(pHead1 == pHead2){
                pNode = pHead1;
                break;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pNode;
    }
};