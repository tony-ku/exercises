#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
    public:
        vector<vector<int>> grid;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int n;
        
        bool valid_path(int row, int col)
        {
            /* row and column must be within limits and the grid must be 0 */
            if (row < 0 || row >= n || col >= n || col < 0)
            {
                return false;
            }
            if (grid[row][col] == 1)
                return false;
            else
                return true;
        }

        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            
            if (grid[0][0] == 1)
                return 0;
            
            this->grid = grid;
            n = (int)grid.size();
            vector<vector<bool>> seen(n, vector<bool>(n, false));
            queue<vector<int>> queue;
            seen[0][0] = true;

            /* Row, column and step */
            queue.push({0, 0, 1});
            while (!queue.empty()) {
                vector<int> curr = queue.front();
                queue.pop();
                int row = curr[0], col = curr[1], steps = curr[2];
                if (row == n - 1 && col == n - 1)
                {
                    return steps;
                }

                for (vector<int> &direction: directions)
                {
                    int next_row = row + direction[0], next_col = col + direction[1];
                    printf ("Search - next_row: %d, next_col: %d\n", next_row, next_col);
                    if (valid_path(next_row, next_col) && !seen[next_row][next_col])
                    {
                        printf ("-----> Valid - next_row: %d, next_col: %d step: %d\n", next_row, next_col, steps);
                        seen[next_row][next_col] = true;
                        queue.push({next_row, next_col, steps + 1});
                    }
                }
            }
            return -1;
        }
    };

vector<vector<int>> test_grid =
{
    { 0, 0, 1, 1, 1, 1},
    { 0, 1, 0, 1, 1, 1},
    { 0, 1, 1, 0, 1, 1},
    { 0, 0, 0, 0, 0, 1},
    { 1, 1, 1, 1, 0, 0},
    { 1, 1, 1, 1, 1, 0}
};

int main(void)
{
    Solution X;

    int ans = X.shortestPathBinaryMatrix(test_grid);
    printf ("ans: %d\n", ans);
    return 0;
}