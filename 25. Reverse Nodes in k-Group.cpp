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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // edge cases
        if (head == nullptr || head->next == nullptr) return head;
        if (k <= 1) return head;
        
        // probe k and then reverse k
        ListNode **pRefcurrStart = &head;
        while (*pRefcurrStart != nullptr) {// while there is still at least one node
            // probe
            ListNode *curr = *pRefcurrStart;
            bool hasKNodes = true;
            for (int i = 0; i < k; i++) {// node[currStart+i]
                if (curr == nullptr) { hasKNodes = false; break; }
                curr = curr->next;
            }
            // reverse
            if (hasKNodes) {
                ListNode *prev = curr;
                curr = *pRefcurrStart;
                for (int i = 0; i < k; i++) {// reversing the next field of node[currStart+i]
                    ListNode *theNext = curr->next;
                    curr->next = prev;
                    prev = curr;
                    if (i < k-1) curr = theNext;
                }
                // now curr is pointing to the last of the k nodes
                // update currStart for the next iteration
                ListNode *currStart = *pRefcurrStart;   // save the previous value
                *pRefcurrStart = curr;
                pRefcurrStart = &currStart->next; // change the reference to head of next k-group
            }
            else {// doesn't have k nodes, just break
                break;
            }
        }
        
        // return
        return head;
    }
};
