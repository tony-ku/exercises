/*
 * Example 2: Given a sorted array of unique integers and a target integer, return true if there exists a pair of numbers that sum to target, false otherwise. This problem is similar to Two Sum. (In Two Sum, the input is not sorted).

For example, given nums = [1, 2, 4, 6, 8, 9, 14, 15] and target = 13, return true because 4 + 9 = 13.

Note: a similar version of this problem can be found on LeetCode: 167. Two Sum II - Input Array Is Sorte
*/

#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

bool find_target_sorted_array(uint32_t *nums, uint32_t size, uint32_t target)
{
	uint32_t left = 0, right = size - 1;
        uint32_t val;

       if (size == 0)
        	return false;

	while (left < right)
	{
		val = nums[left] + nums[right];
		if (val == target)
			return true;
	        if (val > target)
			right--;
		else if (val < target)
			left++;
	
	}
	return false;
}
	
uint32_t test_vec[] = {1, 2, 4,6, 8, 9, 14, 15};
void main(void)
{
	uint32_t size = sizeof(test_vec) / sizeof(uint32_t);
	if (find_target_sorted_array(test_vec, size, 13))
		printf ("found target\n");
	else
		printf ("ERR did not find target\n");

}

