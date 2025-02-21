/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

*/


class Solution {
    public:
        int area(vector<vector<int>>& grid, vector<vector<bool>> &seen, int x, int y)
        {
            if ((x < 0) || (x >= grid.size()) || (y < 0) || (y >= grid[0].size()) || grid[x][y] == 0 || seen[x][y])
                return 0;
            
            seen[x][y] = true;
            /* This should keep growing until it runs out of island space */
            return 1 + area(grid, seen, x+1, y) + area(grid, seen, x-1, y)
                     + area(grid, seen, x, y-1) + area(grid, seen, x, y+1);
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
            int ans = 0;
    
            for (int x = 0; x < grid.size(); x++)
            {
                for (int y = 0; y < grid[0].size(); y++)
                {
                    ans = max(ans, area(grid, seen, x,y));
                }
            }
            return ans;
        }