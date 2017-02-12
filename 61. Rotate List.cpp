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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int len = 1;
        ListNode *curr = head;
        while (curr->next != nullptr) {
            len ++;
            curr = curr->next;
        }
        ListNode *tail = curr;
        k %= len;
        tail->next = head;
        curr = head;
        for (int i = 0; i < len - k - 1; i++) curr = curr->next;
        ListNode *newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }
};
