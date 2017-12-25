class Solution {
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        const size_t count = M.size();
        if (count == 1) return 1;
        
        // preconditions
        size_t circleOf[200] = {};
        bool done[200] = {};
        queue<size_t> todo;
        /*start the first connected component*/
        done[0] = true, todo.push(0); 
        size_t cCircles = 1;
        
        // run bfs for each connected component
        while (!todo.empty())
        {
            /*a node in an existing or a new connected component*/
            size_t row = todo.front(); todo.pop();
            circleOf[row] = cCircles; /*one based index*/
            for (size_t col = 0; col < count; col++)
            {
                if (col == row) continue;
                if (M[row][col] == 1 && !done[col])
                    done[col] = true, todo.push(col);
            }
            /*whether to start a new connected component*/
            if (todo.empty())
                for (size_t pos = 0; pos < count; pos++)
                    if (!done[pos])
                    {
                        done[pos] = true, todo.push(pos);
                        cCircles++;
                        break;
                    }
        }
        return cCircles; 
    }
};
