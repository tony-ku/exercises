/* Example 4: 392. Is Subsequence.

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a sequence of characters that can be obtained by deleting some (or none) of the characters from the original string, while maintaining the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* is  a subsequence of b */
bool is_subsequence(char *a, uint32_t size_a, char *b, uint32_t size_b)
{
    uint32_t i = 0, j = 0;

    while (i < size_a && j < size_b)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }

    /* if we exhaust size_a, then it's a subsequence of b */
    if (i == size_a)
	return true;
    else
        return false;
}

void main(void)
{
	char s1[] = "ace";
	char s2[] = "aec";
        char t1[] = "abcde";
        bool is_sub = false;

	is_sub = is_subsequence(s1, sizeof(s1) - 1, t1, sizeof(t1) - 1);
        if (is_sub)
		printf ("subsequence found\n");

	is_sub = is_subsequence(s2, sizeof(s2) -1, t1, sizeof(t1) - 1);
	if (is_sub)
		printf ("subsequence found\n");
        else
		printf ("second string subsequence not found\n");
}
       
