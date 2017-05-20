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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        if (headA == nullptr || headB == nullptr) return nullptr;
        int lenA = 0, lenB = 0;
        ListNode *aCurrA = headA, *aCurrB = headB;
        while (aCurrA != nullptr) { aCurrA = aCurrA->next; lenA++; }
        while (aCurrB != nullptr) { aCurrB = aCurrB->next; lenB++; }
        aCurrA = headA, aCurrB = headB;
        int lenDiff = abs(lenA - lenB);
        if (lenA < lenB) for (int pos = 0; pos < lenDiff; pos++) aCurrB = aCurrB->next;
        else for (int pos = 0; pos < lenDiff; pos++) aCurrA = aCurrA->next;
        while (aCurrA != nullptr) {
            if (aCurrA == aCurrB) return aCurrA;
            aCurrA = aCurrA->next, aCurrB = aCurrB->next;
        }
        return nullptr;
    }
};
