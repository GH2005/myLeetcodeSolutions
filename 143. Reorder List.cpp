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
    void reorderList(ListNode* head) {
        // edge case
        if (head == nullptr) return;
        
        // save addresses of nodes in a vector
        vector<ListNode*> v;
        ListNode *curr = head;
        while (curr != nullptr) {
            v.push_back(curr);
            curr = curr->next;
        }
        
        // rearrange pointers
        int left = 0, right = v.size(); // the right border is exclusive
        bool processLeft = true;
        while (right - left > 1) {
            if (processLeft) {
                v[left]->next = v[right-1];
                left ++;
                processLeft = false;
            }
            else {// change the "next" field of *v[right-1]
                v[right-1]->next = v[left];
                right --;
                processLeft = true;
            }
        }
        assert(right - left == 1);
        v[left]->next = nullptr;
    }
};
