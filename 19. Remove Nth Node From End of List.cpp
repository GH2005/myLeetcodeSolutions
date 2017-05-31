/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *aCurr = &dummy, *aPrev = &dummy;
        int c = 0;
        while (aCurr != nullptr)
        {
            if (++c > n+1) aPrev = aPrev->next;
            aCurr = aCurr->next;
        }
        // remove the node
        ListNode *aTgt = aPrev->next;
        aPrev->next = aTgt->next;
        delete aTgt;
        return dummy.next;
    }
};
