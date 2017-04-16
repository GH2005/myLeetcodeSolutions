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
    ListNode* reverseList(ListNode* head, ListNode *aPrev = nullptr) {
        if (head == nullptr) return head;
        ListNode *aNext = head->next;
        head->next = aPrev;
        if (aNext == nullptr) return head;
        else return this->reverseList(aNext, head);
    }
};
