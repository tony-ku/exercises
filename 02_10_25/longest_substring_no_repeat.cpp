/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <string>
#include <unordered_map>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;

        int max_count = 0;
        while (right < s.size()) {
            char r = s[right];
            map[r]++;

            while (map[r] > 1)
            {
                char l = s[left];
                map[l]--;
                left++;
            }
            max_count = max(max_count, right - left + 1);
            right++;
       }
       return max_count;
    }
};

int main(void)
{
    string s = "abcabcbb";
    Solution X;
    printf ("output: %d\n", X.lengthOfLongestSubstring(s));
    return 0;
}
