class Solution {
    
    struct Node {
        int val = 0;
        Node *next = nullptr;
        Node(int v, Node *n) :val(v), next(n) {}
    };
public:
    string getPermutation(int n, int k) {
        
        int fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        if (k < 1 || fact < k) return "";
        if (fact == 1) return "1";
        
        // construct the linked list
        
        Node *start = new Node(0, nullptr); // dummy head
        Node *curr = start;
        for (int vNode = 1; vNode <= n; vNode ++) {
            curr->next = new Node(vNode, nullptr);
            curr = curr->next;
        }

        // decide the digits in the permutation one by one
        Node *aBase = start;
        k--;    // becomes zero-based
        for (int divisor = n; divisor >= 2; divisor--) {
            fact /= divisor;
            int q = k / fact;
            k = k % fact;
            // find the node with index q-1
            if (q == 0) {
                aBase = aBase->next;
                continue;
            }
            Node *aBefore = aBase;
            for (int i = 0; i < q; i++) aBefore = aBefore->next;
            // save the addresses of affected nodes
            Node *aTarg = aBefore->next;
            Node *aAfter = aTarg->next;
            Node *aAfterBase = aBase->next;
            // change links
            aBase->next = aTarg;
            aTarg->next = aAfterBase;
            aBefore->next = aAfter;
            // for the next iteration
            aBase = aTarg;
        }

        // construct the response
        Node *aCurr = start;
        string res;
        for (int iDigit = 0; iDigit < n; iDigit++) {
            aCurr = aCurr->next;
            res += aCurr->val + '0';
        }
        // destroy the linked list
        aCurr = start;
        if (aCurr != nullptr) {
            Node *aNext = aCurr->next;
            delete aCurr;
            aCurr = aNext;
        }
        return res;
    }
};
