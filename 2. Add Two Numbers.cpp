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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* pRes = new ListNode(0);
        ListNode* pNow = pRes;
        int pp = false;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
            }
            if (l2 != NULL) {
                sum += l2->val;
            }
            sum += pp;
            
            pNow->val = sum % 10;
            pp = sum / 10;
            
            // update.
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
            
            if ((l1 != NULL) || (l2 != NULL) || pp) {
                pNow->next = new ListNode(pp);
                pNow = pNow->next;
            }
        
        }
        return pRes;
        
    }
};
