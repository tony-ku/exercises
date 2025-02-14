/* Make The String Great

Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
*/

class Solution {
    public:
        string makeGood(string s) {
            /* Walk through the string, use a stack to push it on to the stack.   As it traverses, it will pop it out of the stack if it sees lower/upper.
             *  This covers cases like s = "abBAcC";  a inserted, b inserted, B checked, popped b out, string is now "a", A checked, 'a" popped out, string is now
             *   null.   c pushed in the stack, C checked and popped out.  return null.
             *  
            */
            vector<char> stack;
            for (char c: s)
            {
                if (!stack.empty() && (abs(stack.back() - c) == 32))
                    stack.pop_back();
                else
                    stack.push_back(c);
            }
            
            string ans(stack.begin(), stack.end());
            return ans;
        }
    };