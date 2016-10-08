#define MAXSIZE 4
class Solution {
private:
    int totalSize = 0;
    vector<vector<int>> *pRes = nullptr;
    vector<int> *pNums = nullptr;
private:
    void AddPermutationRecurs(bool visited[], int partial[], int currSize) {
        
        // base case - add a permutation into the response
        if (currSize == this->totalSize) {
            this->pRes->push_back(vector<int>(partial, partial + this->totalSize));
            return;
        }
        
        // enumerate all possible next items into int_partial[]
        for (int i = 0; i < this->totalSize; i++) {// visited[i]
            if (visited[i]) continue;
            // change the arrays
            visited[i] = true;
            partial[currSize++] = (*this->pNums)[i];
            
            // recursive call
            AddPermutationRecurs(visited, partial, currSize);
            
            // change the arrays back
            visited[i] = false;
            currSize--;
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // the response and the edge input case
        this->totalSize = nums.size();
        vector<vector<int>> res;
        if (this->totalSize == 0) return res;
        this->pRes = &res;
        this->pNums = &nums;

        // run the recursive call
        bool visited[MAXSIZE];
        int partial[MAXSIZE];
        memset(visited, false, MAXSIZE*sizeof(bool));
        this->AddPermutationRecurs(visited, partial, 0);
        
        // able to return
        return res;
    }
};
