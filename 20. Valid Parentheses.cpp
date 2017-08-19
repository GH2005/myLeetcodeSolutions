class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        auto left_half = [](char c)->char
        {
            switch(c)
            {
                case ')': return '(';
                case ']': return '[';
                case '}': return '{';
                default: ;
            }
        };
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                stk.push(ch);
            else if (!stk.empty() && left_half(ch) == stk.top())
                stk.pop();
            else return false;
        }
        return stk.empty();
    }
};
