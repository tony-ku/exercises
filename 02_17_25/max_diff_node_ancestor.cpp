
/*
Maximum Difference Between Node and Ancestor

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


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

/* On a node path, basically max and min of that path would have the same ancestor */
class Solution {
    public:
        int search(TreeNode *root, int curr_min, int curr_max)
        {
            int left = 0;
            int right = 0;
            
            /* If we're at the end (i.e. at a leaf), return the difference */
            if (root == nullptr)
                return curr_max-curr_min;
            
            curr_min = min(curr_min, root->val);
            curr_max = max(curr_max, root->val);
    
            /* Walk the left */
            left = search(root->left, curr_min, curr_max);
            /* Walk the right */
            right = search(root->right, curr_min, curr_max);
            
            /* Return the biggest one of the left or right */
            return max(left, right);
        }
        
        int maxAncestorDiff(TreeNode* root) {
            if (root == nullptr)
                return 0;
            return search(root, root->val, root->val);
        }
    };