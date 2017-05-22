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
    ListNode* partition(ListNode* head, int x) {
        ListNode *aDummy = new ListNode(x);
        aDummy->next = head;
        ListNode *aPrev = aDummy, *aBorder = aDummy;
        while (aPrev->next != nullptr) {
            ListNode *aCurr = aPrev->next;
            if (aCurr->val >= x) { aPrev = aCurr; continue; }
            else if (aBorder->next == aCurr) { aPrev = aBorder = aCurr; continue; }
            aPrev->next = aCurr->next;
            aCurr->next = aBorder->next;
            aBorder->next = aCurr;
            aBorder = aCurr;
        }
        ListNode *aRes = aDummy->next;
        delete aDummy;
        return aRes;
    }
};
