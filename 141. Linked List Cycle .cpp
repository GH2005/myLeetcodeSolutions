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
    bool hasCycle(ListNode *head) {
        ListNode *aFast = head, *aSlow = head;
        while (aFast != nullptr)
        {
            aFast = aFast->next;
            if (aFast == nullptr) return false;
            aFast = aFast->next;
            aSlow = aSlow->next;
            if (aFast == aSlow) return true;
        }
        return false;
    }
};
