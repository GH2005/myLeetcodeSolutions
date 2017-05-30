/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        int len = 0;
        ListNode *aCurr = head;
        while (aCurr != nullptr) { len++; aCurr = aCurr->next; }
        return this->build_node(head, len);
    }
    TreeNode *build_node(ListNode *head, int len)
    {
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(head->val);
        ListNode *aMid = head;
        int posMid = 0 + (len-1) / 2;
        for (int pos = 0; pos < posMid; pos++) aMid = aMid->next;
        TreeNode *aRoot = new TreeNode(aMid->val);
        aRoot->left = this->build_node(head, posMid - 0);
        aRoot->right = this->build_node(aMid->next, len - 1 - posMid);
        return aRoot;
    }
};
