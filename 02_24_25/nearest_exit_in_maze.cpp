
#include <queue>
#include <vector>

using namespace std;

[["+",".","+","+","+","+","+"],
 ["+",".","+",".",".",".","+"],
 ["+",".","+",".","+",".","+"],
 ["+",".",".",".","+",".","+"],
 ["+","+","+","+","+",".","+"]]
[0,1]
class Solution
{
public:
    vector<vector<char>> maze;
    int m;
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool is_valid(int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= m)
            return false;
        else
            return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int start_row = entrance[0], start_col = entrance[1];
        this->maze = maze;

        queue<vector<int>> queue;
        m = (int)maze.size();
        n = (int)maze[0].size();
        /* Seen matrix */
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        seen[start_row][start_col] = true;
        queue.push({start_row, start_col, 0});
    
        while (!queue.empty())
        {
            vector<int> top = queue.front();
            int curr_row = top[0], curr_col = top[1], curr_dist  = top[2];
            queue.pop();
            for (vector<int> &dir: directions)
            {
                int next_row = curr_row + dir[0];
                int next_col = curr_col + dir[1];

                if (is_valid(next_row, next_col) && !seen[next_row][next_col])
                {
                    /* if it's a space, add to the search, else mark it as seen */
                    if (maze[next_row][next_col] == '.')
                    {
                        if (next_row == 0 || next_row == m-1 || next_col == 0 || next_col == n - 1)
                            return curr_dist + 1;
                        queue.push({next_row, next_col, curr_dist+1});
                    }

                    seen[next_row][next_col] = true;
                }
            }
        }
        return -1;
    }

};