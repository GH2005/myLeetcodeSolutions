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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        int count = 0;
        ListNode *aCurr = head;
        while (aCurr != nullptr) { count++; aCurr = aCurr->next; }
        if (count == 1) return true;
        if (count == 2) return head->val == head->next->val;
        int midPos = 0 + (count-1) / 2;
        // reverse the first half
        ListNode *aPrev = nullptr;
        aCurr = head;
        for (int pos = 0; pos <= midPos; pos++) {
            // reverse
            ListNode *aNext = aCurr->next;
            aCurr->next = aPrev;
            // update
            aPrev = aCurr;
            aCurr = aNext;
        }
        // decide palindrome
        ListNode *aLeft = count % 2 == 0 ? aPrev : aPrev->next;
        ListNode *aRight = aCurr;
        while (aLeft != nullptr) {
            if (aLeft->val != aRight->val) return false;
            aLeft = aLeft->next;
            aRight = aRight->next;
        }
        return true;
    }
    
};
