class Solution {
    // custom types needed
    struct State {// values: 0 --- unknown; 1 --- unreachable; 2 --- reachable
        int toPacific;
        int toAtlantic;
        State(int a, int b) :toPacific(a), toAtlantic(b) {}
        State() :toPacific(0), toAtlantic(0) {}
    };
    
    // in-class global variables shared by recursive calls
    bool (*pVisited)[150];
    State (*pStates)[150];
    int M;
    int N;
    vector<vector<int>> *pMtx;
    
    // for easier movement: up, right, down, left
    int moveY[4] = { -1, 0, 1, 0 };
    int moveX[4] = { 0, 1, 0, -1 };
    
    // the dp function, in which "true" answers can be safely assigned to
    // states, but "false" answers can not
    int dp(int y, int x, bool forPacific/*false --- for Atlantic*/) {
        // returns whether the ocean is reachable using this searching path
        // the return value is consistent to that of *State* (1 and 2 only)
        
        // first, refer to *states*
        Solution::State& theState = this->pStates[y][x];
        if (forPacific) {
            if (theState.toPacific != 0) return theState.toPacific;
        }
        else {
            if (theState.toAtlantic != 0) return theState.toAtlantic;
        }
        
        // *states* does not give an answer, continuing seaching
        // the next step is restricted by three factors: the matrix borders,
        // height of the next cell, and whether the next cell is visited
        for (int i = 0; i < 4; i++) { // direction i
            int newY = y + moveY[i];
            int newX = x + moveX[i];
            if (newY >= 0 && newY < this->M && newX >= 0 && newX < this->N
                && (*this->pMtx)[newY][newX] <= (*this->pMtx)[y][x]
                && !this->pVisited[newY][newX]) {
                    
                this->pVisited[newY][newX] = true;
                int result = dp(newY, newX, forPacific);
                this->pVisited[newY][newX] = false;
                if (result == 2) {
                    if (forPacific) this->pStates[y][x].toPacific = 2;
                    else this->pStates[y][x].toAtlantic = 2;
                    return 2;
                }
            }
        }
        // this function did not return during the above for loop, which
        // means the ocean is unreachable using this searching path
        return 1;
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // initialization of the response object
        vector<pair<int, int>> res;
        
        // edge input cases
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        if (m == 1) {
            for (int x = 0; x < n; x++) res.push_back(pair<int, int>(0, x));
            return res;
        }
        if (n == 1) {
            for (int y = 0; y < m; y++) res.push_back(pair<int, int>(y, 0));
            return res;
        }
        
        // dp preparations, including global variables accessible by all recursive calls
        this->M = m;
        this->N = n;
        this->pMtx = &matrix;
        bool visited[150][150];
        this->pVisited = visited;
        memset(this->pVisited, 0, 150*150*sizeof(bool));
        // states of cells
        Solution::State states[150][150];
        this->pStates = states;
        // the following values are simple base cases
        for (int y = 0; y < m; y ++) {
            this->pStates[y][0].toPacific = 2;
            this->pStates[y][n-1].toAtlantic = 2;
        }
        for (int x = 0; x < n; x ++) {
            this->pStates[0][x].toPacific = 2;
            this->pStates[m-1][x].toAtlantic = 2;
        }
        
        // run dp(...) for every cell
        for (int y = 0; y < this->M; y++) {
            for (int x = 0; x < this->N; x++) {// cell matrix[y][x]
                // see if the *State* of this cell is already informative;
                // if not, run *dp(...)* to get the answer
                // unlike inside *dp(...)*, *unreachable" decisions can be made
                // here and only here
                // Pacific reachability
                Solution::State& theState = this->pStates[y][x];
                if (theState.toPacific != 2) {
                    this->pVisited[y][x] = true;
                    theState.toPacific = this->dp(y, x, true);
                    this->pVisited[y][x] = false;
                }
                // Atlantic reachability
                if (theState.toAtlantic != 2) {
                    this->pVisited[y][x] = true;
                    theState.toAtlantic = this->dp(y, x, false);
                    this->pVisited[y][x] = false;
                }
                // if Both are reachable, add the coordinate to *res*
                if (theState.toPacific == 2 && theState.toAtlantic == 2)
                    res.push_back(pair<int, int>(y, x));
            }
        }
        
        // the resposne object is already filled
        return res;
    }
};
