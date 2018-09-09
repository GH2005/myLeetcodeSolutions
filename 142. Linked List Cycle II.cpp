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
    ListNode *detectCycle(ListNode *head) {
      
      ListNode const *slow = head;
      if (!slow) return nullptr;
      slow = slow->next;
      if (!slow) return nullptr;
      ListNode const *fast = slow->next;
      if (!fast) return nullptr;
      
      while (slow != fast) {
        slow = slow->next;
        if (not (fast = fast->next)) return nullptr;
        if (not (fast = fast->next)) return nullptr;
      }
      
      ListNode const *left = head, *right = slow;
      while (left != right) {
        left = left->next;
        right = right->next;
      }
      
      return const_cast<ListNode *>(left);
      
    }
};
