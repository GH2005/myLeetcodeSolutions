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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    using ElementType = std::pair<int, ptrdiff_t>;
    auto cmp = [](ElementType const &e1, ElementType const &e2)->bool {
      return e1.first > e2.first;
    };
    std::priority_queue<ElementType, std::vector<ElementType>, decltype(cmp)> pq{cmp};
    
    for (ptrdiff_t i = 0; i < lists.size(); ++i) {
      if (lists[i]) { pq.emplace(lists[i]->val, i); }
    }
    
    ListNode dummy(0);
    ListNode *last = &dummy;
    while (!pq.empty()) {
      ElementType const &e = pq.top();
      ptrdiff_t const i = e.second;
      pq.pop();
      last = last->next = lists[i];
      lists[i] = lists[i]->next;
      if (lists[i]) { pq.emplace(lists[i]->val, i); }
    }
    
    last->next = nullptr;
    return dummy.next;
  }
};
