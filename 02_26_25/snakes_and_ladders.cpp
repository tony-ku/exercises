/*

Snakes and Ladders

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.

Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.


Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.

*/


/*
 *
 *   The board is laid out in reverse order, like this:
 *
 *   13 14 15 16 17 18
 *   12 11 10  9  8  7
 *   1  2  3   4  5  6
 *
 *   Lookup will have to reverse the column order in a loop
 *
 *  The dice roll is done from 1 to 6, so we would walk from 1 to start, then calculate the distance from
 *  start at each label.  If there is a snake or bridge, then it's a short cut, so that distance will end up
 *  with just 1.  otherwise the distance increases as it goes on.
 *
 * The board variable specifies if it jumps or not, -1 means no jump, and any other number means it can go to the
 * next cell with a +1 distance.
 *
 *  - initialize cell for lookup of rows, columns, (columns would be reversed on the end of the row, etc.)
 *
 *   do this while queue not empty:
 *  - pop the top of the queue
 *      - walk through the next 6 (die roll) or if it reaches the end of the matrix.
 *      - if the next destination through board lookup is -1, then destination is not a bridge/snake, else jump to the destination (bridge, snake)
 *         - if next dist is -1, it hasn't been visited, set the distance to +1 from current and add to he queue
 *
 *  dist[n*n] would be when the game ends, return that distance.
 *           
 */


 class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
    
            vector<pair<int, int>> cells(n * n + 1);
            vector<int> columns(n);
            /* incrementing column */
            iota(columns.begin(), columns.end(), 0);
    
            /* start with 1 on the bottom left */
            int label = 1;
    
            /* Create a cells mapping from bottom to top  */
            /* Walk from bwttom to top row */
            for (int row = n - 1; row >= 0; row--)
            {
                for (int column: columns)
                {
                    cells[label++] = {row, column};
                }
                /* need to traverse as the order of the number
                 * is reversed */
                reverse (columns.begin(), columns.end());
            }
    
            /* dist is the distance of the cell from first one */
            vector<int> dist(n*n+1, - 1);
            queue<int> queue;
            dist[1] = 0;
            queue.push(1);
            while (!queue.empty()) 
            {
                int curr = queue.front();
                queue.pop();
    
                /* Walk through the entire row */
                for (int next = curr + 1; next <= min(curr + 6, n*n); next++)
                {
                    int row = cells[next].first;
                    int column = cells[next].second;
    
                    /* if the destination row/column is -1, it means it's not a snake or a bridge, so goto next
                     * otherwise, jump to the destination 
                    */
                    int destination = 0;
                    if (board[row][column] != -1)
                        destination = board[row][column];
                    else
                        destination = next;
    
                    /* if the distance of the destination is not initialized/visited, then set it to the current
                     * distance + 1, and add it to the queue for search */
                    if (dist[destination] == -1)
                    {
                        dist[destination] = dist[curr] + 1;
                        queue.push(destination);
                    }
                }
            }
            return dist[n*n];
        }
    };