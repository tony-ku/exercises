#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 };

 /*
 
 Tree:

            10
        5         15
    3       7         18
 */
 TreeNode roots[6];

 void setup_tree(void)
 {
    memset(roots, 0, sizeof(roots));
    roots[0].val = 10;
    roots[0].left = &roots[1];
    roots[0].right = &roots[2];
    roots[1].val = 5;
    roots[1].left = &roots[3];
    roots[1].right = &roots[4];
    roots[2].val = 15;
    roots[2].left = nullptr;
    roots[2].right = &roots[5];
    roots[3].val = 3;
    roots[3].left = roots[3].right = nullptr;
    roots[4].val = 7;
    roots[5].val = 18;
 }

 int rangeSumBST(TreeNode* root, int low, int high) {
    stack<TreeNode *> stack;
    int val = 0;
    stack.push(root);

    while (!stack.empty())
    {
        TreeNode *node = stack.top();
        stack.pop();

        printf ("node val: %d\n", node->val);
        /* If it's within range, add the value */
        if (low <= node->val && node->val <=high) {
            printf ("within range\n");
            val += node->val;
        }

        /* Search the left side if it's not null and low is less than the node val*/
        if (node->left != nullptr && low < node->val) {
            printf ("Search left\n");
            stack.push(node->left);
        }

        if (node->right != nullptr && high > node->val) {
            printf ("Search right\n");
            stack.push(node->right);
        }
    }
    return val;
}


int main(void)
{
    setup_tree();
    printf ("Final sum: %d\n", rangeSumBST(roots, 5, 15));
    return 0;
}

