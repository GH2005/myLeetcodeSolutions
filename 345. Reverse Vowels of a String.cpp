class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        auto is_vowel = [](char c)->bool
        { 
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        do {
            while (0 <= right && !is_vowel(s[right])) right--;
            while (left < s.size() && !is_vowel(s[left])) left++;
        } while (left < right ? (swap(s[left++], s[right--]), true) : false);
        return s;
    }
};
