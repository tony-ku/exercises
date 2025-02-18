
/* Example walk through of BFS

                                   24
                                  /   \
                                 8     3
                                / \     \
                               2   1     12
                                    \
                                      5


   Each iteration should show one layer:
       24
       8, 3,
       2, 1, 12
       5
*/

#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 };

TreeNode roots[7];
void createTestTree(void)
 {
    memset(roots, 0, sizeof(roots));
    roots[0].val = 24;
    roots[0].left = &roots[1];
    roots[0].right = &roots[2];
    roots[1].val = 8;
    roots[1].left = &roots[3];
    roots[1].right = &roots[4];
    roots[2].val = 3;
    roots[2].left = nullptr;
    roots[2].right = &roots[5];
    roots[3].val = 2;
    roots[3].right = nullptr;
    roots[3].left = nullptr;
    roots[4].val = 1;
    roots[4].left = nullptr;
    roots[4].right = &roots[6];
    roots[5].val = 12;
    roots[5].left = nullptr;
    roots[5].right = nullptr;
    roots[6].val = 5;
    roots[6].left = nullptr;
    roots[6].right = nullptr;
 }

void printAllNodes(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.push(root);
    
    while (!queue.empty()) {
        int nodesInCurrentLevel = (int)queue.size();
        // do some logic here for the current level

        for (int i = 0; i < nodesInCurrentLevel; i++) {
            TreeNode* node = queue.front();
            queue.pop();

            // do some logic here on the current node
            cout << node->val << " ";
            
            // put the next level onto the queue
            if (node->left) {
                queue.push(node->left);
            }
            
            if (node->right) {
                queue.push(node->right);
            }
        }
        cout << endl;
    }
}

int main(void)
{
    createTestTree();
    printAllNodes(roots);
    return 0;
}