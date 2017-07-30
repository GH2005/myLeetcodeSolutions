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
        int len1 = 0, len2 = 0;
        ListNode *curr = l1;
        while (curr != nullptr) len1++, curr = curr->next;
        curr = l2;
        while (curr != nullptr) len2++, curr = curr->next;
        ListNode *longer, *shorter;
        int longerLen, shorterLen;
        if (len1 < len2)
            longer = l2, longerLen = len2, shorter = l1, shorterLen = len1;
        else
            longer = l1, longerLen = len1, shorter = l2, shorterLen = len2;
        vector<int> digits(longerLen+1);
        // find the digits
        int jointPos = longerLen - shorterLen + 1;
        ListNode *currLonger = longer, *currShorter = shorter;
        for (int pos = 1; pos <= longerLen; pos++)
        {
            digits[pos] = currLonger->val;
            currLonger = currLonger->next;
            if (pos < jointPos) continue;
            digits[pos] += currShorter->val;
            currShorter = currShorter->next;
        }
        for (int pos = longerLen; 0 < pos; pos--)
            if (digits[pos] >= 10) digits[pos-1]++, digits[pos] %= 10;
        // construct res based on digits
        ListNode *res;
        int start;
        if (digits[0] == 1)
            res = new ListNode(1), start = 1;
        else
            res = new ListNode(digits[1]), start = 2;
        curr = res;
        for (int pos = start; pos <= longerLen; pos++)
        {
            curr->next = new ListNode(digits[pos]);
            curr = curr->next;
        }
        return res;
    }
};
