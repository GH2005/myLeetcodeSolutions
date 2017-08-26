class MinStack {
    struct ListNode
    {
        int val;
        ListNode *aLower;
        ListNode *aPrevMin;
        ListNode(int v, ListNode *al, ListNode* ap)
            : val(v), aLower(al), aPrevMin(ap) {}
    };
    ListNode *aBase;
    ListNode *aTop;
    ListNode *aMin;
    int count;
public:
    /** initialize your data structure here. */
    MinStack() : aBase(new ListNode(INT_MAX, nullptr, nullptr)), count(0)
    {
        aTop = aBase;
        aMin = aBase;
    }
    
    ~MinStack()
    {
        // clean the variables in the runtime heap
    }
    
    void push(int x) {
        ListNode *node = new ListNode(x, aTop, nullptr);
        if (x < aMin->val)
            node->aPrevMin = aMin, aMin = node;
        aTop = node;
        count ++;
    }
    
    void pop() {
        if (count == 0) return;
        if (aTop == aMin) aMin = aMin->aPrevMin;
        count --;
        ListNode *tmp = aTop;
        aTop = aTop->aLower;
        delete tmp;
    }
    
    int top() {
        return aTop->val;
    }
    
    int getMin() {
        return aMin->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
