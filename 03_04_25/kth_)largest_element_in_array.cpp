/*
Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/

class Solution {
    public:
        /* Use min heap - push the nums in, and if it exceeds k, pop the smallest ones out,
         * at the end it would the kth largest value on top of the heap
         */
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> heap;
            for (auto num: nums)
            {
                heap.push(-num);
                if (heap.size() > k)
                    heap.pop();
            }
            
            return -heap.top();
        }
};