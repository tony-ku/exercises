/*
    Given an m x n 2D binary grid which represents a map of 1 (land) and 0 (water)
    return the number of islands. An island is surrounded by water and is formed by connecting adjacent land cells horizontally or vertically.
*/
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> island_grid =
{
    {'1', '1', '0', '0', '0', '1'},
    {'0', '1', '0', '0', '0', '0'},
    {'0', '1', '1', '0', '1', '1'},
    {'0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '0', '1'},
    {'1', '1', '1', '1', '0', '1'}
};

class Solution {
    public:
        int m;
        int n;
        vector<vector<char>> grid;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> seen;
        
        int numIslands(vector<vector<char>>& grid) {
            this->grid = grid;
            m = grid.size();
            n = grid[0].size();
            seen = vector(m, vector<bool>(n, false));
            
            int ans = 0;
            for (int row = 0; row < m; row++) {
                for (int col = 0; col < n; col++) {
                    if (grid[row][col] == '1' && !seen[row][col]) {
                        ans++;
                        seen[row][col] = true;
                        dfs(row, col);
                    }
                }
            }
            
            return ans;
        }
        
        void dfs(int row, int col) {
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    dfs(nextRow, nextCol);
                }
            }
        }
        
        bool valid(int row, int col) {
            return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == '1';
        }
    };

int main(void)
{
    Solution y;
    printf ("Num Islands: %d\n", y.numIslands(island_grid));
    return 0;
}