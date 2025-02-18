
/*
Deepest Leaves Sum
Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:
             1
          2     3
        4   5     6
       7            8


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        int deepestLeavesSum(TreeNode* root) {
            queue<TreeNode *> queue;
            vector<int> temp;
            queue.push(root);
            
            while (!queue.empty()) {
                int node_in_current_level = queue.size();
                temp.clear();
                while(node_in_current_level--)
                {
                    TreeNode *node = queue.front();
                    queue.pop();
                    temp.push_back(node->val);
                    if (node->left) {
                        queue.push(node->left);
                    }
                    if (node->right) {
                        queue.push(node->right);
                    }
                }
            }
            
            int val = 0;
            for (int c: temp)
                val += c;
            return val;
        }
    };