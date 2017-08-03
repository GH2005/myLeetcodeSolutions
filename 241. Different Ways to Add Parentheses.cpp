class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<char> operators;
        int left = 0;
        for (int right = 0; right < input.size(); right++)
        {
            char ch = input[right];
            if ('0' <= ch && ch <= '9') continue;
            numbers.push_back(stoi(input.substr(left, right-left)));
            operators.push_back(input[right]);
            left = right + 1;
        }
        numbers.push_back(stoi(input.substr(left, input.size() - left)));
        // add single numbers to the dp table
        vector<vector<vector<int> *>> dp(numbers.size(), vector<vector<int> *>(numbers.size()));
        for (int i = 0; i < numbers.size(); i++)
            dp[i][i] = new vector<int>{numbers[i]};
        // fill the dp table
        for (int cNumbers = 2; cNumbers <= numbers.size(); cNumbers++)
        {
            for (int start = 0; start <= numbers.size() - cNumbers; start++)
            {// this is one range that is to be added to the dp table
                int end = start + cNumbers - 1;
                vector<int> *&collection = dp[start][end];
                if (collection == nullptr) collection = new vector<int>();
                // compute this element of dp table
                for (int posOperator = start; posOperator < end; posOperator++)
                {
                    vector<int> *collection1 = dp[start][posOperator];
                    vector<int> *collection2 = dp[posOperator+1][end];
                    char op = operators[posOperator];
                    for (int m = 0; m < collection1->size(); m++)
                    for (int n = 0; n < collection2->size(); n++)
                    {
                        int num1 = (*collection1)[m], num2 = (*collection2)[n];
                        if (op == '+') collection->push_back(num1 + num2);
                        else if (op == '-') collection->push_back(num1 - num2);
                        else collection->push_back(num1 * num2);
                    }
                }
            }
        }
        // clean the dp table on the heap
        
        // respond
        return *dp[0][numbers.size()-1];
    }
};
