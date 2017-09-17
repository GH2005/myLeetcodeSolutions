class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int distTo3 = 3, distTo5 = 5;
        vector<string> res;
        for (int v = 1; v <= n; v++)
        {
            distTo3--, distTo5--;
            if (distTo3 != 0 && distTo5 != 0)
            {
                res.push_back(to_string(v));
                continue;
            }
            res.emplace_back();
            if (distTo3 == 0)
                res.back() += "Fizz", distTo3 = 3;
            if (distTo5 == 0)
                res.back() += "Buzz", distTo5 = 5;
        }
        return res;
    }
};
