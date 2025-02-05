/*
Given an integer array nums, find the number of ways to split the array into two parts so that the first section has a sum greater than or equal to the sum of the second section. The second section should have at least one number.
*/

/* 
 *  example - array of 10, 4, -8, 7.  Prefix sum would be 10, 14, 6, 13.  First split would be index 0, and index 1-3 together.   10 would be the sum on the left split, and 13-10 would be the right split */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int ways_to_split_array(int32_t *nums, int num_size)
{
   int i;
   int num_ways = 0;
   int left, right;
   int last_pos = num_size - 1;
 
   int32_t *prefix_nums = (int32_t *)malloc(4 * num_size);
   
   prefix_nums[0] = nums[0];
   for (i = 1; i < num_size; i++)
      prefix_nums[i] = prefix_nums[i-1] + nums[i];

   for (i = 0; i < num_size - 1; i++)
   {
        uint32_t left = prefix_nums[i];
        uint32_t right = prefix_nums[last_pos] - prefix_nums[i];

	printf ("left: %d, right %d\n", left, right);  
	if (left >= right)
		num_ways++;
   }

   free (prefix_nums);
   return num_ways;
}

void main(void)
{
    int nums[] = {10, 4, -8, 7};
    int num_ways = ways_to_split_array(nums, sizeof(nums) / sizeof(int));
    printf ("number of ways: %d\n", num_ways);
} 
