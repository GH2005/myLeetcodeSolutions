class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        auto is_vowel = [](char c)->bool
        { 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        while (left < right)
        {
            if (!is_vowel(s[left])) { left++; continue; }
            if (!is_vowel(s[right])) { right--; continue; }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
