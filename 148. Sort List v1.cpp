/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  void prv_divideAndConquer(ListNode *const beforeHead, ptrdiff_t const nodeCount) const noexcept {
    if (nodeCount < 2) return;
    ListNode *prev = beforeHead, *curr = beforeHead->next;
    ListNode *const keyNode = curr;
    int const keyVal = curr->val;
    ptrdiff_t smallerNodesCount = 0;
    for (ptrdiff_t i = 0; i < nodeCount; ++i) {
      if (keyVal <= curr->val) {
        prev = curr;
        curr = curr->next;
      }
      else {
        ListNode *headNode = beforeHead->next;
        ListNode *nextNode = curr->next;
        beforeHead->next = curr;
        curr->next = headNode;
        prev->next = curr = nextNode;
        ++smallerNodesCount;
      }
    }
    if (nodeCount > 2) {
      prv_divideAndConquer(beforeHead, smallerNodesCount);
      prv_divideAndConquer(keyNode, nodeCount - smallerNodesCount - 1);
    }
  }
public:
    ListNode* sortList(ListNode* head) {
      if (!head) return nullptr;
      ptrdiff_t nodeCount = 0;
      for (ListNode const *node = head; node; node = node->next) {
        ++nodeCount;
      }
      ListNode extraHead{0}; extraHead.next = head;
      prv_divideAndConquer(&extraHead, nodeCount);
      return extraHead.next;
    }
};
