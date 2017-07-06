// idea from satyakam
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        for (RandomListNode *aL1Curr = head; aL1Curr != nullptr; aL1Curr = aL1Curr->next)
        {
            RandomListNode *aL2Node = new RandomListNode(aL1Curr->label);
            aL2Node->next = aL1Curr->random;
            aL1Curr->random = aL2Node;
        }
        RandomListNode *aL2Head = head->random;
        // set random pointers in l2
        for (RandomListNode *aL1Curr = head; aL1Curr != nullptr; aL1Curr = aL1Curr->next)
        {
            RandomListNode *aL2Curr = aL1Curr->random;
            aL2Curr->random = aL2Curr->next == nullptr ? nullptr : aL2Curr->next->random;
        }
        // restore random pointers in l1 and member variables next in l2
        for (RandomListNode *aL1Curr = head; aL1Curr != nullptr; aL1Curr = aL1Curr->next)
        {
            RandomListNode *aL2Curr = aL1Curr->random;
            aL1Curr->random = aL2Curr->next;
            aL2Curr->next = aL1Curr->next == nullptr ? nullptr : aL1Curr->next->random;
        }
        return aL2Head;
    }
};
