/*
Example 2: You are given a binary string s (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". What is the length of the longest substring achievable that contains only "1"?

For example, given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.
*/

#include <stdio.h>
#include <stdint.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

char test_vec[] = "1101100111";

int substitute_one(char *s, int size)
{
   int left = 0, right = 0;
   int temp = 0;
  int len = 0;

   for (right = 0; right < size; right++)
   {
     if (s[right] == '0')
	temp++;

     /* we can only have one  '0' to be converted */
     while (temp > 1)
     {
	if (s[left] == '0')
        {
            temp--;
        }
        /* move left window over */
        left++;
     }
     len = max(len, right - left + 1);
  }

  return len;
}

void main(void)
{
    int len = substitute_one(test_vec, sizeof(test_vec) - 1);
printf ("len: %d\n", len);
}
