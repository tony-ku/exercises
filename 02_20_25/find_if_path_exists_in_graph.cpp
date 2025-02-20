/* Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:

     0 -- 1
      \  /
        2

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:

      1            3
     /             | \
    0              |   5
     \             | /
       2            4

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.

*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool dfs_search(unordered_map<int, vector<int>>& graph, vector<bool> &seen, int current_node, int dest)
        {
            if (current_node == dest)
                return true;
            
            if (!seen[current_node])
            {
                seen[current_node] = true;
                /* For the curent node, search the lookupmap graph for all the nodes connected to it.
                 * initially curr node is 0, then dest is 2,
                 *  seen[0] = true;
                 *  next node is now 1, then 2.
                 *  since all of it exists, return true
                 */
                for (auto next_node : graph[current_node])
                {
                     printf ("current node: %d, next_node: %d, dest: %d\n", current_node, next_node, dest);
                    if (dfs_search(graph, seen, next_node, dest))
                        return true;
                }
            }
            return false;
        }
        
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            unordered_map<int, vector<int>> graph;
            vector<bool> seen(n);
    
            /* Add the edges to lookup map
             *
             *  key is the node and contains list of other nodes connected to that node.
             */
            for (auto edge : edges)
            {
                int x = edge[0], y = edge[1];
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            
            return dfs_search(graph, seen, source, destination);
        }
    };


int main(void)
{
    Solution X;

    vector<vector<int>> edges_1 = {{0, 1}, {1, 2}, {2,0}};
    if (X.validPath(3, edges_1, 0, 2))
        printf ("Example 1: True\n");
    else
        printf ("Example 1: faklse\n");

    vector<vector<int>> edges_2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4,3}};
    if (X.validPath(6, edges_2, 0, 5))
        printf ("Example 2: True\n");
    else
        printf ("Example 2: False\n");
    return 0;
}