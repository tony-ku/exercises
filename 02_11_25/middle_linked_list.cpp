/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


 Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode *fast = head;
            ListNode *slow = head;
            / *
              * one node: [1]
              *          fast->next is null, return node 1, good.
              *  
              *[1,2,3,4,5]
              *  slow to 2, fast to 3,
              *  slow to 3, fast to 5,
              *  loop exits as fast->next is now null
              * 
              * [1,2,3,4,5,6]
              *  slow to 2, fast to 3
              *  slow to 3, fast to 5
              *  slow to 4, fast to 7 (null), looop finishes
              * /
            while (fast != nullptr && (fast->next != nullptr))
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }
    };