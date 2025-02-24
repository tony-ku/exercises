/*

Reachable Nodes With Restrictions

Solution
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

 

Example 1:

                0
            /   |  \
           1    4   5
          / \       |
         2   3      6

Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

*/


class Solution {
    public:
        /* This means first node would be ans++, so cannot have first node to be 
         * restricted.
         * Then simply walk through all the non-seen nodes
         */
        void dfs(int current_node, int &ans, vector<vector<int>>&map, vector<bool> &seen)
        {
            ans++;
            seen[current_node] = true;
            for (auto node: map[current_node])
            {
                if (!seen[node])
                    dfs(node, ans, map, seen);
            }
    
        }
        int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
            vector<vector<int>> map(n);
            int ans = 0;
    
            for (auto edge: edges)
            {
                int a = edge[0];
                int b = edge[1];
                map[a].push_back(b);
                map[b].push_back(a);
            }
    
            /* Similar to other DFS walks, mark it as seen for restricted so we don't connect them */
            vector<bool> seen(n, false);
            for (auto node: restricted)
                seen[node] = true;
    
            dfs(0, ans, map, seen);
            return ans;
        }
    };