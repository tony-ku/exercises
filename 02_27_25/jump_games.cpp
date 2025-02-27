/*

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 
Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length
*/

/* BFS approach, do both upper and lower jumps at the same time if possible.  If it's walked through already, don't run it again */
class Solution {
    public:
        bool canReach(vector<int>& arr, int start) {
            int n = (int)arr.size();
            queue<int> queue;
            queue.push (start);
            vector<bool> seen(n, false);
    
            while (!queue.empty())
            {
                int next_node_upper, next_node_lower;
                int node = queue.front();
                queue.pop();
                if (arr[node] == 0)
                    return true;
                if (!seen[node])
                {
                    next_node_upper = node + arr[node];
                    if (next_node_upper < n)
                    {
                        queue.push(next_node_upper);
                    }
                    next_node_lower = node - arr[node];
                    if (next_node_lower >= 0)
                    {
                        queue.push(next_node_lower);
                    }
                    /* mark as processed */
                    seen[node] = true;
                }
            }
            return false;
        }
    };