// just the idea from other people
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *aCurrA = headA, *aCurrB = headB;
        while (aCurrA != aCurrB) {
            aCurrA = aCurrA == nullptr ? headB : aCurrA->next;
            aCurrB = aCurrB == nullptr ? headA : aCurrB->next;
        }
        return aCurrA;
    }
};
