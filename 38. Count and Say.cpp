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
            string &prev = this->seq[this->seq.size() - 2];
            int count = 1;
            for (int pos = 1; pos < prev.size(); pos++)
            {
                if (prev[pos-1] == prev[pos])
                    count++;
                else
                {
                    curr += to_string(count);
                    curr += prev[pos-1];
                    count = 1;
                }
            }
            curr += to_string(count);
            curr += '1';
        }
        return this->seq[n-1];
    }
};
