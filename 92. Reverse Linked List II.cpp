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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) return head;
        if (m == n) return head;
        
        // find the first position
        ListNode *aDummy = new ListNode(-1);
        aDummy->next = head;
        ListNode *aBorder1 = aDummy;
        for (int pos = 0; pos < m-1; pos++) aBorder1 = aBorder1->next;
        ListNode *aPrev = aBorder1->next, *aBorder2 = aBorder1->next;
        ListNode *aCurr = aPrev->next;
        
        // reverse (m-n) links
        for (int pos = 0; pos < n-m; pos++) {
            // reverse the link
            ListNode *aNext = aCurr->next;
            aCurr->next = aPrev;
            // update
            aPrev = aCurr;
            aCurr = aNext;
        }
        
        // change values in aBorder1 and aBorder2
        aBorder1->next = aPrev;
        aBorder2->next = aCurr;
        
        ListNode *res = aDummy->next;
        delete aDummy;
        return res;
    }
};
