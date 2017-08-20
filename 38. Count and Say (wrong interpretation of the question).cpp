// wrong understanding of the problem
class Solution {
    vector<string> seq { "1", "11", "21", "1211", "111221" };
public:
    string countAndSay(int n) {
        if (n-1 < this->seq.size()) return this->seq[n-1];
        while (this->seq.size() < n)
        {
            this->seq.emplace_back();   // note that it may trigger a deep copy
            string &curr = this->seq.back();
            string &prev = *(this->seq.end() - 2);
            int pos = 0;
            while (pos < prev.size() - 1)
            {
                if (prev[pos++] == '2') curr += "12";
                else if (prev[pos++] == '1') curr += "21";
                else curr += "1112";
            }
            if (pos < prev.size()) curr += "11";
        }
        return this->seq[n-1];
    }
};
