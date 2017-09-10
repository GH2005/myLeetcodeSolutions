class Solution {
public:
    string reverseWords(string s) {
        for (int start = 0, end = 0; start < s.size();
            start = end + 1)
        {
            end = s.find(' ', start);
            if (end == string::npos) end = s.size();
            reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
};
