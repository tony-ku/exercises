/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

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
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        
        /* if left side is null, then walk the right */
        if (root->left == nullptr)
        {
            return 1 + dfs(root->right);
        }
        else if (root->right == nullptr)
        {
            /* if right side is null, then walk the left */
            return 1 + dfs(root->left);
        }
        
        /* Neither, walk both, find the minimum */
        return 1 + min(dfs(root->left), dfs(root->right));
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};