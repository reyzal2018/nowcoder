//复杂链表的复制
//https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNode(pHead);
        MoveRandomNode(pHead);
        return SplitList(pHead);
    }
    
    void CloneNode(RandomListNode* pHead)
    {
        while(pHead){
            RandomListNode* pNode = new RandomListNode(pHead->label);
            pNode->next = pHead->next;
            pHead->next = pNode;
            pHead = pNode->next;
        }
    }
    
    void MoveRandomNode(RandomListNode* pHead)
    {
        while(pHead){
            RandomListNode* pNode = pHead->next;
            pNode->random = pHead->random ? pHead->random->next:NULL;
            pHead = pNode->next;
        }
    }
    
    RandomListNode* SplitList(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode* pNewHead = pHead->next;
        pHead->next = pNewHead->next;
        pHead = pHead->next;
        RandomListNode* pNewNode = pNewHead;
        while(pHead){
            pNewNode->next = pHead->next;
            pNewNode = pNewNode->next;
            pHead->next = pNewNode->next;
            pHead = pHead->next;
        }
        return pNewHead;
    }
};