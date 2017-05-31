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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *aBase = &dummy, *a1 = aBase->next;
        while (a1 != nullptr && a1->next != nullptr)
        {
            ListNode *a2 = a1->next;
            a1->next = a2->next;
            a2->next = a1;
            aBase->next = a2;
            aBase = a1;
            a1 = aBase->next;
        }
        return dummy.next;
    }
};
