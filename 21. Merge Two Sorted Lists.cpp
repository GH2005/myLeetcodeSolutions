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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *aCurrNew = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode *&aNeeded = l1->val < l2->val ? l1 : l2;
            aCurrNew = aCurrNew->next = aNeeded;
            aNeeded = aNeeded->next;
        }
        aCurrNew->next = l1 == nullptr ? l2 : l1;
        return dummy.next;
    }
};
