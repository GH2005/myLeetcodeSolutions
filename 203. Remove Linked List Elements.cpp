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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *aDummy = new ListNode(INT_MIN);
        aDummy->next = head;
        ListNode *aCurr = aDummy;
        while (aCurr->next != nullptr) {
            ListNode *aNext = aCurr->next;
            if (aNext->val == val) {
                aCurr->next = aNext->next;
                delete aNext;
            }
            else {
                aCurr = aCurr->next;
            }
        }
        
        ListNode *res = aDummy->next;
        delete aDummy;
        return res;
    }
};
