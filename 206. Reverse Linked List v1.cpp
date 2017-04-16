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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *aPrev = nullptr, *aCurr = head;
        bool headVisited = false;
        while (aCurr != nullptr) {
            // reverse links
            ListNode *aNext = aCurr->next;
            aCurr->next = aPrev;
            // update
            if (aCurr == head) {
                if (headVisited) break;
                else headVisited = true;
            }
            aPrev = aCurr, aCurr = aNext;
        }
        return aPrev;
    }
};
