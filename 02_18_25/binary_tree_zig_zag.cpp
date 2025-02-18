
/* 

Binary Tree Zigzag Level Order Traversal


Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

        3
      9   20
         15  7
  

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            queue<TreeNode *> queue;
            queue.push(root);
            vector<vector<int>> result;
            bool order = true;
            
            if (root == nullptr)
                return result;
            
            while (!queue.empty())
            {
                vector<int>temp;
                int queue_size = queue.size();
                while (queue_size--)
                {
                    TreeNode *node = queue.front();
                    queue.pop();
                    temp.push_back(node->val);
                    //printf ("val: %d\n", node->val);
    
                    if (node->left)
                        queue.push(node->left);
                    if (node->right)
                        queue.push(node->right);
    
                }
                if (order)
                {
                    order = false;
                }
                else
                {
                    /* reverse order before store */
                    reverse(temp.begin(), temp.end());
                    order = true;
                }
                result.push_back(temp);
                
            }
            return result;
        }
    };