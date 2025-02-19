

/*
ou are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

YNotice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:

            4
        2       7
    1       3

    insert 5:

             4
          /   \
         2      7
       / \        \
     1     3        5


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if (root == NULL)
                return new TreeNode(val);
            
            if (val > root->val)
            {
                if (root->right != nullptr)
                    insertIntoBST(root->right, val);
                else
                    root->right = new TreeNode(val);
            }
            else
            {
                if (root->left != nullptr)
                    insertIntoBST(root->left, val);
                else
                    root->left = new TreeNode(val);
            }
            return root;
        }
    };