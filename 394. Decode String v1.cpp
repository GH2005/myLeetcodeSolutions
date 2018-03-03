// ugly first implementation; will refine it next week
class Solution {
public:
    string decodeString(string s) {
        const size_t length = s.size();
        if (length == 0) return "";
        std::stack<std::pair<uint32_t, std::string>> callStack;
        callStack.emplace();
        auto isDigit = [](const char &ch)->bool{return '0' <= ch && ch <= '9';};
        for (size_t i = 0, prevChar = ']'; i < length; ++i) {
            if (isDigit(s[i]) && !isDigit(prevChar)) callStack.emplace();
            prevChar = s[i];
            std::pair<uint32_t, std::string> &topElement = callStack.top();
            if (isDigit(s[i])) {
                (topElement.first *= 10) += s[i] - '0';
            }
            else if (s[i] == '[') {}
            else if (s[i] == ']') {
                auto prevTop = std::move(topElement);
                printf("prevTop=%d, %s\n", prevTop.first, prevTop.second.c_str());
                callStack.pop();
                auto &topElement = callStack.top();
                printf("topElement(prev)=%d, %s\n", topElement.first, topElement.second.c_str());
                for (uint32_t count = 0; count < prevTop.first; ++count) {
                    topElement.second += prevTop.second;
                }
                printf("topElement(after)=%d, %s\n", topElement.first, topElement.second.c_str());
            }
            else {
                topElement.second += s[i];
                printf("topElement(added)=%d, %s\n", topElement.first, topElement.second.c_str());
            }
        }
        return callStack.top().second;
    }
};
