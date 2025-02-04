/*Example 1: Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. This is the problem we have been talking about above. We will now formally solve it.
*/

/*
Let's use an integer curr that tracks the sum of the current window. Since the problem wants subarrays whose sum is less than or equal to k, we want to maintain curr <= k. Let's look at an example where nums = [3, 1, 2, 7, 4, 2, 1, 1, 5] and k = 8.
*/
#include <stdio.h>
#include <stdint.h>

int findLength(int *nums, int size, int k)
{
   uint32_t left = 0, right = 0;

   int curr = 0;
   int window_size = 0;

   for (right = 0; right < size; right++)
   {
	curr += nums[right];
	if (curr > k)
        {
	     curr -= nums[left];
             left++;
        }
        if ((right-left+1) > window_size)
            window_size = right-left+1;   
   }

   return window_size;
}

int vals[] = {3, 1, 2, 7, 4, 2, 1, 1, 5};

void main(void)
{
   int len = findLength(vals, sizeof(vals)/sizeof(int), 8);
   printf ("len: %d\n", len);
}

