//copy-list-with-random-pointer
//https://www.nowcoder.com/practice/60e43001345241ba9266cb4ee6fc6350
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        CloneNode(head);
        CloneRandomNode(head);
        return SplitList(head);
    }
    
    void CloneNode(RandomListNode* head){
        while(head){
            RandomListNode* newNode = new RandomListNode(head->label);
            newNode->next = head->next;
            head->next = newNode;
            head = newNode->next;
        }
    }
    
    void CloneRandomNode(RandomListNode* head){
        while(head){
            RandomListNode* nextNode = head->next;
            nextNode->random = head->random?head->random->next:NULL;
            head = nextNode->next;
        }
    }
    RandomListNode* SplitList(RandomListNode* head){
        if(head == NULL) return NULL;
        RandomListNode* newHead = head->next;
        head->next = newHead->next;
        head = head->next;
        RandomListNode* newNode = newHead;
        while(head){
            newNode->next = head->next;
            newNode = newNode->next;
            head->next = newNode->next;
            head = head->next;
        }
        return newHead;
    }
};