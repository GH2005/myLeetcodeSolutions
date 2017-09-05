class MyQueue {
    stack<int> stkPush, stkPop;
    bool canPush = true;
    int peekVal = 0;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!canPush)
        {
            while (!stkPop.empty())
            {
                stkPush.push(stkPop.top());
                stkPop.pop();
            }
            canPush = true;
        }
        if (stkPush.empty()) peekVal = x;
        stkPush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (canPush)
        {
            while (!stkPush.empty())
            {
                stkPop.push(stkPush.top());
                stkPush.pop();
            }
            canPush = false;
        }
        int res = stkPop.top();
        stkPop.pop();
        if (!stkPop.empty()) peekVal = stkPop.top();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return peekVal;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (canPush) return stkPush.empty();
        else return stkPop.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
