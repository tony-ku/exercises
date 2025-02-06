/*
 *A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

*/

bool checkIfPangram(char* sentence) {
    bool alphabet['z'-'a'+1] = {false};
    
    int count = 0, alphabet_count = 0;
    char test;
    test = sentence[count];
    while (test != 0)
    {
        /* increment counter if it's not found */
        if (alphabet[test-'a'] == false)
        {
            alphabet_count++;
            alphabet[test-'a'] = true;
        }
        test = sentence[count++];
    }
    if (alphabet_count == 26)
        return true;
    else
        return false;
}
