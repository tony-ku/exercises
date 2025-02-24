/*

Example 3: 542. 01 Matrix

Given an m x n binary (every element is 0 or 1) matrix mat, find the distance of the nearest 0 for each cell. The distance between adjacent cells (horizontally or vertically) is 1.

For example, given mat = [[0,0,0],[0,1,0],[1,1,1]], return [[0,0,0],[0,1,0],[1,2,1]].
*/
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int m;  /* row */
    int n;  /* column */
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool is_valid(int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        if (mat[row][col])
            return true;
        else
            return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        this->mat = mat;
        queue<vector<int>> queue;
        /* Seen matrix */
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        m = (int)mat.size();
        n = (int)mat[0].size();

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (mat[row][col] == 0)
                {
                    /* put all the 0's into the queue */
                    queue.push({row, col, 1});
                    seen[row][col] = true;

                }
            }
        }

        while(!queue.empty())
        {
            vector<int> top = queue.front();
            queue.pop();
            int row = top[0], col = top[1], steps = top[2];

            for (vector<int> &direction: directions)
            {
                int next_row = row + direction[0], next_col = col + direction[1];
                if (is_valid(next_row, next_col) && !seen[next_row][next_col])
                {
                    seen[next_row][next_col] = true;
                    queue.push({next_row, next_col, steps + 1});
                    mat[next_row][next_col] = steps;
                }
            }
        }
        return mat;
    }
};