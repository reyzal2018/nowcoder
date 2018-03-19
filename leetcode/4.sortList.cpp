//sort-list
//https://www.nowcoder.com/practice/d75c232a0405427098a8d1627930bea6
class Solution {
public:
    //使用归并排序
    ListNode *sortList(ListNode *head) {
        ListNode* pNewHead = new ListNode(-1);
        pNewHead->next = head;
        sortList(pNewHead, getListLength(head));
        head = pNewHead->next;
        delete pNewHead;
        return head;
    }

    void sortList(ListNode* pNewHead, int len) {
        if (len > 1) {
            //排序左边一半
            sortList(pNewHead, len / 2);
            //右边待排序链表头
            ListNode* pRightHead = getNode(pNewHead->next, len / 2 - 1);
            //排序右边
            sortList(pRightHead, len - len / 2);
            //合并链表
            pNewHead->next = mergeList(pNewHead->next, len / 2, pRightHead->next, len - len / 2);
        }
    }

    ListNode* getNode(ListNode* pNode, int len) {
        for (int i = 0; i<len; i++) {
            pNode = pNode->next;
        }
        return pNode;
    }

    int getListLength(ListNode* pNode)
    {
        int len = 0;
        while (pNode) {
            len++;
            pNode = pNode->next;
        }
        return len;
    }

    //pNode1开始的len1+len2长度链表排序
    ListNode* mergeList(ListNode* pNode1, int len1, ListNode* pNode2, int len2)
    {
        ListNode* pNewHead = new ListNode(-1);
        ListNode* pNewNode = pNewHead;
        int i1 = 0;
        int i2 = 0;
        while (i1 < len1 && i2 <len2) {
            if (pNode1->val < pNode2->val) {
                pNewNode->next = pNode1;
                pNode1 = pNode1->next;
                i1++;
            }
            else {
                pNewNode->next = pNode2;
                pNode2 = pNode2->next;
                i2++;
            }
            pNewNode = pNewNode->next;
        }
        //新链表需要将其连到pNode2
        while (i1 < len1) {
            pNewNode->next = pNode1;
            pNode1 = pNode1->next;
            pNewNode = pNewNode->next;
            i1++;
        }
        pNewNode->next = pNode2;
        pNewNode = pNewHead->next;
        delete pNewHead;
        return pNewNode;
    }
};