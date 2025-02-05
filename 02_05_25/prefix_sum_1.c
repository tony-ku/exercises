/* Example 1: Given an integer array nums, an array queries where queries[i] = [x, y] and an integer limit, return a boolean array that represents the answer to each query. A query is true if the sum of the subarray from x to y is less than limit, or false otherwise.

For example, given nums = [1, 6, 3, 2, 7, 2], queries = [[0, 3], [2, 5], [2, 4]], and limit = 13, the answer is [true, false, true]. For each query, the subarray sums are [12, 14, 12].

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
 
uint32_t query[][2] = { {0, 3}, {2, 5}, {2, 4} };

uint32_t nums[] = {1, 6, 3, 2, 7, 2};

void answer_queries(uint32_t *nums, uint32_t num_size, uint32_t queries[][2], uint32_t query_size, uint32_t limit, bool *result)
{
   uint32_t *prefix_sums = (uint32_t *)malloc(num_size * 4);

   prefix_sums[0] = nums[0];
   for (uint32_t i = 1; i < num_size; i++)
   {
	prefix_sums[i] = prefix_sums[i-1] + nums[i];
   }
   for (uint32_t i = 0; i < query_size; i++)
   {
	uint32_t left = queries[i][0];
	uint32_t right = queries[i][1];

	printf ("left: %d, right %d\n", left, right);       
	/* Sums of the query is the prefix sums of the right query minus
         * prefix sums of the left query add the number at the left query
         */ 
        uint32_t temp = prefix_sums[right] - prefix_sums[left] + nums[left];
        result[i] = temp < limit;
    }

    free(prefix_sums);
}

void main(void)
{
     bool results[3];
          answer_queries(nums, sizeof(nums) / 4,  query, sizeof(query) / (4 *2), 13, results);
     for (uint32_t i = 0; i < 3; i++)
	printf ("result: %d %d\n", i, (uint32_t)results[i]);

}
