class Solution {
private:
    struct QueueItem {
        int value;
        int y;
        int x;
        QueueItem(int vv, int yy, int xx) :value(vv), y(yy), x(xx) {}
        bool operator < (const QueueItem& another) const {
            return this->value > another.value;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // edge cases
        int sideLen = matrix.size();
        assert(sideLen > 0);
        if (k == 1) return matrix[0][0];
        
        // visit k elements; for each one, push its right and below neighbors into the heap
        priority_queue<QueueItem> nextElements;
        nextElements.push(QueueItem(matrix[0][1], 0, 1));
        nextElements.push(QueueItem(matrix[1][0], 1, 0));
        int res = 0;
        for (int i = 2; i <= k; i++) {// the ith smallest element
            // pop out the smallest element in the heap
            QueueItem thisItem = nextElements.top();
            res = thisItem.value;
            nextElements.pop();
            // push the two neighbors into the set
            if (thisItem.y < sideLen - 1)
                nextElements.push(QueueItem(matrix[thisItem.y+1][thisItem.x], thisItem.y+1, thisItem.x));
            if (thisItem.y == 0 && thisItem.x < sideLen - 1)
                nextElements.push(QueueItem(matrix[thisItem.y][thisItem.x+1], thisItem.y, thisItem.x+1));
        }
        
        // return the value of the last visited element
        return res;
    }
};
