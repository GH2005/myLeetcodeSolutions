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
    ListNode* sortList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode dummy{3}; dummy.next = head;
      size_t segLen = 1;
      while (true) {
        for (ListNode *last = &dummy; last->next; ) {
          ListNode *first = last->next;
          ListNode *curr = last;
          size_t actualFirstSegLen = 0;
          for (size_t i = 0; i < segLen; ++i, curr = curr->next) {
            if (!curr->next && last == &dummy) { return dummy.next; }
            else if (!curr->next) { break; }
            ++actualFirstSegLen;
          }
          ListNode *second = curr->next;
          size_t actualSecondSegLen = 0;
          for (size_t i = 0; i < segLen; ++i, curr = curr->next) {
            if (!curr->next) { break; }
            ++actualSecondSegLen;
          }
          ListNode *next = curr->next;
          ListNode *firstCurr = first, *secondCurr = second;
          size_t const combinedLen = actualFirstSegLen + actualSecondSegLen;
          for (size_t i = 0; i < combinedLen; ++i) {
            int const v1 = firstCurr != second ? firstCurr->val : INT_MAX;
            int const v2 = secondCurr != next ? secondCurr->val : INT_MAX;
            if (v1 < v2) {
              last = last->next = firstCurr;
              firstCurr = firstCurr->next;
            }
            else {
              last = last->next = secondCurr;
              secondCurr = secondCurr->next;
            }
          }
          last->next = next;
        }
        segLen *= 2;
      }
    }
};
