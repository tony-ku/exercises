
/*
Find the Smallest Divisor Given a Threshold

Solution
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106
*/
class Solution {
    public:
        
        int find_div_sum(vector<int>& nums, int divisor) {
            int result = 0;
            for (int num : nums) {
                result += ceil((1.0 * num) / divisor);
            }
            return result;
        }
        
        int smallestDivisor(vector<int>& nums, int threshold) {
            
            // integer divisor starts at as lowest
            int low = 1;
            
            // the high is the highest element, as anything higher than that will not 
            // change the result (i.e. it's a celing)
            int high = *max_element(nums.begin(), nums.end());
            int ans = 0;
            
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int result = find_div_sum(nums, mid);
                
                if (result <= threshold) {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return ans;
        }
    };