
/*
Number of Connected Components in an Undirected Graph

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:

0   --- 1                        3
        |                        |
        2                        4



Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
    

*/

class Solution {
    public:
        int dfs(unordered_map<int, vector<int>>&graph, vector<bool> &visited, int node)
        {   
            visited[node] = true;
            for (auto &curr_node : graph[node])
            {
                /* Recrusively walk through any node not yet marked as visited */
                if (visited[curr_node] == false)
                {
                    dfs(graph, visited, curr_node);
                }
            }
            return 0;
        }
    
        int countComponents(int n, vector<vector<int>>& edges) {
            int ans = 0;
            unordered_map<int, vector<int>> graph;
            vector<bool>  visited(n, false);
            
            for (auto edge : edges)
            {
                int x = edge[0], y = edge[1];
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
    
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == false)
                {
                    ans++;
                    dfs(graph, visited, i);
                }
            }
    
            return ans;
        }
    };